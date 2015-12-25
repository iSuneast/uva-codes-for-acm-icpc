/*
 * 12001 - UVa Panel Discussion
 *
 * combination math~
 * the problem is quite straight forward combination math problem
 * we should count sort all the people first
 * and then try to group them according to the law described by the problem
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
#define MAXN 51
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, m, cnt[MAXN], sum[MAXN];
LL dp[301][5];

LL C(const int &a, const int &b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	LL &key = dp[a][b];
	if (a < b)
		return key = 0;
	key = 1;
	for (int i = a - b + 1; i <= a; ++i) {
		key *= i;
	}
	for (int i = 2; i <= b; ++i) {
		key /= i;
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	memset(dp, -1, sizeof(dp));
	int v;
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v);
			cnt[v]++;
		}
		int sz = 1;
		sum[0] = 0;
		for (int i = 1; i < MAXN; ++i) {
			if (cnt[i]) {
				cnt[sz] = cnt[i];
				sum[sz] = sum[sz - 1] + cnt[sz];
				++sz;
			}
		}

		LL key0=0, key1=0;
		for(int i=1; i<sz; ++i) {
			key0+=C(cnt[i], 3);
			key1+=C(cnt[i],4);

			for(int j=i+1; j<sz; ++j) {
				key0+=cnt[i]*cnt[j]*(n-sum[j]);
				key1+=C(cnt[i],3)*cnt[j];
				key1+=C(cnt[j],3)*cnt[i];

				for(int k=j+1; k<sz; ++k) {
					key1+=C(cnt[i],2)*cnt[j]*cnt[k];
					key1+=C(cnt[j],2)*cnt[i]*cnt[k];
					key1+=C(cnt[k],2)*cnt[j]*cnt[i];
					key1+=cnt[i]*cnt[j]*cnt[k]*(n-sum[k]);
				}
			}
		}

		printf("%lld %lld\n", key0, key1);
	}

	return 0;
}

