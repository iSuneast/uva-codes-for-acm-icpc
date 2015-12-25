/*
563 - Crimewave

graph theory...
max-flow...
这题不难...
建图那边需要点技巧...
拆点,两点流量为1
然后就是高效的maxflow模板发挥作用了...

卡了这么久的题目...
终于...
*/

#include<iostream>
#define MAXNODE 5010
#define MAXEDGE 20010
#define JUMP 2500
#define INF 0x7f7f7f7f
using namespace std;

struct EDGE
{
	int ver,cap,flow;
	EDGE *next,*rev;
}data[MAXEDGE<<1],*edge[MAXNODE],*curedge[MAXNODE],*revedge[MAXNODE];

int hash(int x,int y)
{
	return (x-1)*50+y;
}

int n,m,bank,tot;
const int src=0,snk=5001;

void make_edge(EDGE &t,int u,int ver,int cap,EDGE &rev)
{
	t.ver=ver;	t.cap=cap;	t.flow=0;
	t.rev=&rev;
	t.next=edge[u];	edge[u]=&t;
}

void link(int u,int v,int w)
{
	make_edge(data[tot],u,v,w,data[tot+1]);
	make_edge(data[tot+1],v,u,0,data[tot]);
	tot+=2;
}

void init_graph()
{
	for(int i=0;i<MAXNODE;++i)
		edge[i]=NULL;

	tot=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int p=hash(i,j);
			link(p,p+JUMP,1);
			if(i==1 || i==n || j==1 || j==m)
				link(p+JUMP,snk,1);
			else
			{
				link(p+JUMP,hash(i-1,j),1);
				link(p+JUMP,hash(i+1,j),1);
				link(p+JUMP,hash(i,j-1),1);
				link(p+JUMP,hash(i,j+1),1);
			}
		}
}

int q[MAXNODE],dis[MAXNODE];
int cnt[MAXNODE],node;

void rev_bfs()
{
	int front=0,rear=0;
	memset(dis,0x7f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	q[rear++]=snk;
	dis[snk]=0;	cnt[0]=1;
	while(front<rear)
	{
		int u=q[front++];
		EDGE *cur=edge[u];
		while(cur!=NULL)
		{
			if(dis[cur->ver]==INF && cur->rev->cap)
			{
				dis[cur->ver]=dis[u]+1;
				q[rear++]=cur->ver;
				++cnt[ dis[cur->ver] ];
			}
			cur=cur->next;
		}
	}
	node=rear;
}

int augment()
{
	int flow=INF;
	for(int u=src;u!=snk;u=curedge[u]->ver)
		flow=min(flow,curedge[u]->cap);

	for(int u=src;u!=snk;u=curedge[u]->ver)
	{
		curedge[u]->cap-=flow;
		curedge[u]->rev->cap+=flow;
		curedge[u]->flow+=flow;
		curedge[u]->rev->flow-=flow;
	}

	return flow;
}

int isap()
{
	rev_bfs();

	int flow=0,u=src;
	memcpy(curedge,edge,sizeof(edge));
	while(dis[src]<node)
	{
		if(u==snk)
		{
			flow+=augment();
			u=src;
		}

		EDGE *cur;
		for(cur=curedge[u];cur!=NULL;cur=cur->next)
			if(cur->cap && dis[u]==dis[cur->ver]+1)
				break;

		if(cur)
		{
			curedge[u]=cur;
			revedge[cur->ver]=cur->rev;
			u=cur->ver;
		}
		else
		{
			if(!(--cnt[ dis[u] ]))	//gap
				return flow;
			curedge[u]=edge[u];
			int mindis=node;
			EDGE *tmp;
			for(tmp=edge[u];tmp!=NULL;tmp=tmp->next)
				if(tmp->cap)
					mindis=min(mindis,dis[tmp->ver]);
			dis[u]=mindis+1;
			++cnt[ dis[u] ];
			if(u!=src)
				u=revedge[u]->ver;
		}
	}

	return flow;
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
		scanf("%d%d%d",&n,&m,&bank);
		init_graph();
		int x,y;
		for(int i=0;i<bank;++i)
		{
			scanf("%d%d",&x,&y);
			link(src,hash(x,y),1);
		}

		if(isap()==bank)
			puts("possible");
		else
			puts("not possible");
	}

	return 0;
}
