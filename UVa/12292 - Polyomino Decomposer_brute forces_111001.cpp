/*
 * 12292 - Polyomino Decomposer
 *
 * brute forces
 * 直接暴力枚举子集,然后覆盖
 * 取字典序最小的答案即可
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
#define MAXN 13
#define TOT 30
#define OX '*'
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, end, sz;
char g[MAXN][MAXN];
vector<pii> pos;

struct Data {
	char g[MAXN][MAXN];
	bool first;
	bool operator<(const Data &t) const {
		for (int i = 0; i < n; ++i) {
			int a = strcmp(g[i], t.g[i]);
			if (a)
				return a < 0;
		}
		return false;
	}
} final, tmp;

void out(char g[MAXN][MAXN]) {
	for (int i = 0; i < n; ++i) {
		puts(g[i]);
	}
	putchar(10);
}

bool spj() {
	if (sz <= 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == OX) {
					g[i][j] = 'a';
				}
			}
		}
		return true;
	}
	return false;
}

pii yes[TOT];
bool flag[MAXN][MAXN];
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
pii q[TOT];

int bfs(int x, int y) {
	int front = 0, rear = 0;
	q[rear++] = make_pair(x, y);
	flag[x][y] = false;
	while (front < rear) {
		x = q[front].first, y = q[front].second;
		++front;
		for (int d = 0; d < 4; ++d) {
			int tx = x + dx[d], ty = y + dy[d];
			if (0 <= tx && tx < n && 0 <= ty && ty < n && flag[tx][ty]) {
				flag[tx][ty] = false;
				q[rear++] = make_pair(tx, ty);
			}
		}
	}
	return rear;
}

bool cover(int x, int y, int dep, char c) {
	for (int i = 0; i < dep; ++i) {
		int tx = yes[i].first - yes[0].first + x;
		int ty = yes[i].second - yes[0].second + y;
		if (0 <= tx && tx < n && 0 <= ty && ty < n && tmp.g[tx][ty] == OX) {
			tmp.g[tx][ty] = c;
		} else
			return false;
	}
	return true;
}

void chk(int dep) {
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < dep; ++i) {
		flag[yes[i].first][yes[i].second] = true;
	}

	if (bfs(yes[0].first, yes[0].second) != dep)
		return;

	memcpy(tmp.g, g, sizeof(g));
	char c = 'A';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (tmp.g[i][j] == OX && !cover(i, j, dep, c++)) {
				return;
			}
		}
	}
	if (final.first)
		final = tmp;
	else
		final = min(final, tmp);
	final.first = false;
}

void dfs(int p, int dep) {
	chk(dep);
	if (dep == end)
		return;
	for (int i = p; i < sz; ++i) {
		yes[dep] = pos[i];
		dfs(i + 1, dep + 1);
	}
}

void solve() {
	sz = pos.size();
	if (spj())
		return out(g);
	final.first = true;
	end = sz / 2;

	yes[0] = pos[0];
	dfs(1, 1);
	out(final.g);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n) {
		gets(g[0]);
		pos.clear();
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; ++i) {
			gets(g[i]);
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == OX) {
					pos.push_back(make_pair(i, j));
				}
			}
		}
		solve();
	}

	return 0;
}

