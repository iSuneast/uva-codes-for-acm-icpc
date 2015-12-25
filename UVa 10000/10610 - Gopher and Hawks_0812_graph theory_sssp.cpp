/*
10610 - Gopher and Hawks

graph theory...
sssp...
按题目的意思建好图后跑一次sssp即可...
*/

#include<iostream>
#include<queue>
#define MAXN 1003
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];

struct POINT{double x,y;}pnt[MAXN];
int v,m,n,dis[MAXN],tot;
char buf[100];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
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

double dist(POINT a,POINT b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return dx*dx+dy*dy;
}

bool inq[MAXN];

void spfa()
{
#define PUSH(s)	{if(!inq[s]){q.push(s);	inq[s]=true;}}
#define POP()	{inq[q.front()]=false;	q.pop();}

	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	PUSH(0);	dis[0]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]>dis[u]+1)
			{
				dis[cur->v]=dis[u]+1;
				PUSH(cur->v);
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&v,&m)!=EOF && (v||m))
	{
		gets(buf);	n=0;
		double d=v*m*60.0;
		d*=d;
		graph_init();
		while(gets(buf) && buf[0])
		{
			sscanf(buf,"%lf%lf",&pnt[n].x,&pnt[n].y);
			for(int j=0;j<n;++j)
				if(dist(pnt[j],pnt[n])<=d)
					d_link(j,n);
			++n;
		}

		spfa();
		if(dis[1]==INF)
			puts("No.");
		else
			printf("Yes, visiting %d other holes.\n",dis[1]-1);
	}

	return 0;
}
