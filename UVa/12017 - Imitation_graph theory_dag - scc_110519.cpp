/*
 * 12017 - Imitation
 *
 * graph theory
 * scc && dag
 * find the scc and compress it into a DAG
 *
 * then the problem becomes quite simple
 * we just need to count how many edges at least/most in the graph
 * for the least case :
 *    nodes_in_a_scc > 1 , answer += nodes_in_a_scc
 *    answer += the edges_we_can't_delete // O(n*m) time
 * for the most case :
 *    answer2 += nodes_in_a_scc * (nodes_in_a_scc-1) // complete graph
 *    answer2 += nodes_in_a_scc * the_nodes_can_visit_from_current_scc
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
#define MAXN 1001
#define MAXE 10003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

vector<int> edge[MAXN], rev[MAXN], dag[MAXN];
int n;
bool flag[MAXN];
int topo[MAXN], sz, id[MAXN], ccN, ccSz[MAXN];

void topoS(int u) {
	flag[u] = true;
	for (int i = edge[u].size() - 1; i >= 0; --i) {
		if (!flag[edge[u][i]])
			topoS(edge[u][i]);
	}
	topo[sz--] = u;
}

void findCC(int u) {
	flag[u] = true;
	id[u] = ccN;
	++sz;
	for (int i = rev[u].size() - 1; i >= 0; --i) {
		if (!flag[rev[u][i]]) {
			findCC(rev[u][i]);
		}
	}
}

bool g[MAXN][MAXN];
int add;
set<pii> rem;

void dfs(int u) {
	flag[u] = true;
	add += ccSz[u];
	for (int i = dag[u].size() - 1; i >= 0; --i) {
		if (!flag[dag[u][i]]) {
			dfs(dag[u][i]);
		}
	}
}

void calc() {
	int key0 = 0, key1 = 0;
	for (int i = 1; i <= ccN; ++i) {
		for (int j = 1; j <= ccN; ++j) {
			flag[j] = false;
		}
		add = 0;
		dfs(i);
		add -= ccSz[i];
		for (int j = 1; j <= ccN; ++j) {
			g[i][j] = flag[j];
		}

		key1 += ccSz[i] * add;
		key1 += ccSz[i] * (ccSz[i] - 1);
		if (ccSz[i] > 1)
			key0 += ccSz[i];
	}

	for (int i = 1; i <= ccN; ++i) {
		for (int j = dag[i].size() - 1; j >= 0; --j) {
			int v = dag[i][j];
			bool ok = true;
			for (int k = 1; k <= ccN; ++k) {
				if (k != i && k != v && g[i][k] && g[k][v]) {
					ok = false;
					break;
				}
			}
			key0 += ok;
		}
	}

	printf(" %d %d\n", key0, key1);
}

void build() {
	for (int i = 1; i <= ccN; ++i) {
		dag[i].clear();
		for (int j = 1; j <= ccN; ++j) {
			g[i][j] = false;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = edge[i].size() - 1; j >= 0; --j) {
			int v = edge[i][j];
			if (id[i] != id[v] && !g[id[i]][id[v]]) {
				g[id[i]][id[v]] = true;
				dag[id[i]].push_back(id[v]);
			}
		}
	}

	calc();
}

void process() {
	memset(flag, 0, sizeof(flag));
	sz = n;
	for (int i = 1; i <= n; ++i) {
		if (!flag[i]) {
			topoS(i);
		}
	}

	memset(flag, 0, sizeof(flag));
	ccN = 0;
	for (int i = 1; i <= n; ++i) {
		int u = topo[i];
		if (!flag[u]) {
			++ccN;
			sz = 0;
			findCC(u);
			ccSz[ccN] = sz;
		}
	}

	build();
}

void read() {
	int m, u, v;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		edge[i].clear();
		rev[i].clear();
	}

	while (m--) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		rev[v].push_back(u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		read();
		printf("Case #%d:", cas);
		process();
	}

	return 0;
}

