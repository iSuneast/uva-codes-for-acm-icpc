/*
11133 - Eigensequence

dp..
math...
for a[i]<a[j] we define d=a[j]-a[i]
	a[j]%d==0 -> a[j]=k*d ->
	a[i]=a[j]-d=(k-1)*d -> a[i]%d==0

for section [s,e]
1) if e%(e-s)==0 dp[s][e]=1, else dp[s][e]=0
2) [s,e] can be divide into two section [s,s+p] && [s+p,e]
	if(s%p==0 && s+p<e)
	finally, we got
		dp[s][e]=sum(dp[s+p][e])
*/

#include<iostream>
#define MAXN 45
using namespace std;

int dp[MAXN][MAXN];

int DP(int s,int e)
{
	if(dp[s][e]!=-1)
		return dp[s][e];
	if(s+1==e)
		return dp[s][e]=1;

	dp[s][e]=(e%(e-s)==0?1:0);

	for(int p=1;s+p<e;++p)
		if(s%p==0)
			dp[s][e]+=DP(s+p,e);

	return dp[s][e];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	int s,e;
	while(scanf("%d%d",&s,&e)!=EOF && (s||e))
	{
		printf("%d %d %d\n",s,e,DP(s,e));
	}

	return 0;
}
