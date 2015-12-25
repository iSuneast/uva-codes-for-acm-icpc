/*
 * 12289 - One-Two-Three
 *
 * Ad hoc
 * 水题，不解释
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	string q, one = "one";
	scanf("%d", &dataset);
	while (dataset--) {
		cin >> q;
		if (q.length() == 5) {
			puts("3");
		} else {
			int dif = 0;
			for (int j = 0; j < 3; ++j) {
				if (q[j] != one[j])
					++dif;
			}
			puts(dif <= 1 ? "1" : "2");
		}
	}

	return 0;
}
