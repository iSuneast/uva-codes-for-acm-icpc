/*
 * 983 - Localized Summing for Blurring
 *
 * dp...
 * 2d matrix sum
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

int dp[MAXN][MAXN], n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    bool first=true;
    while(scanf("%d %d", &n, &m)!=EOF) {
    	if(!first)
    		putchar(10);
    	first=false;

    	memset(dp, 0, sizeof(dp));
    	for(int i=n; i; --i) {
    		for(int j=1; j<=n; ++j) {
    			scanf("%d", &dp[i][j]);
    		}
    	}

    	for(int i=n; i; --i) {
    		for(int j=1; j<=n; ++j) {
    			dp[i][j]+=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
    		}
    	}

    	int p=n-m+1;
    	LL sum=0;
    	for(int i=p; i; --i) {
    		for(int j=m; j<=n; ++j) {
    			int key=dp[i][j]-dp[i][j-m]-dp[i+m][j]+dp[i+m][j-m];
    			printf("%d\n", key);
    			sum+=key;
    		}
    	}

    	printf("%lld\n", sum);
    }

    return 0;
}

