/*
 * 11782 - Optimal Cut
 *
 * dp
 * 如果保存说有解的话需要[20][1<<20]的空间，当然不行
 * 其实不需要保存节点，由于题目给的是前序遍历
 * 就可以dfs建树，只需要用到n的线性栈空间
 *
 * “your program must find the optimal cut that includes no more than K nodes“
 * 坑爹。。。
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
#define MAXN 20
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;
const LL negInf = -1048576001;

struct Data {
	int dp[MAXN + 1];
	Data() {
		for (int i = 0; i <= MAXN; ++i) {
			dp[i] = negInf;
		}
	}
};
int n, k;

Data dfs(int dep) {
	if (dep > n) {
		return Data();
	}
	Data cur;
	scanf("%d", &cur.dp[1]);
	Data ls = dfs(dep + 1);
	Data rs = dfs(dep + 1);
	for (int c = 2; c <= k; ++c) {
		for (int i = 1; i < c; ++i) {
			if (ls.dp[i] != negInf && rs.dp[c - i] != negInf)
				cur.dp[c] = max(cur.dp[c], ls.dp[i] + rs.dp[c - i]);
		}
	}
	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n != -1) {
		scanf("%d", &k);
		Data final = dfs(0);
		int key = negInf;
		for (int i = 1; i <= k; ++i) {
			key = max(key, final.dp[i]);
		}
		printf("%d\n", key);
	}

	return 0;
}

