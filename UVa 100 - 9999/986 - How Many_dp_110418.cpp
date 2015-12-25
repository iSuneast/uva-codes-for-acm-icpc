/*
 * 986 - How Many?
 *
 * dp...
 * simple dp problem
 * dp[2*n][n][r][2] // x, y, peak, 0-UP || 1-DOWN
 * dp[0][0][0][0]=1
 * the answer is dp[2*n][0][r][1]
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

int dp[46][23][23][2];	// x, y, peaks, 0-UP || 1-DOWN
int n, r, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d %d %d", &n, &r, &k)!=EOF) {
    	memset(dp, 0, sizeof(dp));
    	dp[0][0][0][0]=1;

    	for(int x=1; x<=2*n; ++x) {
    		for(int y=0; y<=n; ++y) {
    			for(int i=0; i<=r; ++i) {
    				if(y)
    					dp[x][y][i][0]+=dp[x-1][y-1][i][0]+dp[x-1][y-1][i][1];
    				dp[x][y][i][1]+=dp[x-1][y+1][i][1];
    				if(y+1==k)
    					dp[x][y][i+1][1]+=dp[x-1][y+1][i][0];
    				else
    					dp[x][y][i][1]+=dp[x-1][y+1][i][0];
    			}
    		}
    	}

    	printf("%d\n", dp[2*n][0][r][1]);
    }

    return 0;
}

