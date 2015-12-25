/*
 * 435 - Block Voting
 *
 * bit mask
 * O(2^n) time to find the minority party
 * check if any party not in current set can be add and turn the party into a big one
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
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int p, v[20], dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		scanf("%d", &p);
		int sum = 0, key[20] = { };
		for (int i = 0; i < p; ++i) {
			scanf("%d", &v[i]);
			sum += v[i];
		}
		int all = (1 << p) - 1, half = sum / 2;
		for (int i = 1; i < all; ++i) {
			int s = 0;
			for (int j = 0; j < p; ++j) {
				if ((1 << j) & i)
					s += v[j];
			}
			if (s > half)
				continue;
			for (int j = 0; j < p; ++j) {
				if (!((1 << j) & i) && s + v[j] > half)
					++key[j];
			}
		}

		for (int i = 0; i < p; ++i) {
			printf("party %d has power index %d\n", i + 1, key[i]);
		}
		putchar(10);
	}

	return 0;
}

