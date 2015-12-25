/*
10074 - Take the Land

DP...
求矩阵里面的最大的立方体...
O(n^4)的竟然能过...
*/

#include<iostream>
#define MAXN 110
using namespace std;

int dp[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		memset(dp,0,sizeof(dp));
		int key=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%d",&dp[i][j]);
				dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
				for(int a=0;a<=i;++a)
					for(int b=0;b<=j;++b)
					{
						int t=dp[i][j]-dp[i][b]-dp[a][j]+dp[a][b];
						if(!t)
						{
							t=(i-a)*(j-b);
							key=max(t,key);
						}
					}
			}
		printf("%d\n",key);
	}

	return 0;
}
