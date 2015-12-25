/*
11324 - The Largest Clique

graph theory...

we calc the scc first...
compress the graph to a new one with NodeWeight=NodeInOneSCC
use DP On tree to find a path with largest weight sum
*/

#include<iostream>
#include<set>
#define MAXN 1003
#define MAXE 50003
using namespace std;

struct GRAPH
{
	struct EDGE
	{
		int v;
		EDGE *next;
	}*edge[MAXN],data[MAXE];
	int tot,topo[MAXN],n,sz;
	int flag[MAXN],cc,cnt,clique[MAXN];

	void graph_init(int _n)
	{
		memset(edge,0,sizeof(edge));
		tot=0;
		n=_n;
	}

	void link(int u,int v)
	{
		data[tot].v=v;
		data[tot].next=edge[u];
		edge[u]=&data[tot++];
	}

	void dfs(int u)
	{
		flag[u]=cc;
		++cnt;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(!flag[cur->v])
				dfs(cur->v);
		topo[--sz]=u;
	}

	void topo_sort()
	{
		memset(flag,0,sizeof(flag));
		cc=1;
		sz=n;
		for(int i=1;i<=n;++i)
			if(!flag[i])
				dfs(i);
	}

	void SCC(int key[MAXN])
	{
		memset(flag,0,sizeof(flag));
		cc=1;
		sz=n;
		for(int i=0;i<n;++i)
		{
			int u=key[i];
			if(!flag[u])
			{
				cnt=0;
				dfs(u);
				clique[cc++]=cnt;
			}
		}
	}

	set<int> si;

	bool chk(int u,int v)
	{
		int h=u*MAXN+v;
		if(si.find(h)==si.end())
		{
			si.insert(h);
			return true;
		}
		return false;
	}

	int dp[MAXN];
	int DP(int u,int w[MAXN])
	{
		if(dp[u]!=-1)
			return dp[u];
		dp[u]=w[u];
		int add=0;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			add=max(add,DP(cur->v,w));
		dp[u]+=add;

		return dp[u];
	}

	int DPOnTree(GRAPH &cc)
	{
		si.clear();
		for(int i=1;i<=cc.n;++i)
		{
			for(EDGE *cur=cc.edge[i];cur;cur=cur->next)
				if(cc.flag[i] != cc.flag[ cur->v ] && chk(cc.flag[cur->v],cc.flag[i]))
					link(cc.flag[cur->v],cc.flag[i]);
		}

		memset(dp,-1,sizeof(dp));
		int key=0;
		for(int i=1;i<=n;++i)
			key=max(key,DP(i,cc.clique));

		return key;
	}
};

GRAPH scc,rev,key;
int n,m;

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
		scc.graph_init(n);
		rev.graph_init(n);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			scc.link(u,v);
			rev.link(v,u);
		}

		scc.topo_sort();
		rev.SCC(scc.topo);

		key.graph_init(rev.cc-1);

		printf("%d\n",key.DPOnTree(rev));
	}

	return 0;
}
