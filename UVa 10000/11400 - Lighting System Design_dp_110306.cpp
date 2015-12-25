/*
 * 11400 - Lighting System Design
 *
 * dp...
 * there is a cool O(n^2) solution
 * if we have three light
 *    v1 k1 c1 l1
 *    v2 k2 c2 l2
 *    v3 k3 c3 l3	(v1 < v2 < v3)
 *
 * Case 1:
 * if c1 >= c2, we can always merge light1 with light2 to save money
 *
 * Case 2:
 * if c1 < c2, but k1+c1*l1 + k2+c2*l2 > k2+c2*(l1+l2)
 *      we can still choose to merger c1 with c2 ?
 *      (when light2 is the last, it's true.)
 *      What about other case?
 *
 * so in this case, we have to decide whether light1 should be merge
 *     with light2 or light3
 * Guess 1: if we merge light1 with light3, and keep light2 alone, we get
 *    format1 = k3 + c3*(l1+l3) + k2 + c2*l2
 * Guess 2: if we merge light1 with light2, and keep light3 away, we get
 *    format2 = k3 + c3*l3 + k2 + c2*(l1+l2)
 *
 * if Guess 1 is truth, we'll have
 *      format1 <= format2
 *  =>  k3 + c3*(l1+l3) + k2 + c2*l2 <= k3 + c3*l3 + k2 + c2*(l1+l2)
 *  =>  c3 <= c2
 *  according to "Case 1", we know if c3 <= c2,
 *      we can merge light2 with light3 to gain a better solution...
 *
 * so, for this case, in conclusion, we only have three choice:
 * Choice 1: merger light1 with light2 and keep light3 alone
 * Choice 2: merger both light1 and light2 with light3
 * Choice 3: keep all three alone
 * Yes!!! the lights are always being merged continuous...
 *
 * really cool result, isn't?
 * --------------------------------------------------------------
 * solution:
 * use dp[j] to represent the best answer of section [1,j]
 * dp[i] = Min( dp[j] + SumOfLightNum[j+1,i] ) 	  # j<i
 *
 * happy coding~
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct DATA {
	int v, k, c, l;
	bool operator<(const DATA &t) const {
		return v<t.v;
	}
}data[MAXN];

int n, dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d", &n)!=EOF && n) {
    	for(int i=0; i<n; ++i) {
    		scanf("%d %d %d %d", &data[i].v, &data[i].k, &data[i].c, &data[i].l);
    		dp[i]=INF;
    	}
    	sort(data, data+n);
    	dp[0]=data[0].k + data[0].c*data[0].l;

    	for(int i=1; i<n; ++i) {
    		int add=data[i].l;

    		for(int j=i-1; j>=0; --j) {
    			dp[i]=min(dp[i], dp[j]+ data[i].k + data[i].c*add);
    			add+=data[j].l;
    		}

    		dp[i]=min(dp[i], data[i].k + data[i].c*add);
    	}

    	printf("%d\n", dp[n-1]);
    }

    return 0;
}

