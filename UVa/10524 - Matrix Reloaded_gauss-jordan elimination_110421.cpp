/*
 * 10524 - Matrix Reloaded
 *
 * Gauss-Jordan elimination
 *
 * "No pivoting is allowed."
 * I don't understand what's the meaning of this sentence
 * BTW, in the PHBB, the people say:
 * 2
 * 0 1
 * 1 0
 * is "Not possible", because the Inverse Matrix is
 * 0 1
 * 1 0 // the diagonal contains 0, is invalid in this problem~
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
#define MAXN 100
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct MATRIX {
	double v[MAXN][MAXN*2];
	int n, m;
	bool read() {
		if(scanf("%d", &n)==EOF)
			return false;
		m=2*n;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				scanf("%lf", &v[i][j]);
			}
			for(int j=n; j<m; ++j) {
				v[i][j]=0;
			}
			v[i][i+n]=1;
		}

		return n;
	}

	void solve() {
		for(int i=0; i<n; ++i) {
			if(abs(v[i][i])<eps) {
				puts("Not possible");
				return ;
			}

			for(int j=m-1; j>=i; --j) {
				v[i][j]/=v[i][i];
			}

			for(int k=0; k<n; ++k) {
				if(k==i || abs(v[k][i])<eps)
					continue;
				for(int j=m-1; j>=i; --j) {
					v[k][j]-=v[k][i]*v[i][j];
				}
			}
		}

		out();
	}

	void out() {
		for(int i=0; i<n; ++i) {
			for(int j=n; j<m; ++j) {
				if(abs(v[i][j])<eps)
					v[i][j]=0;
				printf("%.6lf%c", v[i][j], j+1==m? '\n': ' ');
			}
		}
	}
}matrix;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(matrix.read()) {
    	matrix.solve();
    	putchar(10);
    }

    return 0;
}

