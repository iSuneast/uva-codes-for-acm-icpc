/*
 * 932 - Checking the N-Queens Problem
 *
 * Ad hoc
 * 判定皇后问题解的合法性
 * 对于初始状态无解，可以暴力枚举要移动的皇后
 * 继续判定即可
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
#define MAXN 33
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n;
char g[MAXN][MAXN];
bool h[3][MAXN << 1]; // col, dia, rev_dia

bool chk() {
	memset(h, 0, sizeof(h));
	for (int i = 0; i < n; ++i) {
		bool r = false;
		for (int j = 0; j < n; ++j) {
			if (g[i][j] == 'X') {
				if (r || h[0][j] || h[1][n - 1 - i + j] || h[2][i + j])
					return false;

				r = true;
				h[0][j] = true;
				h[1][n - 1 - i + j] = true;
				h[2][i + j] = true;
			}
		}
	}

	return true;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		scanf("%s", g[i]);
	}

	if (chk()) {
		puts("YES");
	} else {
		puts("NO");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] != 'X')
					continue;
				g[i][j] = '0';
				for (int a = 0; a < n; ++a) {
					for (int b = 0; b < n; ++b) {
						if (g[a][b] == '0') {
							g[a][b] = 'X';
							if (chk()) {
								puts("YES");
								for (int i = 0; i < n; ++i) {
									puts(g[i]);
								}
								return ;
							}
							g[a][b] = '0';
						}
					}
				}
				g[i][j] = 'X';
			}
		}
		puts("NO");
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	bool first = true;
	while (scanf("%d", &n) != EOF) {
		if (first)
			first = false;
		else
			putchar(10);

		solve();
	}

	return 0;
}

