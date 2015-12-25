/*
 * 10870 - Recurrences
 *
 * matrix multiply
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
#define MAXN 15
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int d, n, m;
LL f[MAXN];
struct MATRIX {
	LL v[MAXN][MAXN];
	void init() {
		memset(v, 0, sizeof(v));
		for(int i=0; i<d; ++i) {
			scanf("%lld", &v[0][i]);
		}
		for(int i=1; i<d; ++i) {
			v[i][i-1]=1;
		}
	}
	void identity() {
		memset(v, 0, sizeof(v));
		for(int i=0; i<d; ++i) {
			v[i][i]=1;
		}
	}

	MATRIX operator*(const MATRIX &t) const {
		MATRIX key;
		for(int i=0; i<d; ++i) {
			for(int j=0; j<d; ++j) {
				key.v[i][j]=0;
				for(int k=0; k<d; ++k) {
					key.v[i][j] += v[i][k]*t.v[k][j];
					key.v[i][j]%=m;
				}
			}
		}
		return key;
	}
};

LL process() {
	MATRIX mul, key;
	mul.init();
	key.identity();
	for(int i=0; i<d; ++i) {
		scanf("%lld", &f[i]);
	}

	if(n<=d)
		return f[n-1];

	for( n=n-d; n; n>>=1) {
		if(n&1)
			key=key*mul;
		mul=mul*mul;
	}

	LL ans=0;
	for(int i=0; i<d; ++i) {
		ans += f[d-1-i]*key.v[0][i];
		ans%=m;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while(scanf("%d %d %d", &d, &n, &m)!=EOF && (d||n||m)) {
    	printf("%lld\n", process()%m);
    }

    return 0;
}

