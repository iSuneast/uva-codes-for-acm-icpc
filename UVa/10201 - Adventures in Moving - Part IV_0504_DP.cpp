/*
10201 - Adventures in Moving - Part IV

DP...
不要怕...
做到这种题一定要保持冷静的头脑...
其实状态转移也就那么回事...
认真一点都可以想出来的...

令dp[p][j]为第p个站点剩余油量j的费用则
在第i(0<=i<p)个站点的剩余油量应至少为j-(dis[p]-dis[i])
其中dis[p]-dis[i]<=200
得到dp[p][j]后,根据当前加油站的费用更新dp[p][k](k>=j)
dp[p][k]=min(dp[p][k],dp[p][j]+cost[p]*(k-j))
注意,在到达终点的时候不能更新.所以必须特判.
*/

#include<iostream>
#define GAS 200
#define MAXN 110
#define INF 0x7f7f7f7f
using namespace std;

int dp[MAXN][GAS+10],dis[MAXN],cost[MAXN],end;
char buf[MAXN];

void process(int p,bool fresh)
{
	int oil;
	for(int i=p-1;i>=0;--i)
	{
		if((oil=dis[p]-dis[i])<=GAS)
			for(int j=0;j<=GAS;++j)
			{
				for(int k=j+oil;k<=GAS;++k)
					if(dp[i][k]!=INF)
						dp[p][j]=min(dp[p][j],dp[i][k]);
				if(fresh && dp[p][j]!=INF)
					for(int k=j;k<=GAS;++k)
						dp[p][k]=min(dp[p][k],dp[p][j]+cost[p]*(k-j));
			}
		else
			break;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&end);
		gets(buf);
		memset(dp,0x7f,sizeof(dp));
		dp[0][100]=0;
		int p=0;
		dis[0]=cost[0]=0;
		while(gets(buf) && strcmp(buf,""))
		{
			++p;
			sscanf(buf,"%d%d",&dis[p],&cost[p]);
			process(p,true);
		}
		++p;
		dis[p]=end;	cost[p]=0;
		process(p,false);
		bool found=false;
		for(int i=GAS/2;i<=GAS;++i)
			if(dp[p][i]!=INF)
			{
				printf("%d\n",dp[p][i]);
				found=true;
				break;
			}
		if(!found)
			puts("Impossible");
		if(dataset)
			putchar('\n');
	}

	return 0;
}
