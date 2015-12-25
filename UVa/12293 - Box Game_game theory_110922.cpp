/*
 * 12293 - Box Game
 *
 * game theory
 * ����Ȼ��n=2��Alice��ʤ
 * ��������n������[(n+1)/2, n-1]����Alice�ذܣ���n��Alice��ʤ
 * ����֪��nΪ(2^k)-1ʱ��Bob��ʤ������Alice��ʤ
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
