/*
590 - Always on the run

DP...
貌似非常复杂非常long的题目...
差点就跳过不做了...

其实题目的意思还是很简单的...
days天n_city个城市...
从a->b要么有航班要么没有...
也就是说...
我们只要从第0天开始...
依次枚举每天的情况即可...
用数组dp[i][j]代表地i天在第j个城市的花费...
则状态转移为dp[i][j]=min(dp[i-1][k]+flight[k][j][cur])
容易理解...
第i-1天在第k个城市.然后从k出发到达j.取最小即可
*/

#include<iostream>
#define PERIOD 35
#define CITY 13
#define DAY 1010
#define INF 0x7f7f7f7f
using namespace std;

int flight[CITY][CITY][PERIOD];
int dp[DAY][CITY],n_city,days;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d%d",&n_city,&days)!=EOF && (n_city||days))
	{
		memset(flight,0,sizeof(flight));
		for(int i=1;i<=n_city;++i)
			for(int j=1;j<=n_city;++j)
				if(i!=j)
				{
					scanf("%d",&flight[i][j][0]);
					for(int k=1;k<=flight[i][j][0];++k)
						scanf("%d",&flight[i][j][k]);
				}
		memset(dp,0x7f,sizeof(dp));
		dp[0][1]=0;
		for(int i=1;i<=days;++i)
			for(int j=1;j<=n_city;++j)
				for(int k=1;k<=n_city;++k)
				{
					if(k==j)
						continue;
					int cur=i%flight[k][j][0];
					if(!cur)
						cur=flight[k][j][0];
					if(!flight[k][j][cur])
						continue;
					dp[i][j]=min(dp[i][j],dp[i-1][k]+flight[k][j][cur]);
				}
		printf("Scenario #%d\n",cas++);
		if(dp[days][n_city]==INF)
			puts("No flight possible.");
		else
			printf("The best flight costs %d.\n",dp[days][n_city]);
		putchar('\n');
	}

	return 0;
}
