/*
 * 12028 - A Gift from the Setter
 *
 * Ad hoc
 * 简单题
 * O（n）求出说有的a[],对a[]排序
 * a[0] + a[1] + a[2] + a[3] + ... a[n-1]
 * 则,abs(a[i]-a[j]) = a[i] - a[j] {i>j}
 * 故可得最终的公式 sum{ (-n + 2 * i + 1) * a[i] }
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
#define MAXN 100003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

LL a[MAXN], k, c, n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%lld %lld %lld %lld", &k, &c, &n, &a[0]);
		for (int i = 1; i < n; ++i) {
			a[i] = (k * a[i - 1] + c) % 1000007;
		}
		sort(a, a + n);
		LL final = 0;
		for (int i = 0; i < n; ++i) {
			final += (-n + 2 * i + 1) * a[i];
		}
		printf("Case %d: %lld\n", cas, final);
	}

	return 0;
}

