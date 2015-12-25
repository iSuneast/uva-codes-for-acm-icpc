/*
11474 - Dying Tree

graph theory...
check whether the graph is connected
make a bidirect edge if tree i,j can talk to each other
make a bidirect edge if tree i and doctor j can talk to each other
than check whether the sick tree is connected with any doctor
use dfs function is enough...
*/

#include<iostream>
#define MAXN 113
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];

struct POINT
{
	int x,y;
	POINT *next;
}*pnt[MAXN],buf[MAXN*MAXN];

int n,m,k,d,b,tot,pn;

void graph_init()
{
	memset(edge,0,sizeof(edge));
	memset(pnt,0,sizeof(pnt));
	tot=pn=0;
}

int dist(POINT *a,POINT *b)
{
	int dx=a->x-b->x;
	int dy=a->y-b->y;
	return dx*dx+dy*dy;
}

bool chk(POINT *a,POINT *b,int dis)
{
	for(;a;a=a->next)
		for(POINT *t=b;t;t=t->next)
			if(dist(t,a)<=dis)
				return true;
	return false;
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void input()
{
	scanf("%d%d%d%d",&n,&m,&k,&d);
	k*=k,d*=d;
	graph_init();

	for(;pn<m;++pn)
	{
		scanf("%d%d",&buf[pn].x,&buf[pn].y);
		buf[pn].next=pnt[pn];
		pnt[pn]=&buf[pn];
	}

	int end=n+m;
	for(int i=m;i<end;++i)
	{
		scanf("%d",&b);
		while(b--)
		{
			scanf("%d%d",&buf[pn].x,&buf[pn].y);
			buf[pn].next=pnt[i];
			pnt[i]=&buf[pn++];
		}
		for(int j=0;j<m;++j)
			if(chk(pnt[i],pnt[j],d))
			{
				link(i,j);
				link(j,i);
			}
		for(int j=m;j<i;++j)
			if(chk(pnt[i],pnt[j],k))
			{
				link(i,j);
				link(j,i);
			}
	}
}

bool flag[MAXN];

void dfs(int u)
{
	flag[u]=true;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(!flag[ cur->v ])
			dfs(cur->v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		input();

		memset(flag,0,sizeof(flag));
		dfs(m);
		bool ok=false;
		for(int i=0;i<m && !ok;++i)
			if(flag[i])
				ok=true;

		puts(ok?"Tree can be saved :)":"Tree can't be saved :(");
	}

	return 0;
}
