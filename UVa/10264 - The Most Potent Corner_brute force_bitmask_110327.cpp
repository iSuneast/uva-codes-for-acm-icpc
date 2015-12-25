/*
 * 10264 - The Most Potent Corner
 *
 * brute force
 * corner_i's neighbor are (corner_i^(1<<j))  // 0<=j<n
 * so we just need O(NlogN) time to solve this problem
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
#define MAXN 15
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int var[1<<MAXN], sum[1<<MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n;
    while(scanf("%d", &n)!=EOF) {
    	int sz=(1<<n);
    	for(int i=0; i<sz; ++i) {
    		scanf("%d", &var[i]);
    	}

    	for(int i=0; i<sz; ++i) {
    		sum[i]=0;
    		for(int j=0; j<n; ++j) {
    			sum[i]+=var[ i^(1<<j) ];
    		}
    	}

    	int key=0;
    	for(int i=0; i<sz; ++i) {
    		for(int j=0; j<n; ++j) {
    			ChkMax(key, sum[i]+sum[ i^(1<<j) ]);
    		}
    	}

    	printf("%d\n", key);
    }

    return 0;
}

