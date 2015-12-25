/*
 * 10203 - Snow Clearing
 *
 * graph theory
 * euler path
 * 题目好像很水
 * “with one lane in each direction”
 * 意思是说，每个条路分成两个道（那么每个点的度数必然是偶数了）
 * 所以只需要把说有的路长度加起来×2,除以速度就是答案了
 *
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

	const double s0 = 20.0 * 1000.0 / 60.0;
	int dataset;
	char buf[100];
	scanf("%d", &dataset), gets(buf), gets(buf);
	while (dataset--) {
		double x, y, tx, ty, key = 0;
		gets(buf);
		while (gets(buf) && buf[0]) {
			sscanf(buf, "%lf %lf %lf %lf", &x, &y, &tx, &ty);
			key += sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
		}
		key *= 2;
		LL final = round(key / s0);
		printf("%lld:%02lld\n", final / 60, final % 60);
		if (dataset)
			putchar(10);
	}

	return 0;
}

