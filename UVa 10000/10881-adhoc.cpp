#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define LOWBIT(v) ((v)&(-(v)))

#define MAXN 10003
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

struct Data {
	int p;
	int r;
	int idx;
}data[MAXN];
map<int, int> pos;
int nidx[MAXN];

bool cmp1(const Data &a, const Data &b) {
	if(a.p != b.p) {
		return a.p < b.p;
	}
	return a.r < b.r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		int l, t , n;
		scanf("%d %d %d", &l, &t, &n);
		char dir;
		for(int i=0; i<n; ++i) {
			scanf("%d %c", &data[i].p, &dir);
			data[i].r = (dir == 'R')?1:-1;
			data[i].idx = i;
		}
		sort(data, data+n, cmp1);

		for(int i=0; i<n; ++i) {
			nidx[ data[i].idx ] = i;
		}
		
		pos.clear();
		for(int i=0; i<n; ++i) {
			data[i].p += t*data[i].r;
			pos[ data[i].p ]++;
		}
		sort(data, data+n, cmp1);
		
		printf("Case #%d:\n", cas);
		for(int i=0; i<n; ++i) {
			Data &cur = data[ nidx[i] ];
			if(cur.p < 0 || cur.p > l) {
				puts("Fell off");
			} else {
				if(pos[cur.p] != 1) {
					printf("%d Turning\n", cur.p);
				} else {
					printf("%d %c\n", cur.p, cur.r==1? 'R': 'L');
				}
			}
		}
		putchar(10);
	}

	return 0;
}
