/*
 * 957 - Popes
 *
 * Ad hoc...
 * calculate the maximum segment length of the given sequence~
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

int var[MAXN], y, p;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d %d", &y, &p)!=EOF) {
    	for(int i=0; i<p; ++i) {
    		scanf("%d", &var[i]);
    	}
    	sort(var, var+p);
    	int key=0, s=0, e=0;
    	for(int i=0; i<p; ++i) {
    		int t=upper_bound(var, var+p, var[i]+y-1)-var;
    		if(t-i>key) {
    			key=t-i;
    			s=var[i];
    			e=var[t-1];
    		}
    	}

    	printf("%d %d %d\n", key, s, e);
    }

    return 0;
}

