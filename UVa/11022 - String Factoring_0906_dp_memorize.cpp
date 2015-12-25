/*
11022 - String Factoring

dp...
use memorize to solve it
dp[s][e]=min(dp[s][t]+dp[t][e])
		=min(e-s-string_overlap_from_s+dp[s][sofs])
*/

#include<iostream>
#define MAXN 86
using namespace std;
const int INF=0x3f3f3f3f;

int dp[MAXN][MAXN];
char str[MAXN];

int jump(int s,int l,int e)
{
	int k=(e-s)/l;
	for(int i=1;i<k;++i)
	{
		int st=s+i*l;
		for(int j=0;j<l;++j)
			if(str[s+j]!=str[st+j])
				return i-1;
	}
	return k-1;
}

int DP(int s,int e)
{
	if(s+1==e)
		return 1;
	if(dp[s][e]!=INF)
		return dp[s][e];
	dp[s][e]=e-s;

	for(int l=1;s+l<=e;++l)
	{
		int t=jump(s,l,e);
		if(t)
			dp[s][e]=min(dp[s][e],e-s-(t+1)*l+DP(s,s+l));
	}

	for(int t=s+1;t<e;++t)
		dp[s][e]=min(DP(s,t)+DP(t,e),dp[s][e]);

	return dp[s][e];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%s",str)!=EOF && str[0]!='*')
	{
		memset(dp,0x3f,sizeof(dp));
		printf("%d\n",DP(0,strlen(str)));
	}

	return 0;
}
