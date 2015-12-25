/*
 * 526 - String Distance and Transform Process
 *
 * edit steps~
 * the input string may contains blank chars
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
#define MAXN 100
#define INS 1
#define DEL 2
#define REP 3
#define OK 4
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN], la, lb;
int pos;

void dfs(int pa, int pb) {
	if (!pa && !pb) {
	} else if (!pa) {
		dfs(pa, pb - 1);
		printf("%d Insert %d,%c\n", dp[pa][pb], pos, b[pb]);
		++pos;
	} else if (!pb) {
		dfs(pa - 1, pb);
		printf("%d Delete %d\n", dp[pa][pb], pos);
	} else if (a[pa] == b[pb]) {
		dfs(pa - 1, pb - 1);
		++pos;
	} else if (dp[pa][pb] == dp[pa - 1][pb - 1] + 1) {
		dfs(pa - 1, pb - 1);
		++pos;
		printf("%d Replace %d,%c\n", dp[pa][pb], pb, b[pb]);
	} else if (dp[pa][pb] == dp[pa - 1][pb] + 1) {
		dfs(pa - 1, pb);
		printf("%d Delete %d\n", dp[pa][pb], pos);
	} else {
		dfs(pa, pb - 1);
		printf("%d Insert %d,%c\n", dp[pa][pb], pos, b[pb]);
		++pos;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	bool first = true;
	while (gets(a+1) && gets(b+1)) {
		if (!first) {
			putchar(10);
		} else {
			first = false;
		}

		la = strlen(a + 1);
		lb = strlen(b + 1);
		for (int i = 0; i < MAXN; ++i) {
			dp[0][i] = dp[i][0] = i;
		}
		for (int i = 1; i <= la; ++i) {
			for (int j = 1; j <= lb; ++j) {
				if (a[i] == b[j])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1],
							dp[i - 1][j])) + 1;
			}
		}

		printf("%d\n", dp[la][lb]);
		pos = 1;
		dfs(la, lb);
	}

	return 0;
}

