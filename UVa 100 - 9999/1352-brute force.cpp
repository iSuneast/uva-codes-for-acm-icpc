#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

#define LOWBIT(v) ((v)&(-(v)))

#define MAXN 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int rotate_left[] = {1, 5, 2, 3, 0 ,4};
int rotate_up[] = {3, 1, 0, 5, 4, 2};
int cube[24][6] = {};

void Rotate(int *cur, int *r) {
	int tmp[6];
	memcpy(tmp, cur, sizeof(tmp));
	for(int i=0; i<6; ++i) {
		cur[i] = r[ tmp[i] ];
	}
}

void Init() {
	for(int i=0, p=0; i<6; ++i) {
		int cur[6] = {0, 1, 2, 3, 4, 5};
		switch(i) {
		case 0:
			Rotate(cur, rotate_up);
			break;
		case 1:
			Rotate(cur, rotate_left);
			Rotate(cur, rotate_up);
			break;
		case 2:
			break;
		case 3:
			Rotate(cur, rotate_up);
			Rotate(cur, rotate_up);
			break;
		case 4:
			Rotate(cur, rotate_left);
			Rotate(cur, rotate_left);
			Rotate(cur, rotate_left);
			Rotate(cur, rotate_up);
			break;
		case 5:
			Rotate(cur, rotate_up);
			Rotate(cur, rotate_up);
			Rotate(cur, rotate_up);
			break;
		}
		for(int j=0; j<4; ++j, ++p) {
			memcpy(&cube[p][0], cur, sizeof(cur));
			Rotate(cur, rotate_left);
		}
	}
}

int n;
map<string, int> rem;
int c[4][6];
int nc[4][6];
int key;

void dfs(int dep) {
	if(dep == n) {
		int ret = 0;
		for(int i=0; i<6; ++i) {
			int cnt = 0;
			for(int j=0; j<n; ++j) {
				int ok = 0;
				for(int k=0; k<n; ++k) {
					if(nc[j][i] == nc[k][i]) {
						++ok;
					}
				}
				cnt = max(cnt, ok);
			}
			ret += n-cnt;
		}
		key = min(key, ret);
		return ;
	}
	for(int i=0; i<24; ++i) {
		for(int j=0; j<6; ++j) {
			nc[dep][j] = c[dep][ cube[i][j] ];
		}
		dfs(dep+1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	Init();
	while(scanf("%d", &n) != EOF && n) {
		rem.clear();
		char col[30];
		int col_n = 0;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<6; ++j) {
				scanf("%s", col);
				if(rem.find(col) == rem.end()) {
					rem[col] = col_n++;
				}
				c[i][j] = rem[col];
			}
		}

		for(int i=0; i<6; ++i) {
			nc[0][i] = c[0][i];
		}

		key = 1e9;
		dfs(1);
		printf("%d\n", key);
	}

	return 0;
}
