/*
 * 11367 - Full Tank?
 *
 * graph theory
 * sssp
 * 状态{位置，油量}，然后转移即可
 * 要用dijkstra堆优化，直接dp的话会超时
 *
 * 之前做法错了，还一直找不到错误。。。
 * 求出apsp，然后对于每个u，如果有一条最短的路径可以到达v，并且dis[u][v]<=c
 * 则认为u可以转移到v，并且转移的费用是dis[u][v]*price[u]，
 * 转移之后在v处残留的油量为0（！！！这里错了）
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
#define MAXN 1003
#define MAXC 101
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

vector<pii> edge[MAXN];
int n, p[MAXN];

struct DATA {
	int key, v, c;
	bool operator<(const DATA &t) const {
		return key > t.key;
	}
	DATA() {
	}
	DATA(const int &key, const int &v, const int &c) :
		key(key), v(v), c(c) {
	}
};

bool done[MAXC][MAXN];
int solve(int c, int s, int e) {
	priority_queue<DATA> pq;
	memset(done, 0, sizeof(done));
	pq.push(DATA(0, s, 0));
	while(!pq.empty()) {
		DATA cur=pq.top();	pq.pop();
		if(cur.v==e)
			return cur.key;
		if(done[cur.c][cur.v])
			continue;
		done[cur.c][cur.v]=true;

		if(cur.c+1<=c && !done[cur.c+1][cur.v]) {
			pq.push(DATA(cur.key+p[cur.v], cur.v, cur.c+1));
		}

		for(int i=edge[cur.v].size()-1; i>=0; --i) {
			int v=edge[cur.v][i].first, w=edge[cur.v][i].second;
			if(cur.c>=w && !done[cur.c-w][v]) {
				pq.push(DATA(cur.key, v, cur.c-w));
			}
		}
	}

	return INF;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int m, q, u, v, w;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			edge[i].clear();
			scanf("%d", &p[i]);
		}

		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &u, &v, &w);
			edge[u].push_back(make_pair(v, w));
			edge[v].push_back(make_pair(u, w));
		}

		scanf("%d", &q);
		while (q--) {
			scanf("%d %d %d", &w, &u, &v);
			int final = solve(w, u, v);
			if (final == INF)
				puts("impossible");
			else
				printf("%d\n", final);
		}
	}

	return 0;
}

