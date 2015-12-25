/*
10269 - Adventure of Super Mario

graph theory...
apsp..
非常暴力的算法...
g[u][v][k],保存u->v使用k次鞋子的最短距离

则由于可以用一次鞋子跑多个城镇
先对所有的城镇用floyd预处理
for	1->a
	for 1->a+b
		for 1->a+b
			松弛g[][][0]
如果g[][][0]<=l,则g[][][1]=0
然后
for	p:0->k
	for q:0->p
	(floyd的三重for)
g[i][j][p]=min(g[i][x][q]+g[x][j][p-q])

最后扫描一遍g[snk][src][]的最小值就是解...
*/

#include<iostream>
#define MAXN 103
#define INF 0x3f3f3f3f
using namespace std;

int g[MAXN][MAXN][13];
int a,b,m,l,k;

int floyd()
{
	int snk=a+b;
	for(int x=1;x<=a;++x)
		for(int i=1;i<=snk;++i)
			for(int j=1;j<=snk;++j)
				g[i][j][0]=min(g[i][j][0],g[i][x][0]+g[x][j][0]);

	for(int i=1;i<=snk;++i)
		for(int j=1;j<=snk;++j)
			if(g[i][j][0]<=l)
				g[i][j][1]=0;

	for(int p=0;p<=k;++p)
		for(int q=0;q<=p;++q)
			for(int x=1;x<=snk;++x)
				for(int i=1;i<=snk;++i)
					for(int j=1;j<=snk;++j)
						g[i][j][p]=min(g[i][j][p],g[i][x][q]+g[x][j][p-q]);

	int key=INF;
	for(int p=0;p<=k;++p)
		key=min(key,g[snk][1][p]);
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,u,v,w;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d%d%d",&a,&b,&m,&l,&k);
		memset(g,0x3f,sizeof(g));
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[u][v][0]=g[v][u][0]=min(g[u][v][0],w);
		}

		printf("%d\n",floyd());
	}

	return 0;
}
