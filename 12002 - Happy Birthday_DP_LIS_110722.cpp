/*
 * 12002 - Happy Birthday
 *
 * DP
 * LIS
 * 有一个很复杂的想法，写的不好的话就会TLE
 * 枚举中间的某个值，一定会被取到
 * 然后对于这个值v，分两种情况讨论
 * Case 1: v前面的数只取小于等于v的，那么到达v的时候，一定可以取到v
 * 		对v后面的数，可以取大于v的LIS，取小于等于v的数和v前面的小于等于的数一起求LDS
 * 		解即为LIS+LDS+1
 * Case 2: 同Case 1, 只是把交换大于变成小于，小于变成大于而已
 * 简单观察就可以发现时间复杂度为O（N^2LogN），N为500，很容易超时
 *
 * 其实，可以更简单一点
 * 先求出从某个数开始到最后一个数的LIS以及LDS，O（N^2）{从后往前即可}
 * 然后枚举任意两个位置i，j
 * 如果value[i]>value[j]，则取LIS[i]+LDS[j]
 * 如果value[i]<value[j]，则取LDS[i]+LIS[j]
 * 对每个位置取max（LIS[i], LDS[i]）
 * 这样即可得到最优解
 *
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
#define MAXN 503
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int var[MAXN], n, dp[2][MAXN]; // LIS, LDS

int solve() {
	int key = 0;
	for (int i = n - 1; i >= 0; --i) {
		dp[0][i] = dp[1][i] = 1;
		for (int j = i + 1; j < n; ++j) {
			if (var[i] <= var[j]) {
				dp[0][i] = max(dp[0][j] + 1, dp[0][i]);
			}
			if (var[i] >= var[j]) {
				dp[1][i] = max(dp[1][j] + 1, dp[1][i]);
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (var[i] < var[j]) {
				key = max(key, dp[1][i] + dp[0][j]);
			} else if (var[i] > var[j]) {
				key = max(key, dp[0][i] + dp[1][j]);
			}
		}
		key = max(key, max(dp[0][i], dp[1][i]));
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &var[i]);
		}
		printf("%d\n", solve());
	}

	return 0;
}

/*
 * 	复杂想法的TLE代码 O(NlogN)
 *
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
#define MAXN 503
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int var[MAXN], n, dp[MAXN], tmp[MAXN];

int lis(int var[MAXN], int sz) {
	int key = 0;
	for (int i = 0; i < sz; ++i) {
		int p = upper_bound(dp, dp + key, var[i]) - dp;
		if (p == key) {
			dp[key++] = var[i];
		} else {
			dp[p] = var[i];
		}
	}
	return key;
}

int case_1(int p) {
	int sz = 0;
	for (int j = 0; j < n; ++j) {
		if (j != p && var[j] >= var[p]) {
			tmp[sz++] = var[j];
		}
	}
	int key = lis(tmp, sz) + 1;
	sz = 0;
	for (int j = n - 1; j > p; --j) {
		if (var[j] < var[p]) {
			tmp[sz++] = var[j];
		}
	}

	key += lis(tmp, sz);
	return key;
}

int case_2(int p) {
	int sz = 0;
	for (int j = n - 1; j >= 0; --j) {
		if (j != p && var[j] <= var[p]) {
			tmp[sz++] = var[j];
		}
	}
	int key = lis(tmp, sz) + 1;
	sz = 0;
	for (int j = p + 1; j < n; ++j) {
		if (var[j] > var[p]) {
			tmp[sz++] = var[j];
		}
	}

	key += lis(tmp, sz);
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &var[i]);
		}
		int key = 0;
		for (int i = 0; i < n; ++i) {
			int t1 = case_1(i);
			int t2 = case_2(i);
			key = max(key, max(t1, t2));
		}
		printf("%d\n", key);
	}

	return 0;
}
 */

