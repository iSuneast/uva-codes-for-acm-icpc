/*
10874 - Segments

graph theory...
sssp...
build the graph like
*
* 1) between consequence two segment 
*	 link the four nodes with four edges,
*	 weight = abs(OneSideOfAboveSegment-Segment.a)+abs(Segment.a-Segment.b)
* 2) do the same with source && sink
* 3) run sssp in the graph, and the final answer is dis(sink)+n-1
* 4) there's a tricky case, we shouldn't "+1 weight" while process 1)
*	 if there is only a line, "+1" will cause U WA.
*
*/
#include<iostream>
#include<cmath>
#include<queue>
#define MAXN 40003
#define MAXE 90003
using namespace std;
const int INF=0x3f3f3f3f;

struct SEGMENT
{
	int a,b;
}seg[MAXN>>1];

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXE];
int src,snk,tot,n,dis[MAXN];
bool inq[MAXN];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
	src=0,	snk=2*n+1;
}

void link(int u,int v,int w)
{
	data[tot].v=v;	data[tot].w=w;
	data[tot].next=edge[u];
	edge[u]=&data[tot++];
}

int dist(int p,int s,int e)
{
	return abs(p-s)+abs(e-s);
}

int spfa()
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	q.push(src);	dis[src]=0;	inq[src]=true;
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

	return dis[snk];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		graph_init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&seg[i].a,&seg[i].b);
			if(i==1)
			{
				link(src,i,dist(1,seg[i].b,seg[i].a) );
				link(src,i+n,dist(1,seg[i].a,seg[i].b) );
			}
			else
			{
				link(i-1,i,dist(seg[i-1].a,seg[i].b,seg[i].a) );
				link(i-1,i+n,dist(seg[i-1].a,seg[i].a,seg[i].b) );
				link(i-1+n,i,dist(seg[i-1].b,seg[i].b,seg[i].a) );
				link(i-1+n,i+n,dist(seg[i-1].b,seg[i].a,seg[i].b) );
			}
			if(i==n)
			{
				link(i,snk,n-seg[i].a);
				link(i+n,snk,n-seg[i].b);
			}
		}

		printf("%d\n",spfa()+n-1);
	}

	return 0;
}
