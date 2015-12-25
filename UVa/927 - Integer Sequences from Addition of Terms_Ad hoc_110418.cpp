/*
 * 927 - Integer Sequences from Addition of Terms
 *
 * Ad hoc...
 * just calculate the answer using the format in the problem description
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
#define MAXN 33
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int an, var[MAXN], d, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d", &an);
    	for(int i=0; i<=an; ++i) {
    		scanf("%d", &var[i]);
    	}
    	scanf("%d %d", &d, &k);
    	LL final, cur=0;
    	for(int n=1; ; ++n) {
    		final=0;
    		for(int i=an; i>=0; --i) {
    			final=final*n+var[i];
    		}
    		cur+=n*d;
    		if(cur>=k)
    			break;
    	}

    	printf("%lld\n", final);
    }

    return 0;
}

