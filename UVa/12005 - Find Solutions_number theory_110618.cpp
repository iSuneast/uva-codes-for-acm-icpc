/*
 * 12005 - Find Solutions
 *
 * number theory
 * 可以对公式进行变化
 * c = ab - (a+b)/2 + 1
 * 令 x = 2a - 1, y = 2b - 1
 * 则 xy = 4ab - 2a - 2b = 4c - 3
 * 故，只需要算出4c-3的因子个数即可
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
#define MAXN 20000000
#define MAX_P 1270610
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

bool fade[MAXN];
LL prime[MAX_P];
int sz;

void init() {
	sz = 0;
	prime[sz++] = 2;
	for (int i = 3; i < MAXN; i += 2) {
		if (!fade[i]) {
			prime[sz++] = i;
			for (int j = i; j < MAXN; j += (i << 1)) {
				fade[j] = true;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	init();
	LL n;
	while (scanf("%lld", &n) != EOF && n) {
		printf("%lld ", n);
		n = 4 * n - 3;
		LL ans = 1;
		for (int i = 0; i < sz && prime[i] * prime[i] <= n; ++i) {
			if (n % prime[i] == 0) {
				int t = 1;
				while (n % prime[i] == 0) {
					n /= prime[i];
					++t;
				}
				ans *= t;
			}
		}
		if (n > 1)
			ans *= 2;
		printf("%lld\n", ans);
	}

	return 0;
}

