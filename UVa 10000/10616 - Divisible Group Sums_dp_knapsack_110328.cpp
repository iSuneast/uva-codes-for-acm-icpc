/*
 * 10616 - Divisible Group Sums
 *
 * dp
 * knapsack...
 * "Each of the next N lines contains one 32 bit signed integer."
 * Yes! The integer can be negative :(
 * nothing more tricks
 *
 * just a simple knapsack problem
 * which we can only select M things from all the N things
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
#define MAXN 23
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int var[203], d, m, n;
LL dp[MAXN][MAXN];

void process() {
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for(int i=0; i<n; ++i) {
		int t=(var[i]%d+d)%d;
		for(int k=m-1; k>=0; --k) {
			for(int j=0; j<d; ++j) {
				dp[k+1][ (j+t)%d ] += dp[k][j];
			}
		}
	}

	printf("%lld\n", dp[m][0]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    for(int cas=1, query; scanf("%d %d", &n, &query)!=EOF && (n||query); ++cas) {
    	for(int i=0; i<n; ++i) {
    		scanf("%d", &var[i]);
    	}

    	printf("SET %d:\n", cas);
    	for(int q=1; q<=query; ++q) {
    		scanf("%d %d", &d, &m);
    		printf("QUERY %d: ", q);
    		process();
    	}
    }

    return 0;
}

