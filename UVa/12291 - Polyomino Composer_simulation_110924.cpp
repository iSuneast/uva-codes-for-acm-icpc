/*
 * 12291 - Polyomino Composer
 *
 * simulation
 * 找到小图的第一个'*'
 * 从大图里面删两次小图
 * 最后大图为空即可
 *
 * 数据有问题?
 * 读入用scanf(" %c")便wa了, gets可以ac
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
#define MAXN 33
#define X '*'
#define M '.'
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char g[2][MAXN][MAXN], c[MAXN][MAXN];
int n, m;

pii find(char g[MAXN][MAXN], int sz) {
	for (int i = 1; i <= sz; ++i) {
		for (int j = 1; j <= sz; ++j) {
			if (g[i][j] == X)
				return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}

bool empty() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (g[0][i][j] == X) {
				return false;
			}
		}
	}
	return true;
}

bool erase(pii u, pii v) {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (g[1][i][j] == X) {
				int a = i - v.first + u.first;
				int b = j - v.second + u.second;
				if (1 <= a && a <= n && 1 <= b && b <= n && g[0][a][b] == X) {
					g[0][a][b] = M;
				} else {
					return false;
				}
			}
		}
	}
	return true;
}

int solve() {
	pii b = find(g[1], m);
	if (!erase(find(g[0], n), b))
		return 0;
	if (!erase(find(g[0], n), b))
		return 0;
	return empty();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		gets(g[0][0]);
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; ++i) {
			gets(g[0][i] + 1);
		}
		for (int i = 1; i <= m; ++i) {
			gets(g[1][i] + 1);
		}
		printf("%d\n", solve() ? 1 : 0);
	}

	return 0;
}

