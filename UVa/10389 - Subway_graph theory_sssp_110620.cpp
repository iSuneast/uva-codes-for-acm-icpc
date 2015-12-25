/*
 * 10389 - Subway
 *
 * graph thoery
 * sssp
 *
 * happy coding~
 */

#include <iostream>
#include <sstream>
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
#define MAXN 205
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

const double walk = 10 * 1000 / 60.0;
const double subway = 40 * 1000 / 60.0;
const double inf = 1e20;
struct Point {
	double x, y;
	Point() {
	}
	Point(const double &x, const double &y) :
		x(x), y(y) {
	}
	bool end() {
		return x == -1 && y == -1;
	}
	double dist(const Point &t) {
		return sqrt((x - t.x) * (x - t.x) + (y - t.y) * (y - t.y));
	}
} pnt[MAXN];
int n;
double g[MAXN][MAXN], dis[MAXN];

void read() {
	string buf, line;
	for (n = 0; n < 2; ++n) {
		scanf("%lf %lf", &pnt[n].x, &pnt[n].y);
	}

	for (int i = 0; i < MAXN; ++i) {
		fill_n(g[i], MAXN, inf);
	}

	getline(cin, buf);
	line = "";
	while (getline(cin, buf) && buf != "") {
		line = line + " " + buf;
	}

	stringstream sin(line);
	Point pre = Point(-1, -1);
	while (sin >> pnt[n].x >> pnt[n].y) {
		if (pnt[n].end()) {
			pre = pnt[n];
		} else {
			if (!pre.end()) {
				g[n - 1][n] = g[n][n - 1] = pnt[n].dist(pre) / subway;
			}
			pre = pnt[n++];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			g[i][j] = g[j][i] = min(g[i][j], pnt[i].dist(pnt[j]) / walk);
		}
		g[i][i] = 0;
	}
}

bool inq[MAXN];
double solve() {
	fill_n(dis, n, inf);
	memset(inq, 0, sizeof(inq));
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	inq[0] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int v = 0; v < n; ++v) {
			if (dis[v] > dis[u] + g[u][v]) {
				dis[v] = dis[u] + g[u][v];
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		read();
		printf("%.0lf\n", solve());

		if (dataset)
			putchar(10);
	}

	return 0;
}

