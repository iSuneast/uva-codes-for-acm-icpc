/*
10308 - Roads in the North

graph theory...
Diameter of Tree...
求树的直径...
从任意点开始bfs,取最远的那点作为起点再次bfs
此时得到的最大距离就是树的直径了...
*/

#include<iostream>
#define MAXN 10003
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXN<<1];
int tot;
char buf[100];

void link(int u,int v,int w)
{
	data[tot].v=v;	data[tot].w=w;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void d_link(int u,int v,int w)
{
	link(u,v,w);
	link(v,u,w);
}

void graph_init()
{
	tot=0;
	memset(edge,0,sizeof(edge));
}

bool input()
{
	int u,v,w;
	int done=0;
	graph_init();
	while(gets(buf))
	{
		++done;
		if(!buf[0])	break;
		sscanf(buf,"%d%d%d",&u,&v,&w);
		d_link(u,v,w);
	}
	return done;
}

int dis[MAXN],q[MAXN];

int bfs(int u)
{
#define PUSH(s)	{q[rear++]=s;}

	int front=0,rear=0;
	memset(dis,0x3f,sizeof(dis));
	PUSH(u);	dis[u]=0;
	while(front<rear)
	{
		u=q[front++];
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]==INF)
			{
				dis[cur->v]=dis[u]+cur->w;
				PUSH(cur->v);
			}
	}

	int p=1;
	for(u=1;dis[u]!=INF;++u)
		if(dis[u]>dis[p])
			p=u;

	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(input())
	{
		int src=bfs(1);
		src=bfs(src);
		printf("%d\n",dis[src]);
	}

	return 0;
}
