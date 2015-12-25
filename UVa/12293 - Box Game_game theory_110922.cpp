/*
 * 12293 - Box Game
 *
 * game theory
 * 很显然，n=2，Alice必胜
 * 对于任意n，假如[(n+1)/2, n-1]存在Alice必败，则n处Alice必胜
 * 打表可知，n为(2^k)-1时，Bob必胜，否则Alice必胜
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

	for(int v; scanf("%d", &v)!=EOF && v; ) {
		++v;
		puts(((v&(-v))^v)? "Alice": "Bob");
	}

	return 0;
}
