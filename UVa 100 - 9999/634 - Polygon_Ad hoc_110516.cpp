/*
 * 634 - Polygon
 *
 * Ad hoc...
 * three case:
 * the point lies in the edge of the polygon
 * the point is inside the polygon
 * the point is outside the polygon
 *
 * for case 2,3 we can just count
 * how many segments lies in the left side of the point
 * if it's odd, the answer is "T"
 * otherwise, "F"
 * point (x, y)
 * segment points (sx, sy), (ex, ey)
 * here is "left side" if and only if sx==ex && sx<x && min(sy, ey)<=y<=max(sy,ey)
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
#define MAXN 1003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

pii pnt[MAXN], p;
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while(scanf("%d", &n)==1 && n) {
		for(int i=0; i<n; ++i) {
			scanf("%d %d", &pnt[i].first, &pnt[i].second);
		}
		pnt[n]=pnt[0];
		scanf("%d %d", &p.first, &p.second);
		bool ok=false;
		for(int i=0; i<n; ++i) {
			if(pnt[i].first==pnt[i+1].first) {
				int u=max(pnt[i].second, pnt[i+1].second);
				int d=min(pnt[i].second, pnt[i+1].second);
				if(p.first==pnt[i].first) {
					if(d<=p.second && p.second<=u) {
						ok=true;
						break;
					}
				} else {
					if(d<=p.second && p.second<=u && p.first>pnt[i].first) {
						ok=!ok;
					}
				}
			} else {
				int l=min(pnt[i].first, pnt[i+1].first);
				int r=max(pnt[i].first, pnt[i+1].first);
				if(p.second==pnt[i].second) {
					if(l<=p.first && p.first<=r) {
						ok=true;
						break;
					}
				}
			}
		}
		puts(ok? "T": "F");
	}

	return 0;
}

