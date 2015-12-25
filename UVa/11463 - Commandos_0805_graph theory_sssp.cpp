/*
11463 - Commandos

graph theory...
sssp...
从起点,终点分别求一次sssp
然后枚举中间点,取最大距离和就是解...
*/

#include<iostream>
#include<queue>
#define MAXN 103
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];
int tot,src,snk;

int n,m;

void graph_init()
{
	tot=0;
	memset(edge,0,sizeof(edge));
}

int dis[2][MAXN];
bool inq[MAXN];

void spfa(int src,int dis[MAXN])
{
#define PUSH(s)	{if(!inq[s])	q.push(s);	inq[s]=true;}
#define POP()	{inq[q.front()]=false;	q.pop();}

	memset(dis,0x3f,sizeof(int)*MAXN);
	queue<int> q;
	PUSH(src);	dis[src]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			int v=cur->v;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				PUSH(v);
			}
		}
	}
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void d_link(int u,int v)
{
	link(u,v);
	link(v,u);
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
		graph_init();
		int u,v;
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			d_link(u,v);
		}
		scanf("%d%d",&src,&snk);
		spfa(src,dis[0]);
		spfa(snk,dis[1]);
		int key=0;
		for(int i=0;i<n;++i)
			key=max(key,dis[0][i]+dis[1][i]);

		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
