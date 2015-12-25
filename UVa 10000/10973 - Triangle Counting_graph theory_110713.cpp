/*
 * 10973 - Triangle Counting
 *
 * graph theory
 * 三条边的圈
 * 先对于每个点的相邻节点排序
 * 然后,从某个点u出发走一条边到达另外一个点v
 * 枚举u,v的相邻节点(因为之前已经排好序),统计相同的个数
 * 由于每个相同的圈被统计了6次,故答案/6
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
#define MAXN 3003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, m;
set<int> data[MAXN];
vector<int> edge[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			data[i].clear();
		}
		for (int i = 0, u, v; i < m; ++i) {
			scanf("%d %d", &u, &v);
			if (u == v)
				continue;
			data[u].insert(v);
			data[v].insert(u);
		}
		for (int i = 1; i <= n; ++i) {
			edge[i].clear();
			for (set<int>::iterator it = data[i].begin(); it != data[i].end(); ++it) {
				edge[i].push_back(*it);
			}
		}

		int key = 0;
		for (int i = 1; i <= n; ++i) {
			for (int p = edge[i].size() - 1; p >= 0; --p) {
				int j = edge[i][p];
				for (int a = edge[i].size() - 1, b = edge[j].size() - 1; a >= 0
						&& b >= 0;) {
					if (edge[i][a] < edge[j][b]) {
						--b;
					} else if (edge[i][a] > edge[j][b]) {
						--a;
					} else {
						--a, --b, ++key;
					}
				}
			}
		}
		printf("%d\n", key / 6);
	}

	return 0;
}

