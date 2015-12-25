/*
 * 12032 - The Monkey and the Oiled Bamboo
 *
 * b-search
 * 二分答案即可
 * 题目有个不算trick的trick
 * 一开始人处在0,但是楼梯高度不为零
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
#define MAXN 100003
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int r[MAXN], n;

bool ok(int key) {
	for(int i=1; i<=n; ++i) {
		int d=r[i]-r[i-1];
		if(d>key)
			return false;
		else if(d==key)
			--key;
	}
	return true;
}

int solve() {
	int bgn=0, end=r[n];
	while(bgn<=end) {
		int mid=(bgn+end)>>1;
		if(ok(mid)) {
			end=mid-1;
		} else {
			bgn=mid+1;
		}
	}
	return bgn;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d", &n);
		r[0]=0;
		for(int i=1; i<=n; ++i) {
			scanf("%d", &r[i]);
		}
		printf("Case %d: %d\n", cas, solve());
	}

	return 0;
}

