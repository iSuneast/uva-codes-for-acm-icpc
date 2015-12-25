/*
11863 - Prime Game

DP...
it's a classical model
use dp[l][r]=1 to store the win stage
if and only if
1. ok([l][k]) && dp[k+1][r]=-1
2. ok([k+1][r]) && dp[l][k]=-1
use memorize search to handle it.

be careful about "k", it's of no use. :)
and if "42" exist, the answer is alway yes.
*/

#include<iostream>
#define MAXN 103
#define SZ 100001
using namespace std;

int n,k,var[MAXN],sum[MAXN],dp[MAXN][MAXN];
bool ok[MAXN][MAXN],flag[SZ];

void init()
{
	memset(flag,0,sizeof(flag));
	flag[0]=flag[1]=true;
	for(int i=2;i<SZ;++i)
	{
		if(flag[i])
			continue;
		for(int j=i+i;j<SZ;j+=i)
			flag[j]=true;
	}
}

int DP(int l,int r)
{
	if(dp[l][r])
		return dp[l][r];
	if(ok[l][r])
		return dp[l][r]=1;
	dp[l][r]=-1;
	for(int k=l;k<r;++k)
	{
		if(ok[l][k])
			dp[l][r]=max(dp[l][r],-DP(k+1,r));
		if(ok[k+1][r])
			dp[l][r]=max(dp[l][r],-DP(l,k));

		if(dp[l][r]==1)
			break;
	}

	return dp[l][r];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	init();
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d",&n,&k);
		memset(ok,0,sizeof(ok));
		bool has42=false;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
			if(has42)
				continue;

			sum[i]=var[i];
			if(i)
				sum[i]+=sum[i-1];

			if(var[i]==42)
				has42=true;

			for(int j=0;j<=i;++j)
			{
				int s=sum[i];
				if(j)
					s-=sum[j-1];
				ok[j][i]=(s>0 && !flag[s]);
			}
		}

		if(has42)
			printf("Case %d: Soha\n",cas);
		else
		{
			memset(dp,0,sizeof(dp));
			printf("Case %d: %s\n",cas,(DP(0,n-1)==1)?"Soha":"Tara");
		}
	}

	return 0;
}
