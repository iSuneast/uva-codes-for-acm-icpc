/*
 * 12036 - Stable Grid
 *
 * graph theory
 * net-flow
 * 网络流
 * 注意到题目给的grid里面的值范围为[1,100],建图过程如下
 * 源点到值,容量为值总共出现的个数
 * 值到n个列,容量为1
 * 列到汇点,容量为n
 * 满流的话有解
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
#define MAXN 250
#define MAXE 30000
#define SZ 103
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct EDGE {
	int v, cap, next;
	EDGE() {
	}
	EDGE(const int &v, const int &cap, const int &next) :
		v(v), cap(cap), next(next) {
	}
} data[MAXE];
int edge[MAXN], curE[MAXN], revE[MAXN], tot;

void init() {
	memset(edge, 0, sizeof(edge));
	tot = 1;
}

void link(int u, int v, int w) {
	data[++tot] = EDGE(v, w, edge[u]);
	edge[u] = tot;
	data[++tot] = EDGE(u, 0, edge[v]);
	edge[v] = tot;
}

int cnt[MAXN], dis[MAXN];
int sap(const int &node, const int &src, const int &snk) {
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	cnt[0] = node;

	memcpy(curE, edge, sizeof(edge));
	int flow = 0;
	for (int u = src; dis[src] < node;) {
		if (u == snk) {
			int aug = INF;
			for (int i = src; i != snk; i = data[curE[i]].v) {
				aug = min(aug, data[curE[i]].cap);
			}
			for (int i = src; i != snk; i = data[curE[i]].v) {
				data[curE[i]].cap -= aug;
				data[revE[i]].cap += aug;
			}

			flow += aug;
			u = src;
		}

		int cur = curE[u];
		for (; cur; cur = data[cur].next) {
			if (data[cur].cap && dis[data[cur].v] + 1 == dis[u])
				break;
		}

		if (cur) {
			curE[u] = cur;
			revE[data[cur].v] = cur ^ 1;
			u = data[cur].v;
		} else {
			if (!(--cnt[dis[u]]))
				break;
			curE[u] = edge[u];
			int dist = node;
			for (cur = edge[u]; cur; cur = data[cur].next) {
				if (data[cur].cap)
					dist = min(dist, dis[data[cur].v]);
			}

			dis[u] = dist + 1;
			++cnt[dis[u]];

			if (u != src)
				u = data[revE[u]].v;
		}
	}

	return flow;
}

int var[SZ][SZ], n, h[SZ];

bool chk() {
	memset(h, 0, sizeof(h));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			++h[var[i][j]];
		}
	}
	for (int i = 0; i < SZ; ++i) {
		if (h[i] > n)
			return false;
	}

	init();
	int sz = 1, src = 0;
	for (int i = 0; i < SZ; ++i) {
		if (h[i]) {
			link(src, sz++, h[i]);
		}
	}
	for (int i = 1; i < sz; ++i) {
		for (int j = 0; j < n; ++j) {
			link(i, j + sz, 1);
		}
	}
	int snk = sz + n;
	for (int j = 0; j < n; ++j) {
		link(sz + j, snk, n);
	}

	return sap(snk + 1, src, snk) == n * n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &var[i][j]);
			}
		}
		printf("Case %d: %s\n", cas, chk() ? "yes" : "no");
	}

	return 0;
}

