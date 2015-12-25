/*
10296 - Jogging Trails

graph theory...
中国邮递员问题...
NP完全...
所以只能暴力加边了...
用状态压缩加速...
*/

#include<iostream>
#define MAXN 17
#define INF 0x7f7f7f7f
using namespace std;

int g[MAXN][MAXN],n,m;
int d[MAXN],hash[MAXN];
int state[1<<MAXN],cnt;

void floyd()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(g[i][k]!=INF && g[j][k]!=INF)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int dp(int cur)
{
	if(state[cur]==-1)
	{
		state[cur]=0;
		for(int i=0;i<cnt;++i)
			if(cur&(1<<i))
				for(int j=i+1;j<cnt;++j)
					if(cur&(1<<j))
					{
						int t=dp(cur-(1<<i)-(1<<j));
						t+=g[ hash[i] ][ hash[j] ];
						if(!state[cur])
							state[cur]=t;
						else
							state[cur]=min(t,state[cur]);
					}
	}
	return state[cur];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && n)
	{
		int u,v,w;
		memset(g,0x7f,sizeof(g));
		memset(d,0,sizeof(d));
		int sum=0;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			sum+=w;
			++d[u],++d[v];
			g[u][v]=g[v][u]=min(g[u][v],w);
		}

		cnt=0;
		for(int i=1;i<=n;++i)
			if(d[i]&1)
				hash[cnt++]=i;

		if(cnt)
		{
			floyd();
			memset(state,-1,sizeof(state));
			printf("%d\n",sum+dp((1<<cnt)-1));
		}
		else
			printf("%d\n",sum);
	}

	return 0;
}
