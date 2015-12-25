/*
 * 12019 - Doom's Day Algorithm
 *
 * Ad hoc...
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

const int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char ans[][20] = { "Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday" };
int rem[13][32];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int m = 1, d = 0, key = 6;
	while (m <= 12) {
		++d;
		if (d > days[m]) {
			d = 0;
			++m;
		} else {
			rem[m][d] = key;
			key = (key + 1) % 7;
		}
	}

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		scanf("%d %d", &m, &d);
		puts(ans[rem[m][d]]);
	}

	return 0;
}

