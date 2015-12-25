/*
 * 10313 - Pay the Price
 *
 * dp
 * classical knapsack problem
 * for each change D, money M, we have N coins
 * dp[M][N]+=dp[M-D][N-1]
 * O(n^3) time~
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
#define MAXN 301
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

LL dp[MAXN][MAXN], sum[MAXN][MAXN];

void init() {
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for(int d=1; d<MAXN; ++d) {
		for(int m=d; m<MAXN; ++m) {
			for(int n=1; n<=m; ++n) {
				dp[m][n]+=dp[m-d][n-1];
			}
		}
	}

	sum[0][0]=1;
	for(int m=1; m<MAXN; ++m) {
		sum[m][0]=0;
		for(int n=1; n<=m; ++n) {
			sum[m][n]=dp[m][n]+sum[m][n-1];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    init();
    int n;
    vector<int> l;
    char buf[100];
    while(scanf("%d", &n)!=EOF) {
    	gets(buf);
    	l.clear();
    	for(char *token=strtok(buf, " "); token; token=strtok(NULL, " ")) {
    		l.push_back( atol(token) );
    	}
    	if(!l.size()) {
    		printf("%lld\n", sum[n][n]);
    	} else if(l.size()==1) {
    		l[0]=min(l[0], n);
    		printf("%lld\n", sum[n][ l[0] ]);
    	} else {
    		if(l[0]>n) {
    			puts("0");
    		} else if(n==0 && l[0]==0){
    			puts("1");
    		} else {
    			l[0]=max(l[0],1);
        		l[1]=min(l[1], n);
        		printf("%lld\n", sum[n][ l[1] ] - sum[n][ l[0]-1 ]);
    		}
    	}
    }

    return 0;
}

