/*
 * 10807 - Prim
 *
 * brute force...
 * sort all the edges by their weight
 * DFS check && build the two MST using the sorted edges
 *
 * pruning :
 * @ stop when the two MST have already done builded
 * @ stop when we won't have a better answer
 * @ if an edge can belongs to any of these two MST, we won't SKIP it (GREEDY idea)
 *
 * happy coding~
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define MAXN 11
#define MAXE 30
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, m, key;
struct EDGE {
	int u, v, w;
	bool fade;
	bool operator<(const EDGE &t) const {
		return w<t.w;
	}
}edge[MAXE];

struct UFS {
	int fa[MAXN], mst;
	UFS() {
		for(int i=1; i<=n; ++i) {
			fa[i]=i;
		}
		fa[0]=1;
		mst=0;
	}
	int find(int u) {
		return u==fa[u]? u: fa[u]=find(fa[u]);
	}
	bool merge(const int &u, const int &v) {
		int _u=find(u), _v=find(v);
		if(_u!=_v) {
			fa[_u]=_v;
			return true;
		}
		return false;
	}
};

void dfs(int p, const UFS &ufs0, const UFS &ufs1) {
	if(ufs0.fa[0]==n && ufs1.fa[0]==n) {
		key=min(key, ufs0.mst+ ufs1.mst);
		return ;
	}

	if(p==m || ufs0.mst+ufs1.mst>=key)
		return ;

	bool skip=true;
	UFS cur=ufs0;
	if(cur.merge( edge[p].u, edge[p].v )) {
		cur.mst+=edge[p].w;
		cur.fa[0]++;
		skip=false;
		dfs(p+1, cur, ufs1);
	}

	cur=ufs1;
	if(cur.merge( edge[p].u, edge[p].v )) {
		cur.mst+=edge[p].w;
		cur.fa[0]++;
		skip=false;
		dfs(p+1, ufs0, cur);
	}

	if(skip)
		dfs(p+1, ufs0, ufs1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d", &n)!=EOF && n) {
    	scanf("%d", &m);
    	for(int i=0; i<m; ++i) {
    		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    		edge[i].fade=false;
    	}
    	sort(edge, edge+m);

    	key=INF;
    	dfs(0, UFS(), UFS());

    	if(key==INF) {
    		puts("No way!");
    	} else {
    		printf("%d\n", key);
    	}
    }

    return 0;
}

