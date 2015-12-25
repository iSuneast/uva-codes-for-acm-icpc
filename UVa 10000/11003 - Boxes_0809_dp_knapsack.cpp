/*
11003 - Boxes

dp...
knapsack...
由于东西要从下往上堆叠...
所以读入数据的时候直接从后往前读,就可以把倒推变成正推了...

dp[i][j]表示第i个物品堆j个物品时,j个物品的最小重量
则dp[i][j]=min(*,dp[i-1][j])
	第i个物品至少可以承受第i-1个物品可以承受的重量
dp[i-1][j-1]<=dp[i].load --- (前[i-1][j-1]物品的重量没有超过第i个物品的承重)
	dp[i][j]=min(*,dp[i-1][j-1]+data[i].w)

最后dp[n][i]如果有被处理过的值,则最大的i就是的答案了...
*/

#include<iostream>
#define MAXN 1003
#define INF 0x3f3f3f3f
using namespace std;

struct TURTLE
{
	int w,load;
}data[MAXN];
int dp[MAXN][MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=n;i;--i)
			scanf("%d%d",&data[i].w,&data[i].load);

		int key=0;
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<=n;++i)
			dp[i][0]=0;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=i;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
				if(dp[i-1][j-1]<=data[i].load)
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]+data[i].w);
			}

		for(int i=1;i<=n;++i)
			if(dp[n][i]!=INF)
				key=i;

		printf("%d\n",key);
	}
	return 0;
}
