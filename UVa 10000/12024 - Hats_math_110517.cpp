/*
 * 12024 - Hats
 *
 * combination math
 * permuatation
 * 错排数
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

LL fac[13], key[13];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	fac[2] = 2;
	key[1] = 0;
	key[2] = 1;
	for (int i = 3; i <= 12; ++i) {
		fac[i] = fac[i - 1] * i;
		key[i] = (i - 1) * (key[i - 1] + key[i - 2]);
	}

	int dataset, n;
	scanf("%d", &dataset);
	while (dataset--) {
		scanf("%d", &n);
		printf("%lld/%lld\n", key[n], fac[n]);
	}

	return 0;
}

