/*
10943 - How do you add?

DP...
dp[][]保存数字n拆成k段的种数
易知
	dp[0][]=1
	dp[][1]=1
	dp[1][i]=i
对其他的任何元素
	dp[n][k]+=dp[i][k-1]
	其中i<-[0,n]
	表示元素n拆成k段可以通过i+(n-i)拆成k-1段得到
	递推即可得解...
*/

#include<iostream>
#define MAXN 100
#define MOD 1000000
using namespace std;

int dp[MAXN+3][MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(dp,0,sizeof(dp));
	for(int i=0;i<=MAXN;++i)
	{
		dp[0][i]=1;
		dp[i][1]=1;
		dp[1][i]=i;
	}
	for(int n=2;n<=MAXN;++n)
		for(int k=2;k<=MAXN;++k)
			for(int i=0;i<=n;++i)
				dp[n][k]=(dp[n][k]+dp[i][k-1])%MOD;

	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF && (n||k))
		printf("%d\n",dp[n][k]);

	return 0;
}
