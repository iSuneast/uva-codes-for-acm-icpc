/*
 * 12295 - Optimal Symmetric Paths
 *
 * graph theory
 * sssp
 * 路径是对称的,所以可以把图按照斜对角线折叠, 合并折叠后的点, 得到一张新图
 * 新建起始点,与终结点(权为0), 从u连一条到v的边, 权为v的点权
 * dijksta算出最短路径数就可以了
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
#include <map>
#include <set>
#include <ctime>
#define SZ 101
#define MAXN 5100
#define MOD 1000000009
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int g[SZ][SZ], n;
vector<pii> edge[MAXN];
int node, id[SZ][SZ], src, snk;
const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

bool valid(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < n - r;
}

void build() {
	node = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			edge[node].clear();
			id[i][j] = node++;
		}
	}
	edge[node].clear(), edge[node+1].clear();
	src = node++, snk = node++;
	edge[src].push_back(make_pair(0, g[0][0]));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			for (int d = 0; d < 4; ++d) {
				int r = i + dr[d], c = j + dc[d];
				if (valid(r, c)) {
					edge[id[i][j]].push_back(make_pair(id[r][c], g[r][c]));
				}
			}
		}
		edge[id[i][n - i - 1]].push_back(make_pair(snk, 0));
	}
}

int dp[MAXN], dis[MAXN], q[MAXN];

void dijkstra(int u) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pii, vector<pii> , greater<pii> > pq;
	pq.push(make_pair(0, u));

	int sz = 0;
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		u = cur.second;
		if (dis[u] != INF)
			continue;
		dis[u] = cur.first;
		q[sz++] = u;
		for (int i = edge[u].size() - 1; i >= 0; --i) {
			int v = edge[u][i].first;
			if (dis[v] == INF) {
				pq.push(make_pair(edge[u][i].second + dis[u], v));
			}
		}
	}

	memset(dp, 0, sizeof(dp));
	dp[q[0]] = 1;
	for (int p = 0; p < sz; ++p) {
		u = q[p];
		for (int i = edge[u].size() - 1; i >= 0; --i) {
			int v = edge[u][i].first;
			if (dis[v] == dis[u] + edge[u][i].second) {
				dp[v] = (dp[v] + dp[u]) % MOD;
			}
		}
	}
}

void solve() {
	build();
	dijkstra(src);
	printf("%d\n", dp[snk]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &g[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = n - i; j < n; ++j) {
				int r = n - j - 1, c = n - i - 1;
				g[r][c] += g[i][j];
			}
		}
		solve();
	}

	return 0;
}

