/*
11742 - Social Constraints

brute force...
暴力枚举全排列...
逐个验证即可
*/

#include<iostream>
#define MAXN 25
#define fabs(a) ((a)<0?-(a):a)
using namespace std;

int n,m,cons[MAXN][3],state[10],key;
bool flag[10];

void chk()
{
	for(int i=0;i<m;++i)
	{
		int p1,p2;
		for(p1=0;p1<n;++p1)
			if(state[p1]==cons[i][0])
				break;
		for(p2=0;p2<n;++p2)
			if(state[p2]==cons[i][1])
				break;
		if(cons[i][2]>0)
		{
			if(fabs(p1-p2)>cons[i][2])
				return ;
		}
		else
		{
			if(fabs(p1-p2)<-cons[i][2])
				return ;
		}
	}
	++key;
}

void dfs(int dep)
{
	if(dep==n)
		chk();
	else for(int i=0;i<n;++i)
		if(!flag[i])
		{
			flag[i]=true;
			state[dep]=i;
			dfs(dep+1);
			flag[i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&cons[i][0],&cons[i][1],&cons[i][2]);
		key=0;
		dfs(0);
		printf("%d\n",key);
	}

	return 0;
}
