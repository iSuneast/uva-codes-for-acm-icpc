/*
 * 11405 - Can U Win?
 *
 * graph theory
 * sssp
 * bitmask dp
 * 先预处理出说有兵所在位置之间的距离
 * 然后状态压缩DP,求出从原来位置开始的一条联通所有兵的最少时间
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
#define MAXN 13
#define SZ 9
#define Enemy 'P'
#define Knight 'k'
#define Empty '.'
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char g[MAXN][MAXN];
int n;
vector<pii> node;
int dis[SZ][MAXN][MAXN];

bool valid(pii cur) {
	return 1 <= cur.first && cur.first <= 8 && 1 <= cur.second && cur.second
			<= 8 && g[cur.first][cur.second] == Empty;
}

const int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void bfs(pii cur, int dis[MAXN][MAXN]) {
	memset(dis, 0x3f, sizeof(int) * MAXN * MAXN);
	dis[cur.first][cur.second] = 0;
	queue<pii> q;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int d = 0; d < 8; ++d) {
			pii next = make_pair(cur.first + dx[d], cur.second + dy[d]);
			if (valid(next) && dis[next.first][next.second] == INF) {
				dis[next.first][next.second] = dis[cur.first][cur.second] + 1;
				q.push(next);
			}
		}
	}
}

int G[MAXN][MAXN], dp[SZ][1 << SZ];

void ChkMin(int &a, const int &b) {
	if (a > b)
		a = b;
}

bool solve() {
	int sz = node.size();
	for (int i = 0; i < sz; ++i) {
		bfs(node[i], dis[i]);
	}
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			G[i][j] = dis[i][node[j].first][node[j].second];
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[sz - 1][1 << (sz - 1)] = 0;
	for (int i = 1; i < (1 << sz); ++i) {
		for (int j = 0; j < sz; ++j) {
			if ((1 << j) & i) {
				for (int k = 0; k < sz; ++k) {
					if (!((1 << k) & i)) {
						ChkMin(dp[k][i | (1 << k)], dp[j][i] + G[j][k]);
					}
				}
			}
		}
	}

	for (int i = 0; i < sz; ++i) {
		if (dp[i][(1 << sz) - 1] <= n) {
			return true;
		}
	}
	return false;
}

void read() {
	scanf("%d", &n);
	node.clear();
	pii pos;
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			scanf(" %c", &g[i][j]);
			if (g[i][j] == Knight) {
				pos = make_pair(i, j);
				g[i][j] = Empty;
			} else if (g[i][j] == Enemy) {
				node.push_back(make_pair(i, j));
				g[i][j] = Empty;
			}
		}
	}
	node.push_back(pos);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		read();
		puts(solve() ? "Yes" : "No");
	}

	return 0;
}

