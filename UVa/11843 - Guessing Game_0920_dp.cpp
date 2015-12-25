/*
11843 - Guessing Game

dp...
*
* a strike, if Bob's number is greater than X
* a smile, if Bob's number is less than X
* a stop, if Bob's number is precisely X
*
so the answer of (n,m) is
min( max( (i,m),(n-1-i,m-1) ) )   1<=i<n-1
*/

#include<iostream>
#define MAXN 1001
using namespace std;
const int INF=0x3f3f3f3f;

int dp[MAXN][21];

int DP(int n,int m)
{
	if(dp[n][m]!=INF)
		return dp[n][m];
	if(!m)
		return dp[n][m]=n;
	if(n==1)
		return dp[n][m]=1;

	dp[n][m]=min(dp[n][m],DP(n-1,m)+1);
	for(int i=1;i<n-1;++i)
	{
		int t=max( DP(i,m),DP(n-1-i,m-1) );
		dp[n][m]=min(dp[n][m],t+1);
	}
	return dp[n][m];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(dp,0x3f,sizeof(dp));
	int n,m,dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",DP(n,m-1));
	}

	return 0;
}
