/*
 * 12039 - Goldbach's Cardinality
 *
 * number theory
 * 先筛出10^7的素数,然后对于[low,high]的解既是
 * [0,high/2*2] - [0,(low-1)/2*2]
 * 对与[0,v]的解,我们可以利用两个指针i,j来模拟扫描
 * 一开始j为v/2对应的素数在素数表里面的位置,i=j-1
 * 如果prime[i]+prime[j]>v, --i
 * 答案累加i(素数表为2,3,5...), ++j
 * 每次的维护最坏时间复杂度为素数表大小,故方法虽然较慢,但还是可行的
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
#include <map>
#include <set>
#include <ctime>
#define MAXN 10000000
#define MAXP 664580
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

bool fade[MAXN];
int prime[MAXP], sz;

void init() {
	sz = 0;
	for (int i = 3; i < MAXN; i += 2) {
		if (!fade[i]) {
			prime[sz++] = i;
			for (int j = i + i; j < MAXN; j += i) {
				fade[j] = true;
			}
		}
	}
}

LL calc(int v) {
	int p=lower_bound(prime, prime+sz, v/2)-prime, i=p-1, j=p;
	LL ans=i;
	ans=ans*(ans+1)/2;
	while(j<sz && prime[j]<v) {
		while(i>=0 && prime[i]+prime[j]>v) {
			--i;
		}
		if(i<0)
			break;
		ans+=i+1;
		++j;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	init();
	for (int low, high; scanf("%d %d", &low, &high) != EOF && (low || high);) {
		low = (low + 1) / 2 * 2;
		high = high / 2 * 2;
		printf("%lld\n", calc(high)-calc(low-2));
	}

	return 0;
}

