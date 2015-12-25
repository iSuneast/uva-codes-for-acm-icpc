/*
10480 - Sabotage

graph theory...
max-flow-min-cut...
�������С��...
��Ϊ��С��һ����ͼ�����������
���Դ�Դ�����,����������ı߿ɴ�ĵ�Ϊһ������
��ͼһ��ɨ��...
��(u,v)����Ϊ0�ı���u,v���ڲ�ͬ�ļ������Ǹ��
*/

#include<iostream>
#define MAXN 503
#define MAXE 4000
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v,cap,flow;
	EDGE *rev,*next;
}*edge[MAXN],data[MAXE],*cur_edge[MAXN],*rev_edge[MAXN];
int tot,src,snk,node;

int n,m;

void graph_init()
{
	tot=0;
	src=1,snk=2,node=n;
	memset(edge,0,sizeof(edge));
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

void d_link(int u,int v,int cap)
{
	link(u,v,cap);
	link(v,u,cap);
}

int q[MAXN],dis[MAXN],cnt[MAXN];

void rev_bfs()
{
#define PUSH(s)	{q[rear++]=s;}

	int u=snk,front=0,rear=0;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	PUSH(u);	dis[u]=0;	cnt[0]++;

	while(front<rear)
	{
		u=q[front++];
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			int v=cur->v;
			if(dis[v]==INF)
			{
				dis[v]=dis[u]+1;
				++cnt[ dis[v] ];
				PUSH(v);
			}
		}
	}
}

int augment()
{
	int flow=INF,u;
	for(u=src;u!=snk;u=cur_edge[u]->v)
		flow=min(flow,cur_edge[u]->cap);

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
	rev_bfs();
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
			int dist=INF;
			for(cur=edge[u];cur;cur=cur->next)
				if(cur->cap)
					dist=min(dist,dis[cur->v]);
			dis[u]=dist+1;
			++cnt[ dis[u] ];
			if(u!=src)
				u=rev_edge[u]->v;
		}
	}

	return flow;
}

bool flag[MAXN];

void dfs(int u)
{
	flag[u]=true;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(cur->cap && !flag[cur->v])
			dfs(cur->v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int u,v,w;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		graph_init();
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			d_link(u,v,w);
		}

		isap();

		memset(flag,0,sizeof(flag));
		dfs(src);

		for(int u=1;u<=n;++u)
			for(EDGE *cur=edge[u];cur;cur=cur->next)
				if(!cur->cap && cur->flow>0 && flag[u]!=flag[cur->v])
					printf("%d %d\n",u,cur->v);
		putchar(10);
	}

	return 0;
}
