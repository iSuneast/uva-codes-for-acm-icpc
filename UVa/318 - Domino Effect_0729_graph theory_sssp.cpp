/*
318 - Domino Effect

graph theory...
sssp...
单源最短路
spfa求出sssp后用
key=max{ (dis[u]+dis[v]+w)/2.0 | dis[] }
算出key就是答案了

注意bt数据"1 0"
*/

#include<iostream>
#include<queue>
#define MAXN 503
#define MAXEDGE 1000000
#define INF 0x3f3f3f3f
using namespace std;

int n,m;

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXEDGE];
int tot=0,src;

void graph_init()
{
	memset(edge,0,sizeof(edge));
	src=1;
	tot=0;
}

void link(int u,int v,int w)
{
	data[tot].v=v;data[tot].w=w;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void d_link(int u,int v,int w)
{
	link(u,v,w);
	link(v,u,w);
}

int dis[MAXN];
bool inq[MAXN];

void spfa()
{
#define PUSH(s)	{if(!inq[s]) {q.push(s); inq[s]=true;}}
#define POP()	{inq[q.front()]=false;	q.pop();}

	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	int u=src,v,w;
	dis[u]=0;	PUSH(u);

	while(!q.empty())
	{
		u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			v=cur->v;w=cur->w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				PUSH(v);
			}
		}
	}
}

void calc()
{
	int x=1,y=1,u;
	double key=0,t;
	for(int u=1;u<=n;++u)
		if(dis[u]>key)
		{
			key=dis[u];
			x=y=u;
		}

	for(int u=1;u<=n;++u)
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			int v=cur->v,w=cur->w;
			t=(dis[u]+dis[v]+w)/2.0;
			if(t>key)
			{
				key=t;
				x=u,y=v;
			}
		}

	if(x==y)
		printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",key,x);
	else
		printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",key,x,y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int i,j,k,u,v,w,cas=1;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		graph_init();
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&w);
			d_link(u,v,w);
		}
		spfa();

		printf("System #%d\n",cas++);
		calc();
	}

	return 0;
}
