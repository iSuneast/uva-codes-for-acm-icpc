/*
 * 11970 - Lucky Numbers
 *
 * brute force
 *
 * set T = sqrt(n-x)
 * so x = n-T*T
 * then x / sqrt(n-x) = (n-T*T) / T
 * T*T <= n, so we just need O(sqrt(n)) time to find out T
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
#define MAXN 31623
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int sqr[MAXN];

void init() {
	for(int i=1; i<MAXN; ++i) {
		sqr[i]=i*i;
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
    	printf("Case %d:", cas);
    	for(int t=MAXN-1; t>=1; --t) {
    		int x=n-sqr[t];
    		if(x<=0)
    			continue;
    		if(x%t==0) {
    			printf(" %d", x);
    		}
    	}

    	putchar(10);
    }

    return 0;
}

