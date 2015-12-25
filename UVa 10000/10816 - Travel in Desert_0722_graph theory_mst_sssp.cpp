/*
10816 - Travel in Desert

graph theory...
mst...
sssp...
先对图求:使s,t连通的最小生成树的最大边权ht
(不需要得到完整的生成树,只需当s,t连通时就可以退出)
然后将所有边权<=ht的边加入图,求一次sssp即可
*/

#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#define MAXN 103
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

struct EDGE
{
	int u,v;
	double r,d;
	bool operator<(const EDGE &t)const
	{
		if(fabs(r-t.r)<eps)
			return d<t.d;
		return r<t.r;
	}
}edge[MAXN*MAXN];

struct MST
{
	int v;
	double r,d;
	MST *next;
}*mst[MAXN],data[MAXN*MAXN*2];
int tot;

int n,e,s,t,fa[MAXN],ans[MAXN];
double dis[MAXN];

void init()
{
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		mst[i]=NULL;
		dis[i]=INF;
	}
}

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

void link(int u,int v,double r,double d)
{
	data[tot].r=r;
	data[tot].d=d;
	data[tot].v=v;
	data[tot].next=mst[u];
	mst[u]=&data[tot++];
}

double ht;

void kruskal()
{
	init();
	ht=0;
	for(int i=0;i<e;++i)
	{
		int a=find(edge[i].u),b=find(edge[i].v);
		if(a!=b)
		{
			fa[a]=b;
			ht=max(ht,edge[i].r);
		}
		if(find(s)==find(t))
			break;
	}

	tot=0;
	for(int i=0;i<e && edge[i].r<=ht;++i)
	{
		link(edge[i].u,edge[i].v,edge[i].r,edge[i].d);
		link(edge[i].v,edge[i].u,edge[i].r,edge[i].d);
	}
}

bool inq[MAXN];

void spfa()
{
#define PUSH(s) {if(!inq[s]) q.push(s);	inq[s]=true;}
#define POP()	{inq[q.front()]=false;	q.pop();}

	queue<int> q;
	PUSH(s);	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		MST *cur=mst[u];

		while(cur)
		{
			if(dis[ cur->v ]>dis[u]+cur->d)
			{
				fa[cur->v]=u;
				dis[ cur->v ]=dis[u]+cur->d;
				PUSH(cur->v);
			}
			cur=cur->next;
		}
	}

}

void dfs(int u)
{
	if(u==s)
		printf("%d",s);
	else
	{
		dfs(fa[u]);
		printf(" %d",u);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&e)!=EOF)
	{
		scanf("%d%d",&s,&t);
		for(int i=0;i<e;++i)
			scanf("%d%d%lf%lf",&edge[i].u,&edge[i].v,&edge[i].r,&edge[i].d);
		sort(edge,edge+e);

		kruskal();

		spfa();

		dfs(t);
		printf("\n%.1lf %.1lf\n",dis[t],ht);
	}

	return 0;
}
