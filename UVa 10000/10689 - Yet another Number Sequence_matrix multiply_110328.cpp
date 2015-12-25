/*
 * 10689 - Yet another Number Sequence
 *
 * fib...
 * matrix multiply
 * just a fairy straight forward matrix multiply problem the same as FIB sequence
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
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct MATRIX {
	int v[2][2];
	void identity() {
		v[0][1]=v[1][0]=0;
		v[0][0]=v[1][1]=1;
	}

	void fib() {
		v[0][0]=v[0][1]=v[1][0]=1;
		v[1][1]=0;
	}

	MATRIX multiply(const MATRIX &t, const int &m) {
		MATRIX ans;
		for(int i=0; i<2; ++i) {
			for(int j=0; j<2; ++j) {
				ans.v[i][j]=0;
				for(int k=0; k<2; ++k) {
					ans.v[i][j] = (ans.v[i][j] + v[i][k]*t.v[k][j])%m;
				}
			}
		}

		return ans;
	}
}key, mul, e;

int pow_mod(int a, int b, int n, const int &m) {
	if(!n)
		return a;
	key.identity();
	mul.fib();
	for( --n; n>0; n>>=1) {
		if(n&1) {
			key=key.multiply(mul, m);
		}
		mul=mul.multiply(mul, m);
	}

	return (b*key.v[0][0]+a*key.v[0][1])%m;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    const int mod[]={0, 10, 100, 1000, 10000};
    int a, b, n, m;
    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d %d %d", &a, &b, &n, &m);
    	printf("%d\n", pow_mod(a, b, n, mod[m]) );
    }

    return 0;
}

