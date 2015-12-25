/*
 * 10174 - Couple-Bachelor-Spinster Numbers.
 *
 * number theory~
 * x*x-y*y = (x+y)*(x-y) = N
 * a = x+y, b = x-y, so
 * a*b = N
 * x = (a+b)/2, y = (a-b)/2
 * case 1: O(sqrtN) to find valid a && b then calculate x, y
 * case 2: we know N = x*x-y*y = (a+b)*(a+b)/4 - (a-b)*(a-b)/4
 *   so N % 4 ==0 , we just need to count how many number in [n1, n2]%4==0
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
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	char buf[100];
	int x, y;
	while (gets(buf)) {
		bool chk = false, rev = false;
		switch (sscanf(buf, "%d %d", &x, &y)) {
		case 1:
			if (x == 0) {
				puts("0 0");
				break;
			}
			if (x < 0) {
				x = -x;
				rev = true;
			}
			for (LL i = 1; i * i <= x; ++i) {
				if(x%i)
					continue;
				int a = i, b = x / i;
				if ((a + b) % 2 == 0) {
					if (!rev)
						printf("%d %d\n", (a + b) / 2, (b - a) / 2);
					else
						printf("%d %d\n", (b - a) / 2, (a + b) / 2);
					chk = true;
					break;
				}
			}
			if (!chk)
				puts(x & 1 ? "Spinster Number." : "Bachelor Number.");
			break;
		case 2:
			int key = 0;
			for (int v = (x & 1) ? x + 1 : x; v <= y; v += 2) {
				x = abs(v);
				if (x && x%4)
					++key;
			}
			printf("%d\n", key);
			break;
		}
	}

	return 0;
}

