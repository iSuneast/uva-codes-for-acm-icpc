/*
 * 11968 - In The Airport
 *
 * Ad hoc...
 * a simple problem
 * p.s we'd better use long long instead of double to avoid precision error~
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

LL var[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n, m, k;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d %d", &n, &m, &k);
    	LL s=0;
    	for(int i=0; i<n; ++i) {
    		scanf("%lld", &var[i]);
    		s+=var[i];
    	}

    	LL a, b;
    	LL dis=1e18;
    	for(int i=0; i<m; ++i) {
    		if(abs(var[i]*n-s)<dis) {
    			dis=abs(var[i]*n-s);
    			a=var[i];
    		} else if(abs(var[i]*n-s)==dis) {
    			a=min(a, var[i]);
    		}
    	}

    	dis=1e18;
    	for(int i=m; i<m+k; ++i) {
    		if(abs(var[i]*n-s)<dis) {
    			dis=abs(var[i]*n-s);
    			b=var[i];
    		} else if(abs(var[i]*n-s)==dis) {
    			b=min(b, var[i]);
    		}
    	}

    	printf("Case #%d: %lld %lld\n", cas, a, b);
    }

    return 0;
}

