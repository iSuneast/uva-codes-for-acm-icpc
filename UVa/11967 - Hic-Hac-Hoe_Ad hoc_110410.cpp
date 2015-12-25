/*
 * 11967 - Hic-Hac-Hoe
 *
 * Ad hoc...
 * sort the points at first
 * and choose the first un-marked one
 * go UP, RIGHT, UP-RIGHT, DOWN-RIGHT as far as possible
 * if we can go more than K consequence steps return true
 * else mark the direction and the points we have already visit
 * so we at most visit a point 4 times (from 4 different direction )
 * the time is O(NlogN) because the sort operation~
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
#define MAXN 100003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

struct DATA {
	int x, y;
	void read() {
		scanf("%d %d", &x, &y);
	}
	bool operator<(const DATA &t) const {
		if(x==t.x)
			return y<t.y;
		return x<t.x;
	}
	bool operator==(const DATA &t) const {
		return x==t.x && y==t.y;
	}
}data[2][MAXN];
int n, sz[2], k;
bool flag[4][MAXN];
const int dx[]={0, 1, 1, 1}, dy[]={1, 1, 0, -1};

bool chk(DATA cur[MAXN], int sz) {
	sort(cur, cur+sz);
	memset(flag, 0, sizeof(flag));

	for(int i=0; i<sz; ++i) {
		for(int d=0; d<4; ++d) {
			if(flag[d][i])
				continue;
			DATA t=cur[i];
			int cnt=0;
			while(true) {
				int p=lower_bound(cur, cur+sz, t)-cur;
				if(0<=p && p<sz && cur[p]==t) {
					if(++cnt==k)
						return true;
					flag[d][p]=true;

					t.x+=dx[d];
					t.y+=dy[d];
				} else {
					break;
				}
			}
		}
	}

	return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &k);
    	sz[0]=sz[1]=0;
    	for(int i=0; i<n; ++i) {
    		if(i%2==0) {
    			data[0][ sz[0]++ ].read();
    		} else {
    			data[1][ sz[1]++ ].read();
    		}
    	}

    	bool a=chk(data[0], sz[0]);
    	bool b=chk(data[1], sz[1]);

    	printf("Case %d: ", cas);
    	if(a && b) {
    		puts("error");
    	} else if(a || b) {
    		puts(a? "crosses": "noughts");
    	} else
    		puts("none");
    }

    return 0;
}

