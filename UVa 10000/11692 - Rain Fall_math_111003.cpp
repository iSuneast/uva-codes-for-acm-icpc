/*
 * 11692 - Rain Fall
 *
 * math
 * 只有几种情况，分别讨论即可
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

	double l, k, t1, t2, h;
	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		scanf("%lf %lf %lf %lf %lf", &l, &k, &t1, &t2, &h);
		if (h + eps < l) {
			printf("%.6lf %.6lf\n", h, h);
		} else {
			double a = t1, b = -((t1 + t2) * k + h), c = k * l;
			double delta = b * b - 4 * a * c;
			if (delta < 0) {
				printf("%.6lf %.6lf\n", h, h);
			} else {
				delta = sqrt(delta);
				double x1 = (-b + delta) / (2 * a);
				if (fabs(h - l) < eps) {
					printf("%.6lf %.6lf\n", h, x1 * t1);
				} else {
					printf("%.6lf %.6lf\n", x1 * t1, x1 * t1);
				}
			}
		}
	}

	return 0;
}
