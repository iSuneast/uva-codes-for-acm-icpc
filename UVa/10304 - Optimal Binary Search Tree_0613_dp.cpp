/*
10304 - Optimal Binary Search Tree

dp...
”Îæÿ’Û¡¥≥À¿‡À∆...
*/

#include<iostream>
#define MAXN 256
#define INF 0x7f7f7f7f
using namespace std;

int dp[MAXN][MAXN];
int sum[MAXN][MAXN];
int f[MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	
	while(scanf("%d",&n)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		memset(dp,0x7f,sizeof(dp));
		int s=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",f+i);
			s+=f[i];
			sum[0][i]=s;
			for(int j=1;j<=i;++j)
				sum[j][i]=sum[j-1][i]-f[j-1];
			dp[i][i]=0;
		}
		
		for(int k=1;k<n;++k)
			for(int start=0;start<n-k;++start)
			{
				int end=start+k;
				dp[start][end]=min(dp[start][end],dp[start+1][end]+sum[start][end]-f[start]);
				dp[start][end]=min(dp[start][end],dp[start][end-1]+sum[start][end]-f[end]);
				for(int i=start+1;i<=end-1;++i)
					dp[start][end]=min(dp[start][end],dp[start][i-1]+dp[i+1][end]+sum[start][end]-f[i]);
			}

		printf("%d\n",dp[0][n-1]);
	}
	
	return 0;
}
