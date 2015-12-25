/*
 * 11966 - Galactic Bonding
 *
 * union find set
 * check whether two points is near enough
 * if yes, merge them in a union find set
 * at last, try to find out how many different set
 * that's the answer
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
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int fa[MAXN];
struct POINT {
	double x, y;
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	double sqr(double t) {
		return t*t;
	}
	double dis(POINT &t) {
		return sqr(t.x-x)+sqr(t.y-y);
	}
}pnt[MAXN];

int find(int u) {
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

void merge(int a, int b) {
	fa[ find(a) ]=find(b);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n;
    double d;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %lf", &n, &d);
    	d*=d;
    	for(int i=0; i<n; ++i) {
    		fa[i]=i;
    		pnt[i].read();
    		for(int j=0; j<i; ++j) {
    			if(pnt[i].dis( pnt[j] )<=d) {
    				merge(i, j);
    			}
    		}
    	}

    	set<int> key;
    	for(int i=0; i<n; ++i) {
    		key.insert( find(i) );
    	}

    	printf("Case %d: %d\n", cas, key.size());
    }

    return 0;
}

