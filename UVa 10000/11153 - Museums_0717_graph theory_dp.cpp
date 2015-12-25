/*
11153 - Museums

graph theory...
dp...
求哈密顿回路...
状态DP....
O(2^n*n^2)的复杂度
状态转移方程
dp[k][MERGE(i,k)]=min(dp[k][MERGE(i,k)],dp[j][i]+g[j][k]);
*/

#include<iostream>
#define MAXN 15
#define INF 0x3f3f3f3f
using namespace std;

int g[MAXN][MAXN],fee[MAXN],fun[MAXN];
int dp[MAXN][1<<MAXN];
int d,t,n,m;

int DP()
{
#define INSIDE(i,j) ((i)&(1<<(j)))
#define MERGE(i,j) (i+(1<<(j)))

	n++;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;++i)
		dp[i][1<<i]=g[0][i];

	for(int i=1;i<(1<<n);++i)
		for(int j=0;j<n;++j)
			if(INSIDE(i,j))
				for(int k=0;k<n;++k)
					if(!INSIDE(i,k))
						dp[k][MERGE(i,k)]=
						min(dp[k][MERGE(i,k)],dp[j][i]+g[j][k]);

	int tot_fun=-1;
	for(int i=1;i<(1<<n);++i)
		if(dp[0][i]!=INF)
		{
			int tmp_fun=0,tmp_fee=0,tmp_time=0;
			for(int j=1;j<n;++j)
				if(INSIDE(i,j))
				{
					tmp_fun+=fun[j];
					tmp_fee+=fee[j];
					tmp_time+=15;
				}

			if(dp[0][i]+tmp_time<=t && tmp_fee<=d)
				tot_fun=max(tot_fun,tmp_fun);
		}

	return tot_fun;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d%d%d",&d,&t,&n,&m);
		fee[0]=fun[0]=0;
		for(int i=1;i<=n;++i)
			scanf("%d%d",fee+i,fun+i);

		memset(g,0x3f,sizeof(g));

		int u,v,w;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[u][v]=g[v][u]=min(g[u][v],w);
		}

		for(int k=0;k<=n;++k)
			for(int i=0;i<=n;++i)
				for(int j=0;j<=n;++j)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		for(int i=0;i<=n;++i)
			g[i][i]=0;

		int max_fun=DP();

		if(max_fun<=0)
			printf("Case %d: No possible trip.\n",cas);
		else
			printf("Case %d: %d\n",cas,max_fun);
	}

	return 0;
}
