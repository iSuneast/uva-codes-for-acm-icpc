/*
193 - Graph Coloring

brute force...
再次证明我想得复杂了...

数据是有效的.
不会出现不连通的情况...
所以只需要从第一个点开始逐个枚举即可...
因为图中边有多条
所以实际上也并没有枚举2^100种...
*/

#include<iostream>
#define BLACK 2
#define WHITE 1
#define MAXN 110
using namespace std;

int node,edge,key,ans;
int color[MAXN],final[MAXN];
bool g[MAXN][MAXN];

void dfs(int cur)
{
	if(cur==node+1)
	{
		if(key>ans)
		{
			ans=key;
			memcpy(final,color,sizeof(color));
		}
	}
	else for(color[cur]=WHITE;color[cur]<=BLACK;++color[cur])
	{
		bool done=false;
		if(color[cur]==BLACK)
			for(int i=1;i<cur;++i)
				if(g[cur][i] && color[i]==BLACK)
				{
					done=true;
					break;
				}
		if(done)
			return ;
		if(color[cur]==BLACK)
			++key;
		dfs(cur+1);
		if(color[cur]==BLACK)
			--key;
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
		scanf("%d%d",&node,&edge);
		int u,v;
		memset(g,0,sizeof(g));
		for(int i=0;i<edge;++i)
		{
			scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=true;
		}

		memset(color,0,sizeof(color));
		key=ans=0;
		dfs(1);

		printf("%d\n",ans);
		bool first=true;
		for(int i=1;i<=node;++i)
			if(final[i]==BLACK)
			{
				if(!first)
					putchar(' ');
				first=false;
				printf("%d",i);
			}
		putchar('\n');
	}

	return 0;
}
