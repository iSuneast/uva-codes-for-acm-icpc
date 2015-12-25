/*
 * 12290 - Counting Game
 *
 * simulation
 * 直接模拟就可以了
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

int n, m, k, cnt[MAXN];

bool chk(int t) {
	if (t % 7 == 0)
		return true;
	for (; t; t /= 10) {
		if (t % 10 == 7)
			return true;
	}
	return false;
}

int solve() {
	int id = 0, p = 0;
	bool r = true;
	memset(cnt, 0, sizeof(cnt));
	while (cnt[m] < k) {
		if (r) {
			++p;
			if (p > n) {
				p = n - 1;
				r = false;
			}
		} else {
			--p;
			if (p < 1) {
				p = 2;
				r = true;
			}
		}
		if (chk(++id)) {
			cnt[p]++;
		}
	}
	return id;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d %d %d", &n, &m, &k) != EOF && (n || m || k)) {
		printf("%d\n", solve());
	}

	return 0;
}
