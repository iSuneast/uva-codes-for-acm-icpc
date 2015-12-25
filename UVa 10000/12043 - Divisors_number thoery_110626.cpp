/*
 * 12043 - Divisors
 *
 * number theory
 * 预处理出d(n)与th(n),后直接扫描[a,b]区间,累加即可
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
#define MAXN 100001
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

bool fade[MAXN];
int prime[MAXN], sz;
int d[MAXN], th[MAXN], fac[20], facn;

void init() {
	sz = 0;
	prime[sz++] = 2;
	for (int i = 3; i < MAXN; i += 2) {
		if (!fade[i]) {
			prime[sz++] = i;
			for (int j = i + i; j < MAXN; j += i) {
				fade[j] = true;
			}
		}
	}

	for (int i = 1; i < MAXN; ++i) {
		int t = i;
		d[i] = 1;
		th[i] = 0;
		facn = 0;
		for (int j = 0; j < sz && prime[j] <= t; ++j) {
			if (t % prime[j] == 0) {
				int a = 1;
				while (t % prime[j] == 0) {
					t /= prime[j];
					fac[facn++] = prime[j];
					++a;
				}
				d[i] *= a;
			}
		}
		set<int> rem;
		for (int j = 0; j < (1 << facn); ++j) {
			int a = 1;
			for (int k = 0; k < facn; ++k) {
				if ((1 << k) & j) {
					a *= fac[k];
				}
			}
			if (rem.find(a) == rem.end()) {
				rem.insert(a);
				th[i] += a;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	init();

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		LL key[2] = { };
		for (int i = a; i <= b; ++i) {
			if (i % k == 0) {
				key[0] += d[i];
				key[1] += th[i];
			}
		}
		printf("%lld %lld\n", key[0], key[1]);
	}

	return 0;
}

