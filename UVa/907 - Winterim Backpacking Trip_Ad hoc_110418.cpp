/*
 * 907 - Winterim Backpacking Trip
 *
 * Ad hoc...
 * be-search the answer the greedy check whether the answer is valid
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
#define MAXN 603
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int var[MAXN], n, k;

bool ok(int key) {
	int cur=0, day=0;
	for(int i=0; i<=n; ++i) {
		if(cur+var[i]>key) {
			cur=0;
			++day;
		}
		cur+=var[i];
	}

	return day<=k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d %d", &n, &k)!=EOF) {
    	int bgn=0, end=0;
    	for(int i=0; i<=n; ++i) {
    		scanf("%d", &var[i]);
    		end+=var[i];
    		bgn=max(bgn, var[i]);
    	}

    	while(bgn<=end) {
    		int mid=(bgn+end)>>1;
    		if(ok(mid)) {
    			end=mid-1;
    		} else
    			bgn=mid+1;
    	}

    	printf("%d\n", bgn);
    }

    return 0;
}

