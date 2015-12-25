#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define LOWBIT(v) ((v)&(-(v)))

#define MAXN 1000003
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int n;
int var[MAXN];
LL s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while(scanf("%d", &n) != EOF) {
		LL sum = 0;
		for(int i=0; i<n; ++i) {
			scanf("%d", &var[i]);
			sum += var[i];
		}
		LL avg = sum/n;
		s[0] = 0;
		for(int i=1; i<n; ++i) {
			s[i] = s[i-1] + var[i-1] - avg;
		}
		sort(s, s+n);
		LL key = 0;
		LL mid = s[n>>1];
		for(int i=0; i<n; ++i) {
			key += abs(mid-s[i]);
		}
		printf("%lld\n", key);
	}

	return 0;
}
