/*
 * 11960 - Divisor Game
 *
 * number theory
 * sieve the prime table and calculate the number of factors at the same time
 * we can initialization the answer in O(NlogN) time
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
#define MAXN 1000001
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int fade[MAXN], dp[MAXN];

void init() {
	for(int i=2; i<MAXN; ++i) {
		if(fade[i])
			continue;
		for(int j=i+i; j<MAXN; j+=i) {
			if(!fade[j]) {
				fade[j]=1;
			}
			int t=j, cnt=1;
			while(t%i==0) {
				t/=i;
				++cnt;
			}
			fade[j]*=cnt;
		}
	}

	for(int i=1; i<MAXN; ++i) {
		dp[i]=i;
		if( fade[ dp[i-1] ] > fade[ dp[i] ] ) {
			dp[i]=dp[i-1];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    init();

    int dataset, n;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d", &n);
    	printf("%d\n", dp[n]);
    }

    return 0;
}

