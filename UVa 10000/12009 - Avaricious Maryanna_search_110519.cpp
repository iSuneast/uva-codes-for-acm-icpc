/*
 * 12009 - Avaricious Maryanna
 *
 * search...
 * dfs...
 * there are at most two valid solution for n>1
 * and the solution N is the sub-solution of N+1
 * so we can generate the solution of N=500, and the output
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
#define MAXN 503
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int key[MAXN], mul[MAXN * 2], n, sz;
int rem[10][MAXN];

void dfs(int dep) {
	if (dep == n) {
		if (!key[n - 1])
			return;
		for (int i = 0; i < n; ++i) {
			rem[sz][i] = key[i];
		}
		++sz;
		return;
	}
	for (int i = 0; i < 10; ++i) {
		key[dep] = i;
		for (int j = 0; j < dep; ++j) {
			mul[j + dep] += 2 * key[dep] * key[j];
		}
		mul[dep + dep] += key[dep] * key[dep];

		int carry = 0, var;
		bool fade = false;
		for (int i = 0; i <= dep; ++i) {
			var = mul[i] + carry;
			if (var % 10 != key[i]) {
				fade = true;
				break;
			}
			carry = var / 10;
		}
		if (!fade)
			dfs(dep + 1);

		for (int j = 0; j < dep; ++j) {
			mul[j + dep] -= 2 * key[dep] * key[j];
		}
		mul[dep + dep] -= key[dep] * key[dep];
	}
}

void init() {
	sz = 0;
	n = 500;
	dfs(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	init();
	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		if (n == 1) {
			printf("Case #%d: 0 1 5 6\n", cas);
		} else {
			printf("Case #%d:", cas);
			vector<int> k;
			if (rem[0][n - 1] && rem[1][n - 1]) {
				for (int i = n - 1; i >= 0; --i) {
					if (rem[0][i] != rem[1][i]) {
						if (rem[0][i] < rem[1][i]) {
							k.push_back(0);
							k.push_back(1);
							break;
						} else {
							k.push_back(1);
							k.push_back(0);
							break;
						}
					}
				}
			} else if (rem[0][n - 1]) {
				k.push_back(0);
			} else {
				k.push_back(1);
			}
			for (int i = 0; i < (int) k.size(); ++i) {
				putchar(' ');
				for (int j = n - 1; j >= 0; --j) {
					printf("%d", rem[k[i]][j]);
				}
			}
			putchar(10);
		}
	}

	return 0;
}

