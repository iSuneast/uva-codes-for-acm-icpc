/*
 * 10987 - Antifloyd
 *
 * graph theory
 * apsp
 * if the current matrix is not APSP, return false
 * if there exist a node k, which g[i][k]+g[k][j]==g[i][j]
 * then there's no edge between (i, j)  // i!=k && j!=k
 * else there's an edge between (i, j) with weight = g[i][j]
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
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int g[MAXN][MAXN], n;
int dp[MAXN][MAXN];

void process() {
	int add=0;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			bool fade=false;
			for(int k=0; k<n; ++k) {
				if(i!=k && j!=k && g[i][k]+g[k][j]==g[i][j]) {
					fade=true;
					break;
				}
			}

			if(!fade)
				++add;
		}
	}

	printf("%d\n", add);
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			bool fade=false;
			for(int k=0; k<n; ++k) {
				if(i!=k && j!=k && g[i][k]+g[k][j]==g[i][j]) {
					fade=true;
					break;
				}
			}

			if(!fade)
				printf("%d %d %d\n", i+1, j+1, g[i][j]);
		}
	}
}

bool chk() {
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			dp[i][j]=g[i][j];
		}
		g[i][i]=dp[i][i]=0;
	}

	for(int k=0; k<n; ++k) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(dp[i][j]!=g[i][j])
				return false;
		}
	}

	return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	printf("Case #%d:\n", cas);

    	scanf("%d", &n);
    	for(int i=1; i<n; ++i) {
    		for(int j=0; j<i; ++j) {
    			scanf("%d", &g[i][j]);
    			g[j][i]=g[i][j];
    		}
    	}

    	if(!chk()) {
    		puts("Need better measurements.");
    	} else
    		process();

    	putchar(10);
    }

    return 0;
}

