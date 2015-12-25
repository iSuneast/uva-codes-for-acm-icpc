/*
 * 218 - Moth Eradication
 *
 * geometry...
 * a straight forward convex hull problem
 * no trick
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
#define MAXN 10003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct POINT {
	double x, y;
}pnt[MAXN];

double sqr(const double &t) {
	return t*t;
}

double dist(const POINT &a, const POINT &b) {
	return sqr(b.x-a.x)+sqr(b.y-a.y);
}

double cross(const POINT &a, const POINT &b, const POINT &c) {
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

bool cmp(const POINT &a, const POINT &b) {
	double t=cross(pnt[0], a, b);
	return t>0 || (fabs(t)<eps && dist(pnt[0],a)<dist(pnt[0],b));
}

struct PLOYGON {
	int n;
	bool read() {
		if(scanf("%d", &n)==EOF || !n)
			return false;
		for(int i=0; i<n; ++i) {
			scanf("%lf %lf", &pnt[i].x, &pnt[i].y);
		}
		return true;
	}

	void process() {
		int p=0;
		for(int i=0; i<n; ++i) {
			if(pnt[i].x<pnt[p].x || ( fabs(pnt[i].x-pnt[p].x)<eps && pnt[i].y<pnt[p].y ))
				p=i;
		}
		swap(pnt[p], pnt[0]);
		sort(pnt+1, pnt+n, cmp);
		int top=2;
		for(int i=3; i<n; ++i) {
			while(top>1 && cross(pnt[top-1], pnt[top], pnt[i])<-eps)
				--top;
			pnt[++top]=pnt[i];
		}
		pnt[n=++top]=pnt[0];

		double perim=0;
		for(int i=n; i>=0; --i) {
			printf("(%.1lf,%.1lf)", pnt[i].x, pnt[i].y);
			if(i) {
				putchar('-');
				perim+=sqrt( dist(pnt[i-1], pnt[i]) );
			} else
				putchar(10);
		}
		printf("Perimeter length = %.2lf\n", perim);
	}

}final;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    for(int cas=1; final.read(); ++cas) {
    	if(cas!=1)
    		putchar(10);
    	printf("Region #%d:\n", cas);
    	final.process();
    }

    return 0;
}

