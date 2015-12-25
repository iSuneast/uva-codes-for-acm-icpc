/*
 * 10655 - Contemplation - Algebra
 *
 * matrix multiply
 * f(n) = x^n + y^n
 * f(n-1) = x^(n-1) + y^(n-1)
 * ...
 * f(1) = x + y = p
 * f(0) = x^0 + y^0 = 2
 * ( x^(n-1) + y^(n-1) ) * (x+y) = x^n + y^n + x*y*( x^(n-2)+y^(n-2) )
 * so f(n) = p*f(n-1) - q*f(n-2)
 *
 * using matrix multiply to solve this equation
 * p q n maybe "0 0 0", so don't exist when just p=q=0 occur
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
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct MATRIX {
	LL v[2][2];
	MATRIX() {
		v[0][0]=v[1][1]=1;
		v[0][1]=v[1][0]=0;
	}
	MATRIX(const LL &p, const LL &q) {
		v[0][0]=p;
		v[0][1]=-q;
		v[1][0]=1;
		v[1][1]=0;
	}
	MATRIX operator*(const MATRIX &t) const {
		MATRIX key;
		for(int i=0; i<2; ++i) {
			for(int j=0; j<2; ++j) {
				key.v[i][j]=0;
				for(int k=0; k<2; ++k) {
					key.v[i][j]+=v[i][k]*t.v[k][j];
				}
			}
		}
		return key;
	}
};

LL p, q, n;

LL process() {
	LL f[]={2, p};
	if(n<2)
		return f[n];

	MATRIX mul=MATRIX(p, q), key=MATRIX();
	for( n--; n; n>>=1) {
		if(n&1)
			key=key*mul;
		mul=mul*mul;
	}

	return key.v[0][0]*f[1] + key.v[0][1]*f[0];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while(scanf("%lld %lld", &p, &q)!=EOF) {
    	if(scanf("%lld", &n)==EOF && !p && !q)
    		break;
    	printf("%lld\n", process());
    }

    return 0;
}

