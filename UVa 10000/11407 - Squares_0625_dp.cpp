/*
11407 - Squares

dp..
明显的递推关系..
dp[i]=min(dp[i],dp[i-j*j]+1);
*/

#include<iostream>
#define MAXN 10001
using namespace std;

int dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<MAXN;++i)
		for(int j=1;j*j<=i;++j)
		{
			int t=i-j*j;
			dp[i]=min(dp[i],dp[t]+1);
		}

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}

	return 0;
}
