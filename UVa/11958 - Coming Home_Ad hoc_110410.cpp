/*
 * 11958 - Coming Home
 *
 * Ad hoc
 * be careful when the bus arrive time is early than current time
 * ( consider late in mid-night )
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
#define MAXN
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	int n, h, m, key=INF, cur, t;
    	scanf("%d %d%*c%d", &n, &h, &m);
    	cur=h*60+m;
    	for(int i=0; i<n; ++i) {
    		scanf("%d%*c%d %d", &h, &m, &t);
    		int d=h*60+m-cur;
    		if(d<0)
    			d+=60*24;
    		t+=d;

    		key=min(key, t);
    	}

    	printf("Case %d: %d\n", cas, key);
    }

    return 0;
}

