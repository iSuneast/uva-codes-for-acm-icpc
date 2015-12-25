/*
11377 - Airport Setup

graph theory...
sssp...
flag the city which has a airport
if we can link(u,v,w), weight
1) !flag[v] w=1 else w=0
2) !flag[u] w=1 else w=0
run sssp from source
be care of the case when source=target the answer should be 0
*/

#include<iostream>
#include<queue>
#define MAXN 2003
#define MAXE 20003
using namespace std;
const int INF=0x3f3f3f3f;

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXE];

int shortPath[MAXN][MAXN];
int n,m,k,tot;
bool flag[MAXN],done[MAXN];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

void link(int u,int v,int w)
{
	data[tot].v=v;
	data[tot].w=w;
	data[tot].next=edge[u];
	edge[u]=&data[tot++];
}

bool inq[MAXN];

void spfa(int src,int dis[MAXN])
{
	memset(dis,0x3f,sizeof(int)*MAXN);
	queue<int> q;
	dis[src]=flag[src]?0:1;
	q.push(src);	inq[src]=true;
	memset(inq,0,sizeof(inq));
	while(!q.empty())
	{
		int u=q.front();	q.pop();	inq[u]=false;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]>dis[u]+cur->w)
			{
				dis[cur->v]=dis[u]+cur->w;
				if(!inq[cur->v])
				{
					q.push(cur->v);
					inq[cur->v]=true;
				}
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,u,v,q;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		graph_init();

		scanf("%d%d%d",&n,&m,&k);
		memset(flag,0,sizeof(flag));
		while(k--)
		{
			scanf("%d",&u);
			flag[u]=true;
		}
		while(m--)
		{
			scanf("%d%d",&u,&v);
			link(u,v,flag[v]?0:1);
			link(v,u,flag[u]?0:1);
		}
		scanf("%d",&q);
		printf("Case %d:\n",cas);

		memset(done,0,sizeof(done));
		while(q--)
		{
			scanf("%d%d",&u,&v);
			if(u==v)
			{
				puts("0");
				continue;
			}
			if(!done[u])
			{
				spfa(u,shortPath[u]);
				done[u]=true;
			}
			if(shortPath[u][v]==INF)
				printf("%d\n",-1);
			else
				printf("%d\n",shortPath[u][v]);
		}
		putchar(10);
	}

	return 0;
}
