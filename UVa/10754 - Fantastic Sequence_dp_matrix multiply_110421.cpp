/*
 * 10754 - Fantastic Sequence
 *
 * dp
 * matrix multiply
 * build the matrix, and then logN time matrix multiply will do
 *
 * be careful when k=0, the answer is c0
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
#define MAXN 30
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

LL k, m, n;
struct MATRIX {
	LL v[MAXN][MAXN];
	void identity() {
		for(int i=0; i<=k; ++i) {
			for(int j=0; j<=k; ++j) {
				v[i][j]=0;
			}
			v[i][i]=1;
		}
	}
	void init() {
		memset(v, 0, sizeof(v));
		for(int i=0; i<=k; ++i) {
			scanf("%lld", &v[0][i]);
		}
		if(!k)
			return ;
		for(int i=1; i<k; ++i) {
			v[i][i-1]=1;
		}
		v[k][k]=1;
	}

	MATRIX operator*(const MATRIX &t) const {
		MATRIX key;
		for(int i=0; i<=k; ++i) {
			for(int j=0; j<=k; ++j) {
				key.v[i][j]=0;
				for(int a=0; a<=k; ++a) {
					key.v[i][j]= (key.v[i][j]+v[i][a]*t.v[a][j])%m;
				}
			}
		}
		return key;
	}
};

LL var[MAXN];

LL process() {
	MATRIX mul, key;
	mul.init();
	key.identity();

	for(int i=0; i<k; ++i) {
		scanf("%lld", &var[i]);
	}
	if(!k) {
		return mul.v[0][0];
	} else if(n<k) {
		return var[n];
	}

	for(n=n+1-k; n; n>>=1) {
		if(n&1)
			key=key*mul;
		mul=mul*mul;
	}

	LL ans=key.v[0][k];
	for(int i=0; i<k; ++i) {
		ans = (ans+key.v[0][i]*var[k-1-i])%m;
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%lld %lld %lld", &k, &m, &n);
    	printf("%lld\n", (process()%m+m)%m);
    	if(dataset)
    		putchar(10);
    }

    return 0;
}

