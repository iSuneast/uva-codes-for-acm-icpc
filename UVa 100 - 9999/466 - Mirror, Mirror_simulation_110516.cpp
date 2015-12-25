/*
 * 466 - Mirror, Mirror
 *
 * simulation
 * just simulation~
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
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define MAXN 10
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n;
struct Mirror {
	char c[MAXN][MAXN];
	bool operator==(const Mirror &t) const {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				if(c[i][j]!=t.c[i][j])
					return false;
			}
		}
		return true;
	}
	Mirror rotate() {
		Mirror t;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				t.c[i][j]=c[n-1-j][i];
			}
		}
		return t;
	}

	Mirror reflect() {
		Mirror t;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				t.c[i][j]=c[n-1-i][j];
			}
		}
		return t;
	}
}s, e;

const char *key[]={
		"preserved",
		"rotated 90 degrees",
		"rotated 180 degrees",
		"rotated 270 degrees",
		"reflected vertically",
		"reflected vertically and rotated 90 degrees",
		"reflected vertically and rotated 180 degrees",
		"reflected vertically and rotated 270 degrees",
		"improperly transformed"
};

int chk() {
	if(s==e)
		return 0;
	Mirror cur=s;
	int key=1;
	while(key<4) {
		cur=cur.rotate();
		if(cur==e)
			return key;
		++key;
	}

	cur=s.reflect();
	if(cur==e)
		return key;
	++key;

	while(key<8) {
		cur=cur.rotate();
		if(cur==e)
			return key;
		++key;
	}

	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	for(int cas=1; scanf("%d", &n)!=EOF; ++cas) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				scanf(" %c", &s.c[i][j]);
			}
			for(int j=0; j<n; ++j) {
				scanf(" %c", &e.c[i][j]);
			}
		}

		printf("Pattern %d was %s.\n", cas, key[chk()]);
	}

	return 0;
}

