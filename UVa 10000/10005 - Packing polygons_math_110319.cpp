/*
 * 10005 - Packing polygons
 *
 * math...
 * a fairy straight forward math problem...
 * note of the small precision error
 *
 * if there is only one point, the answer is true
 * otherwise, the polygon can at least have two points in the edge of the circle
 * so for any two point we consider it's at the edge of the circle,
 * and so we can find out the center of the circle easily
 * check whether every point is in the circle, if yes, the answer is true
 * else try the others pairs...
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
const double eps=1e-6;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct POINT {
	double x, y;
}pnt[MAXN], mid[2];
int n;
double r, sqrR;

double dist(POINT &a, POINT &b) {
	return pow(a.x-b.x, 2.0) + pow(a.y-b.y, 2.0);
}

bool find(POINT &a, POINT &b) {
	if(dist(a,b)>4.0*sqrR)
		return false;

	double mx=(a.x+b.x)/2.0;
	double my=(a.y+b.y)/2.0;

	if(fabs(a.y-b.y)<eps) {
		mid[0].x=mid[1].x=mx;
		double t=sqrt( sqrR - pow(mx-a.x, 2.0) );
		mid[0].y= a.y+t;
		mid[1].y= a.y-t;
		return true;
	}

	double k=-(a.x-b.x)/(a.y-b.y);
	double tb=-k*mx+my;

	double u=k*k+1;
	double v=2*k*(tb-a.y)-2*a.x;
	double w=pow(tb-a.y, 2.0)+a.x*a.x-sqrR;

	double delta=sqrt( v*v-4*u*w );
	mid[0].x=(-v+delta)/(2.0*u);
	mid[0].y=k*mid[0].x+tb;

	mid[1].x=(-v-delta)/(2.0*u);
	mid[1].y=k*mid[1].x+tb;

	return true;
}

bool chk() {
	if(n==1)
		return true;
	sqrR=r*r;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			if(!find(pnt[i], pnt[j]))
				continue;

			for(int p=0; p<2; ++p) {
				bool fade=false;
				for(int k=0; k<n; ++k) {
					if(dist(pnt[k], mid[p])>sqrR+eps) {
						fade=true;
						break;
					}
				}
				if(!fade)
					return true;
			}
		}
	}

	return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d", &n)!=EOF && n) {
    	for(int i=0; i<n; ++i) {
    		scanf("%lf %lf", &pnt[i].x, &pnt[i].y);
    	}
    	scanf("%lf", &r);
    	puts(chk()? "The polygon can be packed in the circle."
    			: "There is no way of packing that polygon.");
    }

    return 0;
}

