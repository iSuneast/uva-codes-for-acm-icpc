#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 20003
#define lowbit(v) ((v)&(-(v)))
using namespace std;

int dra[MAXN], man[MAXN];
int n, m;

int solve() {
	int j=0, ret = 0;
	for(int i=0; i<n; ++i) {
		while(j < m && man[j] < dra[i]) {
			++j;
		}
		if(j == m) {
			return -1;
		}
		ret += man[j++];
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while(scanf("%d %d", &n, &m) != EOF && (n||m)) {
		for(int i=0; i<n; ++i) {
			scanf("%d", &dra[i]);
		}
		sort(dra, dra+n);
		for(int i=0; i<m; ++i) {
			scanf("%d", &man[i]);
		}
		sort(man, man+m);

		int ret = solve();
		if(ret == -1) {
			puts("Loowater is doomed!");
		} else {
			printf("%d\n", ret);
		}
	}

	return 0;
}
