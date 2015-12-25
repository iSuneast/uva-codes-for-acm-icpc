/*
 * 11472 - Beautiful Numbers
 *
 * dp...
 *
 * we can use array dp[digitPos][currentDigit][state] to manage the state
 * initialization dp[0][i][1<<i]=1    0<i<n
 * for digitPos from 1 to m-1
 *    for currentDigit from 0 to n-1
 *        for state from 0 to (1<<n)-1
 *              dp[digitPos][ currentDigit ][ MERGE(i, state) ]
 *           += dp[digitPos-1][ currentDigit+1 ][state]
 *            + dp[digitPos-1][ currentDigit-1 ][state]
 *
 * the time complex is O(m * n * 2^n)
 *
 * I got WA because I forget to %MOD when calculate dp[][][] array...
 * really a silly bug...
 * poor :(
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
#define MAXN 10
#define MAXM 103
#define MAX_S (1<<MAXN)
#define MOD 1000000007LL
#define MERGE(i,j) ((1<<(i))|j)
#define ALL(n) ((1<<(n))-1)
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;

LL dp[MAXM][MAXN][MAX_S];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset, n, m;
    scanf("%d", &dataset);
    while(dataset--) {
    	memset(dp, 0, sizeof(dp));
    	scanf("%d%d", &n, &m);
    	int state=ALL(n);
    	LL key=0;

    	for(int i=1; i<n; ++i) {
    		dp[0][i][ MERGE(i, 0) ]=1;
    	}

    	for(int p=1; p<m; ++p) {
    		for(int i=0; i<n; ++i) {
    			for(int s=0; s<=state; ++s) {
        			if(i)
        				dp[p][i][ MERGE(i,s) ]=(dp[p][i][ MERGE(i,s) ]+dp[p-1][i-1][s])%MOD;
        			if(i+1<n)
        				dp[p][i][ MERGE(i,s) ]=(dp[p][i][ MERGE(i,s) ]+dp[p-1][i+1][s])%MOD;
    			}
   				key = (key+dp[p][i][state])%MOD;
    		}
    	}

    	printf("%lld\n", key);
    }

    return 0;
}

