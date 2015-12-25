/*
10983 - Buy one, get the rest free

graph theory...
max flow...
b-search...

just sort the price , and then b-search in the array to find the best price

the only tricky of this problem is the day limit
we can divide every node into d+1 nodes,label from i,i+n,i+2n...
link(i,i+n) with cap = INF
if we can go through u,v,c,p,e (e<=current price)
we link ( u+e*d , v+(e+1)*d ) with cap = c

source = 0, snk = (d+1)*n
link (source,i) with cap = people

finally calc the max-flow
check whether it's greater than total people
*/

#include<iostream>
#include<algorithm>
#define MAXN 350
#define MAXE 50000
#define MAXF 1003
#define INF 0x3f3f3f3f
using namespace std;

int n,d,m,ppl[MAXN],ppln;

struct EDGE
{
	int v,flow,cap;
	EDGE *next,*rev;
}*edge[MAXN],data[MAXE],*cur_edge[MAXN],*rev_edge[MAXN];
int tot,src,snk,node;

struct FLIGHT
{
	int u,v,c,p,e;
}flight[MAXF];
int fee[MAXF];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
	src=0,snk=n*(d+1),node=snk+1;
}

void make_edge(EDGE *cur,int u,int v,int cap,EDGE *rev)
{
	cur->v=v;	cur->cap=cap;	cur->flow=0;
	cur->next=edge[u];	edge[u]=cur;	cur->rev=rev;
}

void link(int u,int v,int cap)
{
	make_edge(&data[tot],u,v,cap,&data[tot+1]);
	make_edge(&data[tot+1],v,u,0,&data[tot]);
	tot+=2;
}

void build(int money)
{
	graph_init();
	for(int i=1;i<=n;++i)
	{
		link(src,i,ppl[i]);
		for(int j=0;j<d;++j)
			link(i+j*n,i+(j+1)*n,INF);
	}
	for(int i=0;i<m;++i)
	{
		if(flight[i].p<=money)
			link(flight[i].u+flight[i].e*n,flight[i].v+(flight[i].e+1)*n,flight[i].c);
	}
}

int q[MAXN],dis[MAXN],cnt[MAXN];

void rev_bfs()
{
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	int front=0,rear=0;
	q[rear++]=snk;	cnt[0]=1;	dis[snk]=0;
	while(front<rear)
	{
		int u=q[front++];
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[ cur->v ]==INF)
			{
				dis[cur->v]=dis[u]+1;
				++cnt[ dis[ cur->v ] ];
				q[rear++]=cur->v;
			}
	}
	
}

int augment()
{
	int flow=INF;
	for(int u=src;u!=snk;u=cur_edge[u]->v)
		flow=min(flow,cur_edge[u]->cap);

	for(int u=src;u!=snk;u=cur_edge[u]->v)
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
	rev_bfs();
	int flow=0,u=src;
	memcpy(cur_edge,edge,sizeof(edge));

	while(dis[src]<node)
	{
		if(u==snk)
		{
			flow+=augment();
			u=src;
		}

		EDGE *cur=cur_edge[u];
		for(;cur;cur=cur->next)
			if(cur->cap && dis[u]==dis[cur->v]+1)
				break;

		if(cur)
		{
			cur_edge[u]=cur;
			rev_edge[cur->v]=cur->rev;
			u=cur->v;
		}
		else
		{
			if(!(--cnt[ dis[u] ]))
				break;
			cur_edge[u]=edge[u];
			int dist=node;
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

int b_located()
{
	int s=0,e=m,mid;
	while(s<e)
	{
		mid=(s+e)/2;
		build(fee[mid]);

		if(isap()<ppln)
			s=mid+1;
		else
			e=mid;
	}
	return s;
}

void input()
{
	scanf("%d%d%d",&n,&d,&m);
	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d%d%d",&flight[i].u,&flight[i].v,&flight[i].c
			,&flight[i].p,&flight[i].e);
		fee[i]=flight[i].p;
	}
	sort(fee,fee+m);

	ppln=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&ppl[i]);
		ppln+=ppl[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		input();

		int key=b_located();

		if(key==m)
			printf("Case #%d: Impossible\n",cas);
		else
			printf("Case #%d: %d\n",cas,fee[key]);
	}

	return 0;
}
