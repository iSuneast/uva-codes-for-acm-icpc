/*
 * 12022 - Ordering T-shirts
 *
 * combination math
 * 组合数学
 * n个数分成m组，然后对这m个组进行全排列的总数就是答案了
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
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

LL fac[12], c[12][12], final;

LL C(int a, int b) {
	LL key = 1;
	for (int i = a - b + 1; i <= a; ++i) {
		key *= i;
	}
	for (int i = 2; i <= b; ++i) {
		key /= i;
	}
	return key;
}

void init() {
	fac[0] = 1;
	for (int i = 1; i < 12; ++i) {
		fac[i] = fac[i - 1] * i;
		for (int j = 0; j <= i; ++j) {
			c[i][j] = C(i, j);
		}
	}
}

int flag[12], n;
void dfs(int res, int dec, int dep) {
	if (!res) {
		LL add = 1;
		int rem = n;
		map<int, int> mii;
		for (int i = 0; i < dep; ++i) {
			add *= c[rem][flag[i]];
			mii[flag[i]]++;
			rem -= flag[i];
		}
		add *= fac[dep];
		for (map<int, int>::iterator it = mii.begin(); it != mii.end(); ++it) {
			add /= fac[it->second];
		}
		final += add;
	} else {
		for (int i = dec; i <= res; ++i) {
			flag[dep] = i;
			dfs(res - i, i, dep + 1);
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
		scanf("%d", &n);
		final = 0;
		dfs(n, 1, 0);
		printf("%lld\n", final);
	}

	return 0;
}

