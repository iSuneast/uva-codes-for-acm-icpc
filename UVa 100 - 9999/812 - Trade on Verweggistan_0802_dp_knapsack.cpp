/*
812 - Trade on Verweggistan

dp...
knapsack...
ACM-ICPC World Finals (1990-2000)...
十几年前的final题,现在拿出来,竟然是被秒的命运...

易知,要得到最高利润,每堆的利润必须最高
堆之间是独立的,所以对每堆都一次扫描找到利润最高的...
然后将这些值背包即可
*/

#include<iostream>
#define MAXN 1010
using namespace std;

int w,b,p,s[25];
bool dp[54][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&w)!=EOF && w)
	{
		if(cas!=1)
			putchar(10);

		memset(dp,0,sizeof(dp));
		dp[0][0]=true;

		int profit=0;
		for(int k=1;k<=w;++k)
		{
			scanf("%d",&b);
			int m=0;	s[0]=0;
			for(int i=1;i<=b;++i)
			{
				scanf("%d",&p);
				s[i]=s[i-1]+10-p;
				m=max(m,s[i]);
			}
			profit+=m;

			for(int i=0;i<=b;++i)
				if(s[i]==m)
					for(int j=i;j<MAXN;++j)
						if(dp[k-1][j-i])
							dp[k][j]=true;
		}

		printf("Workyards %d\n",cas++);
		printf("Maximum profit is %d.\n",profit);
		printf("Number of pruls to buy:");
		int cnt=10;
		for(int i=0;i<MAXN && cnt;++i)
			if(dp[w][i])
				printf(" %d",i),--cnt;
		putchar(10);
	}

	return 0;
}
