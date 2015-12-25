/*
 * 12049 - Just Prune The List
 *
 * sort
 * 排序后从前往后扫描即可
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
#define MAXN 10003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int a[2][MAXN], n[2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		for (int i = 0; i < 2; ++i) {
			scanf("%d", &n[i]);
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n[i]; ++j) {
				scanf("%d", &a[i][j]);
			}
			sort(a[i], a[i] + n[i]);
		}
		int p0 = 0, p1 = 0, key = 0;
		while (p0 < n[0] && p1 < n[1]) {
			if (a[0][p0] == a[1][p1]) {
				++p0;
				++p1;
			} else if (a[0][p0] < a[1][p1]) {
				++p0;
				++key;
			} else {
				++p1;
				++key;
			}
		}

		key += n[0] - p0 + n[1] - p1;
		printf("%d\n", key);
	}

	return 0;
}

