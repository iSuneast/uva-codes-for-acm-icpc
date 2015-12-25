/*
 * 12010 - Boring Homework
 *
 * simulation...
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
#define MAXR 163
#define MAXC 83
#define MAXN 83
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, root;
char g[MAXR][MAXC];
struct NODE {
	int l, r, lSz, rSz;
} node[MAXN];

void insert(int v) {
	int u = root, p;
	while (u) {
		p = u;
		if (v < u) {
			u = node[u].l;
		} else {
			u = node[u].r;
		}
	}

	if (v < p)
		node[p].l = v;
	else
		node[p].r = v;
}

int dfs(int u) {
	if (!u)
		return 0;
	node[u].lSz = dfs(node[u].l);
	node[u].rSz = dfs(node[u].r);
	return node[u].lSz + node[u].rSz + 1;
}

void myFill(int r, int c, int n, char _c) {
	for (int i = 0; i < n; ++i) {
		g[r][c + i] = _c;
	}
}

void draw(int u, int dep, int add) {
	if (!u)
		return;
	int p = node[u].lSz + add;
	g[dep][p] = 'o';

	if (node[u].l) {
		int ln = node[node[u].l].rSz;
		myFill(dep, p - ln, ln, '-');
		g[dep][p - ln - 1] = '+';
		g[dep + 1][p - ln - 1] = '|';

		draw(node[u].l, dep + 2, add);
	}

	if (node[u].r) {
		int rn = node[node[u].r].lSz;
		myFill(dep, p + 1, rn, '-');
		g[dep][p + rn + 1] = '+';
		g[dep + 1][p + rn + 1] = '|';

		draw(node[u].r, dep + 2, p + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset, v;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		memset(node, 0, sizeof(node));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &v);
			if (i == 1) {
				root = v;
			} else {
				insert(v);
			}
		}
		dfs(root);

		for (int i = 0; i < MAXR; ++i) {
			for (int j = 0; j < MAXC; ++j) {
				g[i][j] = ' ';
			}
		}

		draw(root, 0, 0);
		printf("Case #%d:\n", cas);
		for (int i = 0; i < MAXR; ++i) {
			int j;
			for (j = MAXC - 1; j >= 0; --j) {
				if (g[i][j] != ' ') {
					break;
				}
			}
			if (j < 0) {
				break;
			}
			g[i][j + 1] = 0;
			puts(g[i]);
		}
	}

	return 0;
}

