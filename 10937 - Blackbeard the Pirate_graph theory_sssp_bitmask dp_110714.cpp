/*
 * 10937 - Blackbeard the Pirate
 *
 * graph theory
 * sssp
 * bitmask dp
 * 先预处理出出出发点以及各个宝藏的距离
 * 然后状态DP求最小值即可~
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
#define MAXN 53
#define Land '@'
#define Water '~'
#define Palm '#'
#define Sand '.'
#define Danger '*'
#define Treasure '!'
#define SZ 11
#define INSIDE(a,b) ((a)&(1<<(b)))
#define MERGE(a,b) ((a)|(1<<(b)))
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char g[MAXN][MAXN];
int flag[MAXN][MAXN];
int n, m;
vector<pii> pos;

int dp[SZ][1 << SZ];
int G[SZ][SZ], dis[MAXN][MAXN];
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void bfs(pii cur) {
	memset(dis, 0x3f, sizeof(dis));
	queue<pii> q;
	dis[cur.first][cur.second] = 0;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int a = cur.first + dx[d];
			int b = cur.second + dy[d];
			if (flag[a][b] == 0 && dis[a][b] == INF) {
				dis[a][b] = dis[cur.first][cur.second] + 1;
				q.push(make_pair(a, b));
			}
		}
	}
}

void ChkMin(int &a, const int &b) {
	if (a > b)
		a = b;
}

int solve() {
	int sz = pos.size();
	for (int i = 0; i < sz; ++i) {
		if (flag[pos[i].first][pos[i].second] == -1)
			return -1;
		bfs(pos[i]);
		for (int j = 0; j < sz; ++j) {
			G[i][j] = dis[pos[j].first][pos[j].second];
			if (G[i][j] == INF)
				return -1;
		}
	}

	memset(dp, 0x3f, sizeof(dp));
	for(int i=0; i<sz; ++i) {
		dp[i][1<<i]=G[0][i];
	}
	for (int i = 1; i < (1 << sz); ++i) {
		for (int j = 0; j < sz; ++j) {
			if (INSIDE(i,j)) {
				for (int k = 0; k < sz; ++k) {
					if (!INSIDE(i, k)) {
						ChkMin(dp[k][MERGE(i,k)], dp[j][i] + G[j][k]);
					}
				}
			}
		}
	}

	return dp[0][(1 << sz) - 1];
}

void read() {
	memset(flag, -1, sizeof(flag));
	pos.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf(" %c", &g[i][j]);
			flag[i][j] = 0;
			if (g[i][j] == Land) {
				pos.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (g[i][j] == Palm || g[i][j] == Water) {
				flag[i][j] = -1;
			} else if (g[i][j] == Danger) {
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						flag[i + dx][j + dy] = -1;
					}
				}
			} else if (g[i][j] == Treasure) {
				pos.push_back(make_pair(i, j));
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d %d", &n, &m) != EOF && (n||m)) {
		read();
		printf("%d\n", solve());
	}

	return 0;
}

