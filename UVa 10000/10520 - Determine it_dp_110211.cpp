/*
 * 10520 - Determine it
 *
 * dp...
 * 记忆化搜索~
 * 照着题目的公式敲就可以了~
 *
 * 记得用long long，不然的话会溢出的。。。
 *
 * happy coding~
 */

#include<iostream>
using namespace std;
typedef long long LL;

LL dp[21][21], n;

LL dfs(int i,int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];

	if(i>=j)
	{
		LL x=0, y=0;
		if(i!=n)
		{
			for(int k=i+1; k<=n; ++k)
				x=max(x, dfs(k,1)+dfs(k,j));
		}
		if(j>0)
		{
			for(int k=1;k<j;++k)
				y=max(y, dfs(i,k)+dfs(n,k));
		}
		dp[i][j]=x+y;
	}
	else
	{
		for(int k=i; k<j; ++k)
		{
			dp[i][j]=max(dp[i][j], dfs(i,k)+dfs(k+1,j));
		}
	}

	return dp[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(true)
	{
		memset(dp,-1,sizeof(dp));
		if(scanf("%lld", &n)==EOF)
			break;
		scanf("%lld", &dp[n][1]);
		printf("%lld\n", dfs(1,n));
	}

	return 0;
}
