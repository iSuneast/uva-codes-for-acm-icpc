/*
 * 10843 - Anne's game
 *
 * math
 * 生成树计数 凯利公式 n^(n-2)
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
#define MAXN 101
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;
const LL mod = 2000000011LL;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	LL f[MAXN];
	f[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		f[i]=1;
		for(int j=2; j<i; ++j) {
			f[i]=(f[i]*i)%mod;
		}
	}

	int dataset, n;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		printf("Case #%d: %lld\n", cas, f[n]);
	}

	return 0;
}

