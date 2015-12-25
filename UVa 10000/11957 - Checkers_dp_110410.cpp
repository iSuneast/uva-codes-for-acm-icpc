/*
 * 11957 - Checkers
 *
 * dp
 * a simple dynamic programming problem
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
#define MAXN 105
#define MOD 1000007
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

char g[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d", &n);
    	memset(g, 0, sizeof(g));
    	int r, c;
    	for(int i=1; i<=n; ++i) {
    		scanf("%s", g[i]+1);
    		for(int j=1; j<=n; ++j) {
    			if(g[i][j]=='W') {
    				r=i, c=j;
    			}
    		}
    	}

    	memset(dp, 0, sizeof(dp));
    	dp[r][c]=1;	g[r][c]='.';
    	for(int i=r-1; i>0; --i) {
    		for(int j=1; j<=n; ++j) {
    			if(g[i][j]=='B')
    				continue;

    			if(g[i+1][j-1]=='B') {
    				if(j-2>0)
    					dp[i][j]+=dp[i+2][j-2];
    			} else {
    				dp[i][j]+=dp[i+1][j-1];
    			}

    			if(g[i+1][j+1]=='B') {
    				dp[i][j]+=dp[i+2][j+2];
    			} else {
    				dp[i][j]+=dp[i+1][j+1];
    			}

    			dp[i][j]%=MOD;
    		}
    	}

    	int key=0;
    	for(int i=1; i<=n; ++i) {
    		key+=dp[1][i];
    		key%=MOD;
    	}

    	printf("Case %d: %d\n", cas, key);
    }

    return 0;
}

