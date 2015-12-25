/*
11183 - Teen Girl Squad

graph theory
msdt...
第一次写最小树形图...
写的好挫啊...
*/

#include<iostream>
#define MAXN 1010
#define INF 0x7f7f7f7f
using namespace std;

int g[MAXN][MAXN],n,m,v;
int fa[MAXN];
bool flag[MAXN],scc[MAXN];

void dfs(int u)
{
	for(int v=0;v<n;++v)
		if(g[u][v]!=INF && !flag[v])
		{
			flag[v]=true;
			dfs(v);
		}
}

bool chk()
{
	memset(flag,0,sizeof(flag));
	flag[0]=true;
	dfs(0);
	for(int i=0;i<n;++i)
		if(!flag[i])
			return false;
	return true;
}

int key;

void output()
{
	for(int i=0;i<n;++i)
		if(fa[i]!=i)
			key+=g[ fa[i] ][i];
	printf("%d\n",key);
}

void chu_liu()
{
	key=0;
	memset(scc,0,sizeof(scc));
	scc[0]=true;

	while(true)
	{
		for(int i=0;i<n;++i)
		{
			fa[i]=i;
			if(!scc[i])
				for(int j=0;j<n;++j)
					if(g[fa[i]][i]>g[j][i])
						fa[i]=j;
		}

		bool bk=true;
		for(int i=0;i<n;++i)
			if(!scc[i])
			{
				int j=fa[i],tot=0;
				memset(flag,0,sizeof(flag));
				while(!flag[j])
				{
					flag[j]=true;
					tot+=g[ fa[j] ][j];
					j=fa[j];
				}

				if(flag[i])
				{
					for(int k=0;k<n;++k)
						if(!flag[k])
						{
							for(int j=0;j<n;++j)
								if(flag[j])
								{
									g[i][k]=min(g[i][k],g[j][k]);
									g[k][i]=min(g[k][i],g[k][j]-g[ fa[j] ][j]);
								}
						}

					for(int j=0;j<n;++j)
						if(flag[j] && j!=i)
						{
							for(int k=0;k<n;++k)
								g[k][j]=g[j][k]=INF;
							scc[j]=true;
						}

					key+=tot;
					bk=false;
					break;
				}
			}
		if(bk)
			return output();
	}

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
		int m,u,v,w;
		scanf("%d%d",&n,&m);
		memset(g,0x7f,sizeof(g));
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[u][v]=w;
		}

		printf("Case #%d: ",cas);
		if(!chk())
			puts("Possums!");
		else
			chu_liu();
	}

	return 0;
}
