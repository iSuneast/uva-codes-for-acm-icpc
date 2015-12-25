/*
 * 10733 - The Colored Cubes
 * 
 * brute force...
 * in fact, I don't know how to solve this problem...
 * so I just try a brute force method to calculate all the valid painted number
 *       with color = 1,2,3,4,5,6
 * since there are only 6!=720 permutation and 4*6=24 rotate
 * it won't spend a lot of time
 * 
 * finally, just a simple combination math method
 * SUM( C(n,i) * valid(i) )  1<=i<=6 && i<=n
 * 
 * so a fun problem
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 6
#define TOT 720
using namespace std;

const int cube[24][6]={
		{1,2,3,5,4,6},
		{1,3,5,4,2,6},
		{1,5,4,2,3,6},
		{1,4,2,3,5,6},
		
		{2,6,3,1,4,5},
		{2,3,1,4,6,5},
		{2,1,4,6,3,5},
		{2,4,6,3,1,5},
		
		{3,6,5,1,2,4},
		{3,5,1,2,6,4},
		{3,1,2,6,5,4},
		{3,2,6,5,1,4},
		
		{4,6,2,1,5,3},
		{4,2,1,5,6,3},
		{4,1,5,6,2,3},
		{4,5,6,2,1,3},
		
		{5,6,4,1,3,2},
		{5,4,1,3,6,2},
		{5,1,3,6,4,2},
		{5,3,6,4,1,2},
		
		{6,2,4,5,3,1},
		{6,4,5,3,2,1},
		{6,5,3,2,4,1},
		{6,3,2,4,5,1}
};

bool flag[MAXN];
int per[TOT][MAXN],key[MAXN],tot;
int cur[TOT][MAXN];

void dfs(int dep)
{
	if(dep==MAXN)
		memcpy(per[tot++],key,sizeof(int)*MAXN);
	else for(int i=0;i<MAXN;++i)
		if(!flag[i])
		{
			flag[i]=true;
			key[dep]=i+1;
			dfs(dep+1);
			flag[i]=false;
		}
}

bool same(int *a,int *b)
{
	int t[MAXN],tb[MAXN];
	for(int j=0;j<6;++j)
	{
		tb[ cube[0][j]-1 ]=b[j];
	}
	
	for(int i=0;i<24;++i)
	{
		for(int j=0;j<6;++j)
		{
			t[ cube[i][j]-1 ]=a[j];
		}

		if(memcmp(t,tb,sizeof(int)*6)==0)
			return true;
	}
	return false;
}

int chk(int *color)
{
	int newC[MAXN],sz=0;

	for(int k=0;k<tot;++k)
	{
		for(int j=0;j<MAXN;++j)
			newC[ per[k][j]-1 ]=color[j];
		
		bool fade=false;
		for(int j=0;j<sz;++j)
		{
			if(same(newC,cur[j]))
			{
				fade=true;
				break;
			}
		}
		
		if(!fade)
			memcpy(cur[sz++],newC,sizeof(int)*MAXN);
	}
	
	return sz;
}

int cnt,tmp[MAXN],depth;
void color(int dep,int s)
{
	if(dep==depth)
	{
		if(s==MAXN)
			cnt+=chk(tmp);
		return ;
	}
	for(int j=1;s+j<=MAXN;++j)
	{
		tmp[s+j-1]=dep+1;
		color(dep+1,s+j);
	}
}

long long C(int n,int k)
{
	long long key=1;
	for(int d=0;d<k;++d)
		key*=(n-d);
	for(int i=2;i<=k;++i)
		key/=i;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    tot=0;
    dfs(0);
    long long dp[MAXN+1]={};
    for(int i=1;i<=MAXN;++i)
    {
    	cnt=0;
    	depth=i;
    	color(0,0);
    	dp[i]=cnt;
    }
    
    for(int n; scanf("%d",&n)!=EOF && n;)
    {
    	int b=min(MAXN,n);
    	long long key=0;
    	for(int select=1; select<=b; ++select)
    	{
    		key+=dp[select]*C(n,select);
    	}
    	
    	printf("%lld\n",key);
    }

    return 0;
}

