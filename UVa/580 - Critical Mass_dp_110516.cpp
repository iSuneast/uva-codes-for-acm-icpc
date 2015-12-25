/*
 * 580 - Critical Mass
 *
 * dp
 * total stack method is 2^n
 * safe stack the last few ones should be
 * L LU LUU, so for length n
 * dp[n]=dp[n-1]+dp[n-2]+dp[n-3]
 * dp[1]=2  //L U
 * dp[2]=4  //LL LU UL UU
 * dp[3]=8  // except UUU
 * ....
 * unsafe stack is 2^n-dp[n], it's the answer we need~
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
#define MAXN 63
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

LL dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	dp[1]=1<<1;
	dp[2]=1<<2;
	dp[3]=(1<<3)-1;
	for(int i=4; i<MAXN; ++i) {
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	int n;
	while(scanf("%d", &n)==1 && n) {
		printf("%lld\n", (LL(1)<<n)-dp[n]);
	}

	return 0;
}

