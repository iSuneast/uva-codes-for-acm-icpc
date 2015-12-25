/*
 * 12299 - RMQ with Shifts
 *
 * data struct
 * 用线段树来维护即可
 *
 * 注意是shift(循环移位),不是swap(翻转)...
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
#define MAXN 100001
#define MAXD 18
#define LS(p) ((p)<<1)
#define RS(p) (LS(p)|1)
#define MID(l, r) (((l)+(r))>>1)
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int var[MAXN];

struct SegTree {
	struct Node {
		int l, r, v;
		Node() {
		}
		Node(const int &l, const int &r) :
			l(l), r(r) {
		}
	} node[1 << MAXD];
	void build(int l, int r, const int &p = 1) {
		node[p] = Node(l, r);
		if (l + 1 == r) {
			node[p].v = var[l];
		} else {
			build(l, MID(l, r), LS(p));
			build(MID(l, r), r, RS(p));
			node[p].v = min(node[LS(p)].v, node[RS(p)].v);
		}
	}
	int query(int l, int r, const int &p = 1) {
		if (l <= node[p].l && node[p].r <= r)
			return node[p].v;
		int key = 1e9;
		if (l < MID(node[p].l, node[p].r))
			key = min(key, query(l, r, LS(p)));
		if (MID(node[p].l, node[p].r) < r)
			key = min(key, query(l, r, RS(p)));
		return key;
	}
	void update(int pos, const int &p = 1) {
		if (node[p].l + 1 == node[p].r) {
			node[p].v = var[pos];
		} else {
			if (pos < MID(node[p].l, node[p].r))
				update(pos, LS(p));
			else
				update(pos, RS(p));
			node[p].v = min(node[LS(p)].v, node[RS(p)].v);
		}
	}
} st;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &var[i]);
	}
	st.build(1, n + 1);

	vector<int> vi;
	int s, e;
	for (char op[33]; q--;) {
		scanf("%s", op);
		if (op[0] == 's') {
			vi.clear();
			for (char *token = strtok(op + 6, ",)"); token; token = strtok(
					NULL, ",)")) {
				vi.push_back(atol(token));
			}
			if (!vi.size())
				continue;
			e = var[vi[0]];
			for (int i = vi.size() - 1; i >= 0; --i) {
				s = var[vi[i]];
				var[vi[i]] = e;
				st.update(vi[i]);
				e = s;
			}
		} else {
			sscanf(op + 6, "%d%*c%d", &s, &e);
			printf("%d\n", st.query(s, e + 1));
		}
	}

	return 0;
}

