/*
341 - Non-Stop Travel

graph theory...
sssp...
简单的单源最短路...
多了个输出方案而已...
*/

#include<iostream>
#include<queue>
#define MAXN 13
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v,w;
	EDGE *next;
}data[MAXN*MAXN],*edge[MAXN];
int src,snk,tot;
int n,m;

void graph_init()
{
	tot=0;
	memset(edge,0,sizeof(edge));
}

void link(int u,int v,int w)
{
	data[tot].v=v;	data[tot].w=w;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

int dis[MAXN],fa[MAXN];
bool inq[MAXN];

void spfa()
{
#define PUSH(s)	{if(!inq[s])	q.push(s);	inq[s]=true;}
#define POP()	{inq[q.front()]=false;	q.pop();}

	memset(dis,0x3f,sizeof(dis));
	dis[src]=0;
	queue<int> q;
	PUSH(src);	fa[src]=src;

	while(!q.empty())
	{
		int u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			int v=cur->v,w=cur->w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				fa[v]=u;
				PUSH(v);
			}
		}
	}
}

void dfs(int u)
{
	if(fa[u]!=u)
		dfs(fa[u]);
	printf(" %d",u);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		graph_init();
		int v,w;
		for(int u=1;u<=n;++u)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d%d",&v,&w);
				link(u,v,w);
			}
		}
		scanf("%d%d",&src,&snk);
		spfa();

		printf("Case %d: Path =",cas++);
		dfs(snk);
		printf("; %d second delay\n",dis[snk]);
	}

	return 0;
}
