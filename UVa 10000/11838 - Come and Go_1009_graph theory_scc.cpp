/*
11838 - Come and Go

graph theory...
scc...

we need to check whether there is a path between every pair(u,v)
so we just need to check whether the whole graph is a SCC
*/

#include<iostream>
#define MAXN 2003
#define MAXE 4000003
using namespace std;

struct GRAPH
{
	struct EDGE
	{
		int v;
		EDGE *next;
	}*edge[MAXN],data[MAXE];
	int tot,topo[MAXN],n,sz;
	bool flag[MAXN];

	void graph_init(int _n)
	{
		memset(edge,0,sizeof(edge));
		tot=0;
		sz=n=_n;
	}

	void link(int u,int v)
	{
		data[tot].v=v;
		data[tot].next=edge[u];
		edge[u]=&data[tot++];
	}

	void dfs(int u)
	{
		flag[u]=true;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(!flag[cur->v])
				dfs(cur->v);
		topo[--sz]=u;
	}

	void topo_sort()
	{
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;++i)
			if(!flag[i])
				dfs(i);
	}

	bool chk(int u)
	{
		memset(flag,0,sizeof(flag));
		dfs(u);
		for(int i=1;i<=n;++i)
			if(!flag[i])
				return false;
		return true;
	}
};

GRAPH ori,rev;
int n,m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int u,v,p;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		ori.graph_init(n);
		rev.graph_init(n);
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&p);
			ori.link(u,v);
			rev.link(v,u);
			if(p==2)
			{
				ori.link(v,u);
				rev.link(u,v);
			}
		}

		ori.topo_sort();
		puts(rev.chk(ori.topo[0])?"1":"0");
	}

	return 0;
}
