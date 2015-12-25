/*
11770 - Lighting Away

graph theory...
SCC...
求强连通分支
图比较大,用向量来保存边即可...
*/

#include<iostream>
#include<vector>
#define MAXN 10010
using namespace std;

int n,topo[MAXN<<1],p,scc,flag[MAXN];
vector<int> edges[MAXN],g2[MAXN];
bool degree[MAXN];

void dfs(int u,vector<int> g[MAXN])
{
	flag[u]=scc;
	int sz=g[u].size();
	for(int i=0;i<sz;++i)
		if(!flag[ g[u][i] ])
			dfs(g[u][i],g);
	topo[--p]=u;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int m,u,v;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			edges[i].clear();
			g2[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			g2[v].push_back(u);
		}
		memset(flag,0,sizeof(flag));
		p=n;	scc=1;
		for(int i=1;i<=n;++i)
			if(!flag[i])
				dfs(i,edges);
		memset(flag,0,sizeof(flag));
		p=n<<1;
		for(int i=0;i<n;++i)
			if(!flag[ topo[i] ])
			{
				dfs(topo[i],g2);
				++scc;
			}
		memset(degree,0,sizeof(degree));
		for(int i=1;i<=n;++i)
		{
			int sz=edges[i].size();
			for(int j=0;j<sz;++j)
				if(flag[ edges[i][j] ] != flag[i])
					degree[ flag[ edges[i][j] ] ]=true;
		}
		int key=0;
		for(int i=1;i<scc;++i)
			if(!degree[i])
				++key;
		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
