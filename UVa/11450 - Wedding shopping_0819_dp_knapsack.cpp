/*
11450 - Wedding shopping

dp...
knapsack...
对每个物品进行背包
if(dp[c-1][money-price]) 更新dp[c][money]
*/

#include<iostream>
#define MONEY 203
#define C 23
using namespace std;

bool dp[C][MONEY];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,m,c,k,p;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&m,&c);
		memset(dp,0,sizeof(dp));
		dp[0][0]=true;
		for(int i=1;i<=c;++i)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&p);
				for(int j=0;j+p<=m;++j)
					if(dp[i-1][j])
						dp[i][j+p]=true;
			}
		}
		int key=-1;
		for(int j=m;j>=0 && key==-1;--j)
			if(dp[c][j])
				key=j;

		if(key==-1)
			puts("no solution");
		else
			printf("%d\n",key);
	}

	return 0;
}
