/*
11686 - Pick up sticks

graph theory...
toposort...
拓扑排序而已...
点比较多,用邻接表保存..
*/

#include<iostream>
#define MAXN 1000003
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN];
int tot,n,m,p,topo[MAXN];
char flag[MAXN];

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

bool dfs(int u)
{
	flag[u]=-1;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(flag[cur->v]==-1 || (!flag[cur->v] && !dfs(cur->v) ))
			return false;
	flag[u]=1;
	topo[--p]=u;
	return true;
}

bool topo_sort()
{
	p=n;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;++i)
		if(!flag[i] && !dfs(i))
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		int u,v;
		graph_init();
		while(m--)
		{
			scanf("%d%d",&u,&v);
			link(u,v);
		}
		if(!topo_sort())
			puts("IMPOSSIBLE");
		else for(int i=0;i<n;++i)
			printf("%d\n",topo[i]);
	}

	return 0;
}
