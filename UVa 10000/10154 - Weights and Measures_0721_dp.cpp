/*
10154 - Weights and Measures

dp..
bbs里面介绍的lis和greedy在rejudge后都是错的

按差值(w-s)排序
然后背包即可
dp[i][j]=min(dp[i][j],dp[i-1][j]);
if(dp[i-1][j-1]+data[i].w<=data[i].s)
	dp[i][j]=min(dp[i][j],dp[i-1][j-1]+data[i].w);
*/

#include<iostream>
#include<algorithm>
#define MAXN 5610
#define INF 0x3f3f3f3f
using namespace std;

struct TURTLE
{
	int w,s;
	bool operator<(const TURTLE &t)const
	{
		return s-w<t.s-t.w;
	}
}data[MAXN];
int dp[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n=1;
	while(scanf("%d%d",&data[n].w,&data[n].s)!=EOF)
		++n;
	sort(data+1,data+n+1);

	int key=0;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<=n;++i)
		dp[i][0]=0;

	for(int i=1;i<n;++i)
		for(int j=1;j<i;++j)
		{
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if(dp[i-1][j-1]+data[i].w<=data[i].s)
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+data[i].w);
		}

	for(int i=1;i<n;++i)
		if(dp[n-1][i]!=INF)
			key=max(i,key);

	printf("%d\n",key);

	return 0;
}
