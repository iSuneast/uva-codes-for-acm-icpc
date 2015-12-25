/*
 * 10181 - 15-Puzzle Problem
 *
 * search
 * A*
 * 强大的A*算法
 * 15数码有16个<=15的数字，刚好可以用unsigned long long保存一个状态
 * 然后就是朴素的a*算法了
 * 用set判重即可
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
#define MAXN 10000000
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef pair<int, int> pii;
typedef unsigned long long ULL;

struct Data {
	int g[4][4];
	int h() {
		int key = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int r = g[i][j] / 4, c = g[i][j] % 4;
				key += abs(r - i) + abs(c - j);
			}
		}
		return key;
	}
	void out() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cout << g[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	ULL hash() {
		ULL key = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				key = (key << 4) | g[i][j];
			}
		}
		return key;
	}
	void read() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				scanf("%d", &g[i][j]);
				g[i][j] = (g[i][j] + 15) % 16;
			}
		}
	}
	bool judge() {
		int var[16], sz = 0, ok = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (g[i][j] == 15)
					ok = 3 - i;
				else
					var[sz++] = g[i][j];
			}
		}
		for (int i = 0; i < sz; ++i) {
			for (int j = i+1; j < sz; ++j) {
				if (var[i] > var[j]) {
					++ok;
				}
			}
		}
		return ok % 2 == 0;
	}
} data;

struct State {
	int g, h;
	ULL s;
	State *pre;
	char op;
	State() {
	}
	State(const int &g, const int &h, const ULL &s) :
		g(g), h(h), s(s) {
	}
	bool operator<(const State &t) const {
		return g + h > t.g + t.h;
	}
	pii recover(Data &t) {
		pii key;
		ULL buf = s;
		for (int i = 3; i >= 0; --i) {
			for (int j = 3; j >= 0; --j) {
				t.g[i][j] = buf & 15;
				buf >>= 4;
				if (t.g[i][j] == 15) {
					key = make_pair(i, j);
				}
			}
		}
		return key;
	}
} state[MAXN];
set<ULL> rem;
int tot;

struct CMP {
	bool operator()(const int &a, const int &b) const {
		return state[a].g + state[a].h > state[b].g + state[b].h;
	}
};

void dfs(State &cur) {
	if (!cur.g)
		return;
	dfs(*cur.pre);
	putchar(cur.op);
}

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
char op[] = "RLDU";

void solve() {
	priority_queue<int, vector<int> , CMP> pq;
	Data st;
	rem.clear();

	state[tot = 0] = State(0, data.h(), data.hash());
	rem.insert(state[tot].s);
	pq.push(tot++);
	while (!pq.empty()) {
		State &cur = state[pq.top()];
		pq.pop();
		if (!cur.h) {
			dfs(cur);
			putchar(10);
			return;
		}
		pii slide = cur.recover(st);
		for (int d = 0; d < 4; ++d) {
			int r = slide.first + dx[d], c = slide.second + dy[d];
			if (0 <= r && r < 4 && 0 <= c && c < 4) {
				swap(st.g[r][c], st.g[slide.first][slide.second]);
				state[tot] = State(cur.g + 1, st.h(), st.hash());
				if (rem.find(state[tot].s) == rem.end()) {
					rem.insert(state[tot].s);
					state[tot].pre = &cur;
					state[tot].op = op[d];
					pq.push(tot++);
				}
				swap(st.g[r][c], st.g[slide.first][slide.second]);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		data.read();
		if (!data.judge()) {
			puts("This puzzle is not solvable.");
		} else {
			solve();
		}
	}

	return 0;
}

