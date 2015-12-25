/*
 * 416 - LED Test
 *
 * simulation
 *
 * "N, with value greater than zero (0) and less than eleven (11)."
 * so the count down sequence can't be wrap~
 *
 * enum the start of the count down sequence, and check if the input is valid
 * the LED can be break during the test, we should mark the broken LED and never use it again
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
#define SZ 10
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

const char dig[][10] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY",
		"YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY" };
char chk[20][10];
bool fade[10];
int n;

bool CHK(int s) {
	memset(fade, 0, sizeof(fade));
	for (int i = 0; i < n; ++i) {
		int p = (s - i + SZ*10) % SZ;

		for (int j = 0; j < 7; ++j) {
			if (chk[i][j] == 'Y' && (dig[p][j]=='N' || fade[j])) {
				return false;
			} else if(dig[p][j]=='Y' && chk[i][j]=='N') {
				fade[j]=true;
			}
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 7; ++j) {
				scanf(" %c", &chk[i][j]);
			}
		}

		bool ok = false;
		for (int s = n-1; s < 10; ++s) {
			if (CHK(s)) {
				ok = true;
				break;
			}
		}

		puts(ok ? "MATCH" : "MISMATCH");
	}

	return 0;
}

