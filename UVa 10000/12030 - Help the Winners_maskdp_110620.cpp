/*
 * 12030 - Help the Winners
 *
 * mask dp
 * 经过简单的观察便可以找到规律了
 * 朴素的做法是n!的匹配,然后分别计算两种合法解的方案数
 * 但是复杂度显然太高,
 * 又暴力匹配的情况下,我们只关心有哪些已经匹配,哪些没有匹配而与实际匹配情况无关
 * 故可以用状态压缩的动态规划解法
 * 0: 0,1->0 2->2
 * 1: 0->0 1->1 2->2
 * 2: 0,1,2->2
 * "->"代表旧状态的值累积到新的状态的值
 * 如上三种情况难在充分考虑,不遗漏,结论还是蛮显然的
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
#define MAXN 15
#define INSIDE(i, j) ((i)&(1<<(j)))
#define MERGE(i, j) ((i)|(1<<(j)))
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int var[MAXN][MAXN], n;
LL dp[3][1 << MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &var[i][j]);
			}
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			dp[var[0][i]][MERGE(0,i)] = 1;
		}

		int all = (1 << n) - 1;
		for (int i = 1; i <= all; ++i) {
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				if (INSIDE(i, j))
					++cur;
			}

			for (int j = 0; j < n; ++j) {
				if (!INSIDE(i, j)) {
					dp[2][MERGE(i,j)] += dp[2][i];
					if (var[cur][j] == 0) {
						dp[0][MERGE(i,j)] += dp[0][i] + dp[1][i];
					} else if (var[cur][j] == 1) {
						dp[0][MERGE(i,j)] += dp[0][i];
						dp[1][MERGE(i,j)] += dp[1][i];
					} else {
						dp[2][MERGE(i,j)] += dp[0][i] + dp[1][i];
					}
				}
			}
		}

		printf("Case %d: %lld\n", cas, dp[1][all] + dp[2][all]);
	}

	return 0;
}

