/*
 * 11181 - Probability|Given
 * 
 * brute force...
 * since there are C(n,r) permutation
 * we can just generate out all these permutation and calculate their probability
 * 
 * happy coding...
 */

#include<cstdio>
#define MAXN 23
using namespace std;

double ppl[MAXN],s,p[MAXN];
bool flag[MAXN];
int n,r;

void modify()
{
	double t=1;
	for(int i=0;i<n;++i)
	{
		if(flag[i])
			t*=p[i];
		else
			t*=(1-p[i]);
	}
	s+=t;
	for(int i=0;i<n;++i)
	{
		if(flag[i])
			ppl[i]+=t;
	}
}

void dfs(int p,int dep)
{
	if(n-p+dep<r)
		return ;
	if(dep==r)
		return modify();
	for(int i=p;i<n;++i)
		if(!flag[i])
		{
			flag[i]=true;
			dfs(i+1,dep+1);
			flag[i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    for(int cas=1; scanf("%d%d",&n,&r)!=EOF && (n||r); ++cas)
    {
    	for(int i=0;i<n;++i)
    	{
    		ppl[i]=0;
    		flag[i]=false;
    		scanf("%lf",&p[i]);
    	}
    	s=0;
    	dfs(0,0);
    	
    	printf("Case %d:\n",cas);
    	for(int i=0;i<n;++i)
    	{
    		printf("%.6lf\n",ppl[i]/s);
    	}
    }

    return 0;
}

