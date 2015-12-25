/*
 * 12011 - Complete the Set
 *
 * bit-mask dp
 * if a number contain a bit in P, then
 * it must contain at least all the digits TMP&=t
 *     // TMP is initialization with (111...11)_2 (all 1's in binary represent)
 *     // t is the input number which ((1<<p)&t) is true
 * as a<2^18, we got at most 18 different TMP
 * using bit-mask to check which TMP we should use to form a new number
 *
 * p.s since a<2^18, we can use a mark array with size == 2^18
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
#define BIT 18
#define MAXN (1<<BIT)
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int ALL = MAXN - 1;

int minV[BIT], rem[BIT], sz;
bool ok[MAXN];

int add(const int &u) {
	if (!ok[u]) {
		ok[u] = true;
		return 1;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset, n, var;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i < BIT; ++i) {
			minV[i] = ALL;
		}

		memset(ok, 0, sizeof(ok));
		int a = 0, b = ALL;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &var);
			a |= var;
			b &= var;
			ok[var] = true;
			for (int t = var, p = 0; t; t >>= 1, ++p) {
				if (t & 1)
					minV[p] &= var;
			}
		}

		sz = 0;
		for (int i = 0; i < BIT; ++i) {
			if (minV[i] != ALL) {
				rem[sz++] = minV[i];
			}
		}

		int key = add(a) + add(b), all = (1 << sz);
		for (int i = 1; i < all; ++i) {
			int a = ALL, b = 0;
			for (int j = 0; j < sz; ++j) {
				if ((1 << j) & i) {
					a &= rem[j];
					b |= rem[j];
				}
			}

			key += add(a);
			key += add(b);
		}

		printf("Case #%d: %d\n", cas, key);
	}

	return 0;
}

