/*
882 - The Mailbox Manufacturers Problem

DP...
显然是有规律的...
直接打表输出即可...
*/

#include<iostream>
#define MAXN 100
#define BOXN 10
#define INF 0x7f7f7f7f
using namespace std;

int dp[BOXN+3][MAXN+10][MAXN+10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	for(int start=1;start<=MAXN;++start)		//只有一个箱子...dp[][][]=sum(start,end)
		for(int end=start;end<=MAXN;++end)
			dp[1][start][end]=(start+end)*(end-start+1)/2;
	for(int box=2;box<=BOXN;++box)		//邮箱的个数
	{
		for(int fire=0;fire<=MAXN;++fire)	//可用的鞭炮数
		{
			int end=MAXN-fire;
			for(int start=1;start<=end;++start)		//至少鞭炮数
			{
				if(fire==0)
					dp[box][start][start]=start;
				else
				{
					dp[box][start][start+fire]=INF;
					for(int cur=start;cur<=start+fire;++cur)
						dp[box][start][start+fire]=min(dp[box][start][start+fire],
							cur+max(dp[box-1][start][cur-1],dp[box][cur+1][start+fire]));
				}
			}
		}
	}

	int dataset,k,m;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&k,&m);
		printf("%d\n",dp[k][1][m]);
	}

	return 0;
}
