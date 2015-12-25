/*
 * 12015 - Google is Feeling Lucky
 *
 * Ad hoc...
 * find the site with maximum rank, output it
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

struct DATA {
	string name;
	int rank;
} site[10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset;
	cin >> dataset;
	for (int cas = 1; cas <= dataset; ++cas) {
		int maxV = 0;
		for (int i = 0; i < 10; ++i) {
			cin >> site[i].name >> site[i].rank;
			maxV = max(maxV, site[i].rank);
		}
		cout << "Case #" << cas << ":" << endl;
		for (int i = 0; i < 10; ++i) {
			if (site[i].rank == maxV) {
				cout << site[i].name << endl;
			}
		}
	}

	return 0;
}

