/*
10891 - Game of Sum

dp...
game theory...
This problem can be solved using dynamic programming.
Let best(i, j) be the best difference the current player can get,
given the starting position (i) and the ending position (j).
Let sum(i, j) be the sum a[i]+...+a[j].
The dynamic programming formula is 
best(i, j) = max(max(sum(i,i+k)-best(i+k,j),sum(j-k,j)-best(i,j-k)))
	for k = 0,...,j-i.

be care of the initiate method, the value should be -INF
*/

#include<iostream>
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;

int var[MAXN],sum[MAXN],n,dp[MAXN][MAXN];

int DP(int s,int e)
{
	if(dp[s][e]!=INF)
		return dp[s][e];
	if(s==e)
		return dp[s][e]=var[s];
	else if(s>e)
		return dp[s][e]=0;
	else
	{
		dp[s][e]=-INF;
		for(int i=s;i<=e;++i)
		{
			int t=sum[i]-sum[s-1];
			dp[s][e]=max(dp[s][e],t-DP(i+1,e));

			t=sum[e]-sum[i-1];
			dp[s][e]=max(dp[s][e],t-DP(s,i-1));
		}

		return dp[s][e];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		sum[0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&var[i]);
			sum[i]=sum[i-1]+var[i];
		}

		memset(dp,0x3f,sizeof(dp));
		printf("%d\n", DP(1,n) );
	}

	return 0;
}
