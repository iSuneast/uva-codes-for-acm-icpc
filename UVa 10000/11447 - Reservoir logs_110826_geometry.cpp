/*
 * 11447 - Reservoir logs
 *
 * geometry
 * 还好没有被图片吓到...
 * 直接算出水库的体积,然后按题意算一下就可以了
 * 水库顶点的坐标已经按x轴有序, 则可以两两相邻的点算一下梯形的面积
 * 最后乘以宽度就可以了~
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
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct Point {
	double x, y;
} a, b;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset, n;
	scanf("%d", &dataset);
	while (dataset--) {
		scanf("%d", &n);
		double sum = 0;
		for (int i = 1; i <= n; ++i) {
			a = b;
			scanf("%lf %lf", &b.x, &b.y);
			if (i > 1) {
				sum += (-a.y - b.y) * (b.x - a.x) / 2.0;
			}
		}
		double w, init, use, fall;
		scanf("%lf", &w);
		double tot = sum * w;
		scanf("%lf %lf %lf", &init, &use, &fall);
		sum *= w * init / 100.0;
		sum -= use;
		if (sum < 0) {
			printf("Lack of water. ");
			sum = 0;
		}
		sum += fall;
		if (sum > tot) {
			printf("Excess of water. ");
			sum = tot;
		}
		printf("Final percentage: %.0lf%%\n", floor(sum / tot * 100.0));
	}

	return 0;
}

