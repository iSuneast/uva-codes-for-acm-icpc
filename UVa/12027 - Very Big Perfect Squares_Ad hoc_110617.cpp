/*
 * 12027 - Very Big Perfect Squares
 *
 * Ad hoc...
 * 令数字为v1v2v3v4v5....
 * 数字长度为奇数的话，则解为sqrt(v1) + len/2个"0"
 * 否则，则解为sqrt(v1v2) + (len/2-1)个"0"
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
#define MAXN 1003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char var[MAXN];

void out(int l) {
	while (l--) {
		putchar('0');
	}
	putchar(10);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%s", var) != EOF && strcmp(var, "0")) {
		int len = strlen(var), zero;
		if (len & 1) {
			var[1] = 0;
			zero = len / 2;
		} else {
			var[2] = 0;
			zero = len / 2 - 1;
		}

		for (int i = 1, t = atol(var); i <= 10; ++i) {
			if (i * i > t) {
				printf("%d", i - 1);
				break;
			}
		}
		out(zero);
	}

	return 0;
}

