/*
 * 10306 - e-Coins
 *
 * DP...
 * knapsack...
 * 二维完全背包~
 * 没啥好说的...
 *
 * happy coding~
 */

#include<cstdio>
#include<algorithm>
#define MAXN 303
using namespace std;
const int INF=0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int sqr[MAXN];
	for(int i=0;i<MAXN;++i)
	{
		sqr[i]=i*i;
	}

	int dataset, dp[MAXN][MAXN], a, b, m, s;

	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&m,&s);
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;

		for(int i=0;i<m;++i)
		{
			scanf("%d%d", &a, &b);
			for(int x=a;x<=s;++x)
				for(int y=b;y<=s;++y)
					dp[x][y]=min(dp[x][y], dp[x-a][y-b]+1);
		}

		int key=INF;
		for(int x=0;x<=s;++x)
		{
			int p=lower_bound(sqr, sqr+MAXN, sqr[s]-sqr[x])-sqr;
			if(sqr[p]+sqr[x]==sqr[s])
				key=min(key, dp[x][p]);
		}

		if(key==INF)
			puts("not possible");
		else
			printf("%d\n",key);
	}

	return 0;
}
