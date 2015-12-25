/*
10793 - The Orc Attack

graph theory...
floyd-warshall...
题目其实没有想象的复杂...
又是越是看起来很long很抽象的...越简单...
本体其实就是用floyd求最短路
然后加一些判断进去而已...
初始化INF为0x7f7f7f7f后俩个INF相加会溢出.
所以调floyd是还要加点判断
*/

#include<iostream>
#define MAXN 110
#define INF 0x7f7f7f7f
using namespace std;

int g[MAXN][MAXN],nodes,edges;

void floyd_warshall()
{
	for(int k=1;k<=nodes;++k)
		for(int i=1;i<=nodes;++i)
			for(int j=1;j<=nodes;++j)
				if(g[i][k]!=INF && g[k][j]!=INF)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
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
		int u,v,c;
		scanf("%d%d",&nodes,&edges);
		memset(g,0x7f,sizeof(g));
		for(int i=1;i<=nodes;++i)
			g[i][i]=0;
		for(int i=0;i<edges;++i)
		{
			scanf("%d%d%d",&u,&v,&c);
			g[u][v]=g[v][u]=min(g[u][v],c);
		}
		floyd_warshall();
		int key=-1;
		for(int i=6;i<=nodes;++i)
		{
			bool got=true;
			if(g[i][1]==INF)
				got=false;
			for(int j=2;j<=5 && got;++j)
				if(g[i][j]!=g[i][j-1])
					got=false;
			if(got)
			{
				int tmax,tmin;
				tmax=tmin=g[i][1];
				for(int j=6;j<=nodes;++j)
				{
					tmax=max(g[i][j],tmax);
					tmin=min(g[i][j],tmin);
				}
				tmax-=tmin;
				if(key==-1)
					key=tmax;
				else
					key=min(key,tmax);
			}
		}
		if(key==INF)	//图不连通...
			key=-1;
		printf("Map %d: %d\n",cas,key);
	}

	return 0;
}
