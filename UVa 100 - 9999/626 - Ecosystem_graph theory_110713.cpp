/*
 * 626 - Ecosystem
 *
 * graph theory
 * 找一个3个点构成的圈
 * 直接枚举即可
 * 输出序列要递增/递减才行，并且按字典序输出
 * 可以把每个序列先预处理成递增/递减，无法处理则用最小表示法
 * 这样可以较为容易地判重
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
#define MAXN 103
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n;
bool g[MAXN][MAXN];
struct REM {
	int v[3];
	REM() {
	}
	REM(const int &_a, const int &_b, const int &_c) {
		int buf[3] = { _a, _b, _c };

		for (int s = 0; s < 3; ++s) {
			for (int a = 0, b = s; a < 3; a++, b = (b + 1) % 3) {
				v[a] = buf[b];
			}
			if ((v[0] < v[1] && v[1] < v[2]) || (v[0] > v[1] && v[1] > v[2])) {
				return;
			}
		}

		int t = min(_a, min(_b, _c));
		for (int i = 0; i < 3; ++i) {
			if (buf[i] == t) {
				for (int a = 0, b = i; a < 3; ++a, b = (b + 1) % 3) {
					v[a] = buf[b];
				}
				break;
			}
		}
	}
	bool operator<(const REM &t) const {
		for (int i = 0; i < 3; ++i) {
			if (v[i] != t.v[i]) {
				return v[i] < t.v[i];
			}
		}
		return false;
	}
};
set<REM> rem;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF) {
		for (int i = 0, t; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &t);
				g[i][j] = t;
			}
			g[i][i] = false;
		}
		rem.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (g[i][j] && g[j][k] && g[k][i]) {
						rem.insert(REM(i, j, k));
					}
				}
			}
		}
		for (set<REM>::iterator it = rem.begin(); it != rem.end(); ++it) {
			printf("%d %d %d\n", it->v[0] + 1, it->v[1] + 1, it->v[2] + 1);
		}
		printf("total:%d\n\n", rem.size());
	}

	return 0;
}

