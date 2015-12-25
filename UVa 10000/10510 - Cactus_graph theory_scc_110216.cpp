/*
 * 10510 - Cactus
 *
 * graph theory...
 * scc...
 *
 * Cactus满足
 *   @ it is strongly connected 先检查图是不是scc
 *   @ each edge is part of exactly one directed simple cycle
 *        每条边只能出现在一个简单环里面，则从任意点开始dfs
 *        用两个数组dep[],low[]分别表示
 *           结点u的深度，以及u通过子节点最低能返回到的深度
 *        用color[]来标记结点的状态
 *           -1在递归栈中，0未访问，1结束访问
 *        如果u可以到达v且
 *           color[v]=-1 则low[u]=min(dep[v])
 *           color[v]=1  则low[u]=min(low[v])
 *           color[v]=0  访问v
 *           如果发现dep[v]>dep[u]+1，则说明(u,v)是前向边，无解
 *        如果有多于1个v满足，low[v]<dep[u]，则说明从u出发有多条反向边，无解
 *
 * 归纳如下，图是个scc，且scc图里面不含前向边，且每个点出发至多只有一条反向边。。。
 *
 * happy coding~
 */

#include<iostream>
#include<vector>
#define MAXN 10003
using namespace std;

vector<int> edge[MAXN];
int n, m, topo[MAXN*2], tot;
int vis[MAXN];

void dfs_chk(int u) {
	vis[u]=true;
	for(int sz=edge[u].size(), i=0; i<sz; ++i) {
		if(!vis[ edge[u][i] ])
			dfs_chk( edge[u][i] );
	}
	topo[--tot]=u;
}

int scc() {
	memset(vis, 0, sizeof(vis));
	tot=n;
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs_chk(i);
	}

	memset(vis, 0, sizeof(vis));
	tot=2*n;
	int cc=0;
	for(int i=n-1; i>=0; --i) {
		if(!vis[ topo[i] ]) {
			dfs_chk(topo[i]);
			++cc;
		}
	}

	return cc;
}

int low[MAXN], dep[MAXN], rev[MAXN];
bool fade;

void ChkMin(int &a, const int &t) {
	if(a>t)
		a=t;
}

bool dfs(int u,int depth) {
	vis[u]=-1;
	low[u]=dep[u]=depth;
	for(int sz=edge[u].size(), i=0; i<sz; ++i) {
		int v=edge[u][i];

		if(!vis[v] && !dfs(v, depth+1) )
			return false;
		if(dep[v] > dep[u]+1)
			return false;
		if(low[v]<depth) {
			if(!rev[u])
				rev[u]=true;
			else
				return false;
		}

		if(vis[v]==1)
			ChkMin(low[u], low[v]);
		else
			ChkMin(low[u], dep[v]);
	}

	vis[u]=1;
	return true;
}

bool Cactus() {
	if( scc()!=1 )
		return false;

	memset(vis, 0, sizeof(vis));
	memset(rev, 0, sizeof(rev));
	return dfs(0, 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while(dataset--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; ++i) {
			edge[i].clear();
		}
		for(int u, v; m--; ) {
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
		}

		puts(Cactus()? "YES": "NO");
	}

	return 0;
}
