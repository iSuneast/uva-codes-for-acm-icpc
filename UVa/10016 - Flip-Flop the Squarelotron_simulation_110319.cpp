/*
 * 10016 - Flip-Flop the Squarelotron
 *
 * simulation...
 * no trick, just simulate as the problem description
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
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct BLOCK {
	int mat[MAXN][MAXN], n, ring, s, e;
	void read() {
		scanf("%d", &n);
		ring=(n+1)/2;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				scanf("%d", &mat[i][j]);
			}
		}
	}

	void upsideDown(int r) {
		for(int i=s+1; i<=ring; ++i) {
			swap(mat[i][s], mat[n-i+1][s]);
			swap(mat[i][e], mat[n-i+1][e]);
		}

		for(int j=s; j<=e; ++j) {
			swap(mat[s][j], mat[e][j]);
		}
	}

	void leftRight(int r) {
		for(int j=s+1; j<=ring; ++j) {
			swap(mat[s][j], mat[s][n-j+1]);
			swap(mat[e][j], mat[e][n-j+1]);
		}

		for(int i=s; i<=e; ++i) {
			swap(mat[i][s], mat[i][e]);
		}
	}

	void mainDiagonal(int r) {
		for(int i=s; i<e; ++i) {
			swap(mat[i][s], mat[s][i]);
		}
		for(int j=s; j<e; ++j) {
			swap(mat[e][j], mat[j][e]);
		}
	}

	void mainInvDiagonal(int r) {
		for(int i=s+1; i<e; ++i) {
			swap(mat[i][s], mat[n+1-s][n+1-i]);
		}
		for(int j=s; j<e; ++j) {
			swap(mat[s][j], mat[n+1-j][n+1-s]);
		}
	}

	void process() {
		int t, op;
		for(int r=1; r<=ring; ++r) {
			s=r;
			e=n-s+1;

			scanf("%d", &t);
			while(t--) {
				scanf("%d", &op);
				if(op==1)
					upsideDown(r);
				else if(op==2)
					leftRight(r);
				else if(op==3)
					mainDiagonal(r);
				else
					mainInvDiagonal(r);
			}
		}
	}

	void output() {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<n; ++j) {
				printf("%d ", mat[i][j]);
			}
			printf("%d\n", mat[i][n]);
		}
	}
}final;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	final.read();
    	final.process();
    	final.output();
    }

    return 0;
}

