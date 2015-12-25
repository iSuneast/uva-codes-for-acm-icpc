/*
 * 11094 - Continents
 *
 * graph theory
 * flood fill
 * 题目没有说清楚,还是我没有看清楚 - -
 *
 * Region with coordinates (x,N-1) should be assumed to  have a common edge
 * with region (x,0) for every x between 0 and M-1 (inclusive).
 * 这句话很重要,意思是说,给定的图是圆柱形状的
 *
 * 还有一个是,地图可以包含各种字母,而king一开始说在的位置的字母就是陆地,其他的都是水
 * 这个是在题目的哪里说明的呀= =
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
#define MAXN 25
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int m, n, x, y, key;
char g[MAXN][MAXN], ooxx;

void dfs(int u, int v) {
	if (g[u][v] != ooxx)
		return;
	++key;
	g[u][v] = ' ';
	if (v == 1)
		dfs(u, n);
	if (v == n)
		dfs(u, 1);
	dfs(u + 1, v);
	dfs(u, v + 1);
	dfs(u - 1, v);
	dfs(u, v - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d %d", &m, &n) != EOF) {
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf(" %c", &g[i][j]);
			}
		}
		scanf("%d %d", &x, &y);
		ooxx = g[x + 1][y + 1];
		dfs(x + 1, y + 1);
		int final = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (g[i][j] == ooxx) {
					key = 0;
					dfs(i, j);
					final = max(key, final);
				}
			}
		}
		printf("%d\n", final);
	}

	return 0;
}

