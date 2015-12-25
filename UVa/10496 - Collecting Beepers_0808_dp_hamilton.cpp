/*
10496 - Collecting Beepers

dp...
hamilton
哈密顿回路...
先求出图的任意两个宝藏的距离
然后求一次哈密顿回路即可...
*/

#include<iostream>
#define MAXN 13
#define INF 0x3f3f3f3f
using namespace std;

struct POINT
{
	int x,y;
}pnt[MAXN],sz;

int n,g[MAXN][MAXN];

void input()
{
	scanf("%d%d",&sz.x,&sz.y);
	scanf("%d%d",&pnt[0].x,&pnt[0].y);
	scanf("%d",&n);
	g[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		g[i][i]=0;
		scanf("%d%d",&pnt[i].x,&pnt[i].y);
		for(int j=0;j<i;++j)
			g[i][j]=g[j][i]=abs(pnt[i].x-pnt[j].x)+abs(pnt[i].y-pnt[j].y);
	}
}

int dp[MAXN][1<<MAXN];

int DP(int n)
{
#define INSIDE(a,b) ((a)&(1<<(b)))
#define MERGE(a,b) (a+(1<<(b)))

	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;++i)
		dp[i][1<<i]=g[0][i];

	for(int i=1;i<(1<<n);++i)
		for(int j=0;j<n;++j)
			if(INSIDE(i,j))
				for(int k=0;k<n;++k)
					if(!INSIDE(i,k))
						dp[k][MERGE(i,k)]
					=min(dp[k][MERGE(i,k)],dp[j][i]+g[j][k]);

					return dp[0][(1<<n)-1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		input();
		printf("The shortest path has length %d\n",DP(n+1));
	}

	return 0;
}
