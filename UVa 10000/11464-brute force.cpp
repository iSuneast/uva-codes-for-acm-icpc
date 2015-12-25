#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define LOWBIT(v) ((v)&(-(v)))

#define MAXN 20
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int n;
int v[MAXN][MAXN];
int ori[MAXN][MAXN];
int key;

int calc(int i, int j) {
	return v[i-1][j] + v[i][j-1] + v[i][j+1] + v[i+1][j];
}

void dfs(int r, int c, int cur) {
	if(cur >= key) {
		return ;
	} else if(c > n) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				v[i+1][j] = ori[i+1][j];
				if(calc(i, j) & 1) {
					if(i == n || v[i+1][j] == 1) {
						return ;
					}
					v[i+1][j] = 1;
					++cur;
				}
			}
		}
		key = min(key, cur);
		return ;
	}
	if(v[r][c] == 0) {
		v[r][c] = 1;
		dfs(r, c+1, cur+1);
		v[r][c] = 0;
	}
	dfs(r, c+1, cur);
}

int solve() {
	key = 10000;
	dfs(1, 1, 0);
	if(key == 10000) {
		key = -1;
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d", &n);
		memset(v, 0, sizeof(v));
		memset(ori, 0, sizeof(ori));
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				scanf("%d", &v[i][j]);
				ori[i][j] = v[i][j];
			}
		}
		printf("Case %d: %d\n", cas, solve());
	}

	return 0;
}
