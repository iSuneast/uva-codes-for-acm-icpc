/*
11765 - Component Placement

graph theory...
max-flow-min-cut
最大流最小割
0		---	src->u->snk	正常建图
-1	---	src->u	容量INF	,	u->snk	正常
1		---	src->u	正常		,	u->snk	容量INF
如果u,v之间有边的话,连接一条u<->v的双向边
然后求最大流就是解了

poj的3469，基本类似的题.
http://124.205.79.250/JudgeOnline/problem?id=3469
*/

#include<iostream>
#define MAXNODE 210
#define MAXEDGE 500000
#define INF 0x3f3f3f3f
using namespace std;

int n,m;

struct EDGE
{
	int v,cap,flow;
	EDGE *next,*rev;
}*edge[MAXNODE],data[MAXEDGE],*cur_edge[MAXNODE],*rev_edge[MAXEDGE];
int tot,src,snk,node;

void graph_init()
{
	src=0,snk=n+1,node=n+2;
	tot=0;
	memset(edge,0,sizeof(edge));
}

void make_edge(EDGE *cur,int u,int v,int cap,EDGE *rev)
{
	cur->v=v;	cur->cap=cap;	cur->flow=0;
	cur->rev=rev;	cur->next=edge[u];	edge[u]=cur;
}

void link(int u,int v,int cap)
{
	make_edge(&data[tot],u,v,cap,&data[tot+1]);
	make_edge(&data[tot+1],v,u,0,&data[tot]);
	tot+=2;
}

void d_link(int u,int v,int cap)
{
	link(u,v,cap);
	link(v,u,cap);
}

int q[MAXNODE],cnt[MAXNODE],dis[MAXNODE];

void rev_bfs()
{
#define PUSH(s)	{q[rear++]=s;}

	memset(cnt,0,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
	int front=0,rear=0,u=snk;
	PUSH(u);	dis[u]=0,cnt[0]=1;
	while(front<rear)
	{
		u=q[front++];
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]==INF)
			{
				dis[cur->v]=dis[u]+1;
				++cnt[ dis[cur->v] ];
				PUSH(cur->v);
			}
	}
}

int agument()
{
	int flow=INF,u;
	EDGE *cur;
	for(u=src;u!=snk;u=cur_edge[u]->v)
		flow=min(cur_edge[u]->cap,flow);
		
	for(u=src;u!=snk;u=cur_edge[u]->v)
	{
		cur_edge[u]->cap-=flow;
		cur_edge[u]->flow+=flow;
		cur_edge[u]->rev->cap+=flow;
		cur_edge[u]->rev->flow-=flow;
	}
	
	return flow;
}

int isap()
{
	int flow=0,u=src;
	memcpy(cur_edge,edge,sizeof(edge));
	rev_bfs();
	while(dis[src]<node)
	{		
		if(u==snk)
		{
			flow+=agument();
			u=src;
		}
		EDGE *cur=cur_edge[u];
		
		for(;cur;cur=cur->next)
			if(cur->cap && dis[u]==dis[cur->v]+1)		//这里忘了加cap限制
				break;
		
		if(cur)
		{
			cur_edge[u]=cur;
			rev_edge[cur->v]=cur->rev;
			u=cur->v;
		}
		else
		{
			int dist=INF;
			if(!(--cnt[ dis[u] ]))
				break;
			cur_edge[u]=edge[u];
			for(cur=edge[u];cur;cur=cur->next)
				if(cur->cap)
					dist=min(dist,dis[ cur->v ]);
			dis[u]=dist+1;
			++cnt[ dis[u] ];
			if(u!=src)
				u=rev_edge[u]->v;
		}
	}
	return flow;
}

int up[MAXNODE],down[MAXNODE];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		int i,u,v,w;
		graph_init();
		
		for(i=1;i<=n;++i)
			scanf("%d",&up[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&down[i]);
		
		for(i=1;i<=n;++i)
		{
			scanf("%d",&w);
			if(!w)
			{
				link(src,i,up[i]);
				link(i,snk,down[i]);
			}
			else if(w==1)
			{
				link(src,i,up[i]);
				link(i,snk,INF);
			}
			else
			{
				link(i,snk,down[i]);
				link(src,i,INF);
			}
		}
		
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			d_link(u,v,w);
		}

		printf("%d\n",isap());
	}

	return 0;
}
