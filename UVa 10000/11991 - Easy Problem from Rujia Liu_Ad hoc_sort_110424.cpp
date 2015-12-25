/*
 * 11991 - Easy Problem from Rujia Liu?
 *
 * Ad hoc...
 * make the pairs (Integer, Position)
 * sort the pairs, and then b-search will do
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

int n, m;
pii var[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while(scanf("%d %d", &n, &m)!=EOF) {
    	for(int i=0; i<n; ++i) {
    		scanf("%d", &var[i].first);
    		var[i].second=i+1;
    	}
    	sort(var, var+n);
    	for(int i=0, v, k; i<m; ++i) {
    		scanf("%d %d", &k, &v);
    		int s=lower_bound(var, var+n, make_pair(v, 0))-var;
    		int e=upper_bound(var, var+n, make_pair(v, INF))-var;
    		if(e-s<k)
    			puts("0");
    		else
    			printf("%d\n", var[s+k-1].second);
    	}
    }

    return 0;
}

