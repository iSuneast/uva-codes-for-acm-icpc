/*
 * 11473 - Campus Roads
 *
 * geometry
 * 算出路的长度len,种m颗树, 则每隔len/m-1种一棵树就可以了
 * 从起点开始模拟往后走即可
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
#define SQR(k) ((k)*(k))
#define MAXN 103
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct Point {
	double x, y;
	double dist(const Point &t) {
		return sqrt(SQR(x-t.x) + SQR(y-t.y));
	}
} pnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset, n, m;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d %d", &n, &m);
		double len = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf", &pnt[i].x, &pnt[i].y);
			if (i) {
				len += pnt[i].dist(pnt[i - 1]);
			}
		}
		len /= m-1;

		Point cur = pnt[0];
		int p = 1;
		double jmp = len, t;
		printf("Road #%d:\n", cas);
		printf("%.2lf %.2lf\n", cur.x, cur.y);
		for (int i = 1; i < m; ++i) {
			while ((t = cur.dist(pnt[p])) < jmp) {
				jmp -= t;
				cur = pnt[p++];
			}

			cur.x += jmp * (pnt[p].x - cur.x) / t;
			cur.y += jmp * (pnt[p].y - cur.y) / t;

			printf("%.2lf %.2lf\n", cur.x, cur.y);
			jmp = len;
		}
		putchar(10);
	}

	return 0;
}

