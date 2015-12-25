/*
 * 11267 - The Hire-a-Coder Business Model
 *
 * graph theory
 * mst
 * 首先,必须是一张二部图
 * 然后,要求图连通的情况下,边权之和最小
 * 可以先把说有负权边选中,然后求最小生成树
 * 不能只求最小生成树的...
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN 203
#define MAXE 11003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, m;
vector<pii> edge[MAXN];
int flag[MAXN];
struct Data {
	int u, v, w;
	bool operator<(const Data &t) const {
		return w < t.w;
	}
} data[MAXE];

bool dfs(int u, int c) {
	flag[u] = c;
	for (int i = edge[u].size() - 1; i >= 0; --i) {
		int v = edge[u][i].first;
		if (flag[v] == c || (!flag[v] && !dfs(v, -c))) {
			return false;
		}
	}
	return true;
}

bool chk() {
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; ++i) {
		if (!flag[i] && !dfs(i, 1)) {
			return false;
		}
	}
	return true;
}

int fa[MAXN];
int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void solve() {
	if (!chk()) {
		puts("Invalid data, Idiot!");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	sort(data, data + m);
	int key = 0, cnt = 1;
	for (int i = 0; i < m; ++i) {
		if (find(data[i].u) != find(data[i].v)) {
			++cnt;
			fa[find(data[i].u)] = find(data[i].v);
			key += data[i].w;
		} else if (data[i].w < 0) {
			key += data[i].w;
		}
	}

	printf("%d\n", key);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n) {
		scanf("%d", &m);
		for (int i = 1; i <= n; ++i) {
			edge[i].clear();
		}
		for (int i = 0, u, v, w; i < m; ++i) {
			scanf("%d %d %d", &u, &v, &w);
			data[i].u = u;
			data[i].v = v;
			data[i].w = w;
			edge[u].push_back(make_pair(v, w));
			edge[v].push_back(make_pair(u, w));
		}
		solve();
	}

	return 0;
}

