/*
 * 12034 - Race
 *
 * math
 * 组合数学
 * 第二类stirling数
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
#define MAXN 1001
#define MOD 10056
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int s[MAXN][MAXN], fac[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	memset(s, 0, sizeof(s));
	fac[0] = 1;
	for (int n = 1; n < MAXN; ++n) {
		fac[n] = (fac[n - 1] * n) % MOD;
		s[n][1] = s[n][n] = 1;
		for (int k = 2; k < n; ++k) {
			s[n][k] = (s[n - 1][k - 1] + k * s[n - 1][k]) % MOD;
		}
	}

	int dataset, n;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		int final = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			final = (final + s[n][i] * fac[i]) % MOD;
		}
		printf("Case %d: %d\n", cas, final);
	}

	return 0;
}

