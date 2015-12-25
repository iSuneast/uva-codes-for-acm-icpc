/*
 * 12294 - RPG battles
 *
 * dp
 * 考虑最简单的情况
 * 可以如下方式保存状态 dp[n][p][w1][w2]
 * 代表到达第n关时,有p的力量,剩下w1个stronger药水,w2个double药水
 *
 * 很显然由p2<=100, 力量p只需要保存至101就够了
 * w1为+1药水个数, 可以贪心得知 (p+w1)*2>p*2+w1, 即越早用掉越好, 故w1是可以省略的
 * 最后, w2至多累计7个就够了(2^7=128更大已经没必要的)
 * 所以最终需要的空间为dp[n<=1000][p<=101][w2<=7]
 *
 * 状态转移, 枚举当前状态, 可以O(1)得到之前的状态, 故时间复杂读为
 * O(n*MAXP*MAXW) ~ O(10^6)
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
#define MAXN 1003
#define MAXP 102
#define MAXW 8
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

double dp[MAXN][MAXP][MAXW];
int n, p;

void ChkMin(double &a, const double &b) {
	if (a > b)
		a = b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d %d", &n, &p) != EOF && (n || p)) {
		for (int j = 0; j < MAXP; ++j) {
			for (int k = 0; k < MAXW; ++k) {
				dp[0][j][k] = 1e20;
			}
		}
		dp[0][p][0] = 0;

		int p1, p2, t1, t2, w1, w2;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < MAXP; ++j) {
				for (int k = 0; k < MAXW; ++k) {
					dp[i][j][k] = 1e20;
				}
			}
			scanf("%d %d %d %d %d %d", &p1, &p2, &t1, &t2, &w1, &w2);
			for (int p = p1; p < MAXP; ++p) {
				double t = t2;
				if (p <= p2)
					t += (t1 - t2) * (p2 - p) / (double) (p2 - p1);
				for (int k = 0; k < MAXW; ++k) {
					ChkMin(dp[i][min(MAXP - 1, p + w1)][min(MAXW - 1, k + w2)],
							dp[i - 1][p][k] + t);
				}
				for (int k = MAXW - 1; k > 0; --k) {
					ChkMin(dp[i][min(MAXP - 1, p * 2)][k - 1], dp[i][p][k]);
				}
			}
		}
		double key = 1e20;
		for (int j = 0; j < MAXP; ++j) {
			for (int k = 0; k < MAXW; ++k) {
				ChkMin(key, dp[n][j][k]);
			}
		}
		if (key == 1e20) {
			puts("Impossible");
		} else {
			printf("%.2lf\n", key);
		}
	}

	return 0;
}

