#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define LOWBIT(v) ((v)&(-(v)))

#define MAXN 1003
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int n, m;
const int len = 10000;
double p[MAXN];
double np[MAXN<<1];

void calc(double *pos, int size) {
	double seg = len / (double)size;
	pos[0] = 0;
	for(int i=1; i<size; ++i) {
		pos[i] = pos[i-1] + seg;
	}
}

double solve() {
	calc(p, n);
	calc(np, n+m);
	double ret = 0;
	int size = n+m;
	for(int i=1, j=1, c=0; i<size; ++i) {
		if(c==m || (j<n && i+1 < size && fabs(p[j]-np[i]) < fabs(p[j] - np[i+1]))) {
			ret += fabs(p[j++]-np[i]);
		} else {
			++c;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while(scanf("%d %d", &n, &m) != EOF) {
		printf("%.4lf\n", solve());
	}

	return 0;
}
