/*
 * 11833 - Route Change
 *
 * graph theory
 * sssp
 * 题目说如果走到v<c处，就必须沿着v->v+1->v+2..走
 * 那么其实意思就是说v处只能有一条有向边连向v+1,如此而已
 *
 * 然后直接单源最短路即可
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
#define MAXN 253
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int g[MAXN][MAXN];
int n, m, c, k, dis[MAXN];
bool inq[MAXN];

int solve() {
	queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	q.push(k);
	inq[k] = true;
	dis[k] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int v = 0; v < n; ++v) {
			if (g[u][v] != INF && dis[v] > dis[u] + g[u][v]) {
				dis[v] = dis[u] + g[u][v];
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}

	return dis[c - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int u, v, p;
	while (scanf("%d %d %d %d", &n, &m, &c, &k) != EOF && n) {
		memset(g, 0x3f, sizeof(g));
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &u, &v, &p);
			if (u > v)
				swap(u, v);
			if (u < c && c <= v) {
				g[v][u] = p;
			} else if (v < c) {
				if (u + 1 == v)
					g[u][v] = g[v][u] = p;
			} else {
				g[u][v] = g[v][u] = p;
			}
		}
		printf("%d\n", solve());
	}

	return 0;
}

