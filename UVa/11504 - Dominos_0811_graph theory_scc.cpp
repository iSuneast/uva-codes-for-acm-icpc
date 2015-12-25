/*
11504 - Dominos

graph theory...
scc,tarjan...
对反图进行伪拓扑排序...
得到序列后,从后往前对原图dfs...
标记所有可以访问到的节点...
dfs的次数就是要推倒dominos牌的个数...
*/

#include<iostream>
#define MAXN 100010
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN<<1],*rev_edge[MAXN];
int n,m,tot;

void graph_init()
{
	tot=0;
	memset(edge,0,sizeof(edge));
	memset(rev_edge,0,sizeof(rev_edge));
}

void link(int u,int v)
{
	data[tot].v=v;	
	data[tot].next=edge[u];	edge[u]=&data[tot++];
	data[tot].v=u;	
	data[tot].next=rev_edge[v];	rev_edge[v]=&data[tot++];
}

int topo[MAXN<<1],p;
bool flag[MAXN];

void dfs(int u,EDGE *edge[MAXN])
{
	flag[u]=true;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(!flag[ cur->v ])
			dfs(cur->v,edge);
	topo[--p]=u;
}

int SCC()
{
	memset(flag,0,sizeof(flag));
	p=n;
	for(int i=1;i<=n;++i)
		if(!flag[i])
			dfs(i,rev_edge);

	int scc=0;
	memset(flag,0,sizeof(flag));
	p=2*n;
	for(int i=n-1;i>=0;--i)
		if(!flag[ topo[i] ])
		{
			++scc;
			dfs(topo[i],edge);
		}

		return scc;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,u,v;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		graph_init();
		while(m--)
		{
			scanf("%d%d",&u,&v);
			link(u,v);
		}
		printf("%d\n",SCC());
	}

	return 0;
}
