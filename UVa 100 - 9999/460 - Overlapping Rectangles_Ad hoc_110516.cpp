/*
 * 460 - Overlapping Rectangles
 *
 * Ad hoc..
 * silly mistake...
 * check whether two rectangle overlapped and output the new rectangle
 * if their overlapping is a line, we should not consider it as a rectangle
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
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct Rectangle {
	int sx, sy, ex, ey;
	void read() {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	}
} a, b, c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		a.read();
		b.read();

		bool ok=false;
		if (a.ex >= b.sx && a.sx <= b.ex && a.ey >= b.sy && a.sy <= b.ey) {
			c.sx = max(a.sx, b.sx);
			c.ex = min(a.ex, b.ex);
			c.sy = max(a.sy, b.sy);
			c.ey = min(a.ey, b.ey);
			if(c.sx<c.ex && c.sy<c.ey) {
				ok=true;
				printf("%d %d %d %d\n", c.sx, c.sy, c.ex, c.ey);
			}

		}

		if(!ok)
			puts("No Overlap");

		if (dataset)
			putchar(10);
	}

	return 0;
}

