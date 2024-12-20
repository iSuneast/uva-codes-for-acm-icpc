/*
11603 - Its all about the Bandwidth

graph theory...
MST...
prim
第一次写prim...
终于学会了...
好棒...

题目要求说用最少的边连接得到最大的流量...
并且说有点对间的流量与原图一致...
则用prim跑出mst后
用floyd算出所有点对的最大流量与原图对比...
若有不相同则无解...
否则输出mst的所有边即可...
*/

#include<iostream>
#define MAXN 210
#define INF 0x7f7f7f7f
using namespace std;

int g[MAXN][MAXN],new_g[MAXN][MAXN],tmp[MAXN][MAXN],dis[MAXN],fa[MAXN],n;
bool inq[MAXN];

int prim()
{
	int key=0;
	for(int i=0;i<n;++i)
		dis[i]=INF,inq[i]=true;
	dis[0]=0;
	fa[0]=0;
	memset(new_g,0,sizeof(new_g));
	for(int i=0;i<n;++i)
	{
		int u=-1;
		for(int i=0;i<n;++i)
			if(inq[i])
			{
				if(u==-1)
					u=i;
				else if(dis[i]!=INF && dis[i]>dis[u])
					u=i;
			}
		inq[u]=false;
		key+=new_g[ fa[u] ][u]=new_g[u][ fa[u] ]=g[ fa[u] ][u];
		for(int v=0;v<n;++v)
			if(inq[v])
			{
				if(dis[v]==INF)
				{
					dis[v]=g[u][v];
					fa[v]=u;
				}
				else if(dis[v]<g[u][v])
				{
					dis[v]=g[u][v];
					fa[v]=u;
				}
			}
	}
	return key;
}

void floyd_warshall()
{
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				new_g[i][j]=max(new_g[i][j],min(new_g[i][k],new_g[k][j]));
}

bool chk()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(i!=j && new_g[i][j]!=g[i][j])
				return false;
	return true;
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
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&g[i][j]);
		prim();
		memcpy(tmp,new_g,sizeof(new_g));
		floyd_warshall();
		if(!chk())
			printf("Case #%d: Impossible\n",cas);
		else
		{
			printf("Case #%d: %d\n",cas,n-1);
			for(int i=0;i<n;++i)
				for(int j=i+1;j<n;++j)
					if(tmp[i][j])
						printf("%d %d %d\n",i,j,tmp[i][j]);
		}
	}

	return 0;
}
