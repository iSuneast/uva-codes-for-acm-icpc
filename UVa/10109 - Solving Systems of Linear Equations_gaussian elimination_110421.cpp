/*
 * 10109 - Solving Systems of Linear Equations
 *
 * gaussian elimination
 * my first time of gaussian elimination problem
 * straight forward~
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
#include <list>
#include <set>
#include <ctime>
#define MAXN 530
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct FRACTION {
	LL a, b;
	FRACTION(){}
	FRACTION(const LL &_a, const LL &_b) {
		LL t=gcd(_a, _b);
		a=_a/t;
		b=_b/t;
		if(b<0) {		// be care of the case of a/-b
			b=-b;
			a=-a;
		}
	}

	LL gcd(LL a, LL b) {
		return b==0? a: gcd(b, a%b);
	}

	void read() {
		scanf("%lld", &a);
		if(getchar()=='/')
			scanf("%lld", &b);
		else
			b=1;
		*this=FRACTION(a, b);
	}

	FRACTION operator/(const FRACTION &t) const {
		return FRACTION(a*t.b, b*t.a);
	}
	FRACTION operator*(const FRACTION &t) const {
		return FRACTION(a*t.a, b*t.b);
	}
	FRACTION operator-(const FRACTION &t) const {
		return FRACTION(a*t.b-b*t.a, b*t.b);
	}
};

struct MATRIX {
	int n, m;
	FRACTION v[MAXN][MAXN], x[MAXN];

	void read() {
		scanf("%d %d", &m, &n);
		++m;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j) {
				v[i][j].read();
			}
		}
	}

	void solve() {
		for(int i=0; i<n; ++i) {
			if(v[i][i].a==0) {
				for(int k=i+1; k<n; ++k) {
					if(v[k][i].a!=0) {
						for(int j=0; j<m; ++j) {
							swap(v[i][j], v[k][j]);
						}
						break;
					}
				}
			}

			if(v[i][i].a==0)
				continue;

			for(int j=m-1; j>=i; --j) {
				v[i][j]=v[i][j]/v[i][i];
			}

			for(int k=i+1; k<n; ++k) {
				if(v[k][i].a!=0) {
					for(int j=m-1; j>=i; --j) {
						v[k][j]=v[k][j]-v[i][j]*v[k][i];
					}
				}
			}
		}

		substitution();
	}

	void substitution() {
		int answer=m-1;
		int add=answer;
		for(int i=0; i<n; ++i) {
			bool zero=true;
			for(int j=m-2; j>=i; --j) {
				if(v[i][j].a!=0)
					zero=false;
			}
			if(zero && v[i][m-1].a!=0) {
				puts("No Solution.");
				return ;
			}
			if(!zero)
				--add;
		}

		if(add>0) {
			printf("Infinitely many solutions containing %d arbitrary constants.\n", add);
			return ;
		}

		for(int i=answer-1; i>=0; --i) {
			x[i]=v[i][m-1];
			for(int j=m-2; j>i; --j) {
				x[i]=x[i]-v[i][j]*x[j];
			}
		}

		for(int i=0; i<answer; ++i) {
			if(x[i].b!=1)
				printf("x[%d] = %lld/%lld\n", i+1, x[i].a, x[i].b);
			else
				printf("x[%d] = %lld\n", i+1, x[i].a);
		}
	}
}matrix;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    bool first=true;
    for(int cas; scanf("%d", &cas)!=EOF && cas; ) {
    	if(!first)
    		putchar(10);
    	first=false;
    	printf("Solution for Matrix System # %d\n", cas);
    	matrix.read();
    	matrix.solve();
    }

    return 0;
}

