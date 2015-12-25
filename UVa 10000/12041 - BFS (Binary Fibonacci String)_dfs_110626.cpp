/*
 * 12041 - BFS (Binary Fibonacci String)
 *
 * dfs
 * 简单的递归，必须对整个序列一起考虑，不能一个一个字符考虑
 * BFS(n) = BFS(n-2) + BFS(n-1)
 * 显然，如果[i,j］区间, 有j<= length of BFS(n-2), 则BFS(n)的答案和BFS(n-2)是一样的
 * 又 0 ≤ N, i, j ≤ 2^31 - 1, 所以,其实最大的有效的n不会超过45.
 * 然后就是递归n,处理区间[i,j]
 * n为0时,答案为'0'；n为1时,答案为'1'
 * 如果i<=FIB(n-2)<j, 则转化为n-2,[i, FIB(n-2)]与n-1,[1, j-FIB(n-2)]
 * 如果j<=FIB(n-2), 则转化为n-2,[i, j]
 * 如果FIB(n-2)<i, 则转化为n-1,[i-FIB(n-2), j-FIB(n-2)]
 *
 * dfs树叶子节点为j-i ≤ 10000
 * 还是很快的
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
#define MAXN 50
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

LL fib[MAXN];

void solve(int n, int i, int j) {
	if (n == 0)
		putchar('0');
	else if (n == 1)
		putchar('1');
	else {
		if (i <= fib[n - 2] && fib[n - 2] < j) {
			solve(n - 2, i, fib[n - 2]);
			solve(n - 1, 1, j - fib[n - 2]);
		} else if (fib[n - 2] < i) {
			solve(n - 1, i - fib[n - 2], j - fib[n - 2]);
		} else {
			solve(n - 2, i, j);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	fib[0] = fib[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int dataset;
	scanf("%d", &dataset);
	while (dataset--) {
		int n, i, j;
		scanf("%d %d %d", &n, &i, &j);
		int p;
		for (p = n & 1; p < MAXN; p += 2) {
			if (fib[p] > j)
				break;
		}
		solve(p, i + 1, j + 1);
		putchar(10);
	}

	return 0;
}

