/*
 * 10668 - Expanding Rods
 *
 * math...
 * tedious precision error :(
 * just check when fabs(L' - L) < eps, the answer is 0.000 and got ac
 *
 * my method is b-search the circle's radius R = { [bgn, end] = [0,INF] }
 * tmpL = R * asin(l/(2.0*R))*2.0
 * if tmpL > L', bgn = R
 * else end = R
 *
 * finally R = bgn
 * and the key = R-sqrt( pow(R,2.0)-pow(L/2.0, 2.0) )
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
const double eps=1e-10;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    double l, n, c;
    while(scanf("%lf %lf %lf", &l, &n, &c)!=EOF && (l>=0 || n>=0 || c>=0)) {
    	double l2=(1+n*c)*l;

    	if(fabs(l2-l)<eps) {
        	printf("%.3lf\n", 0.0);
        	continue;
    	}

    	double bgn=0, end=1e10;
    	int cnt=0;
    	while(fabs(bgn-end)>eps && cnt++<1000) {
    		double mid=(bgn+end)/2.0;
    		double arc=asin(l/(2.0*mid))*2.0;
    		double tl=mid*arc;
    		if(tl>l2) {
    			bgn=mid;
    		} else
    			end=mid;
    	}

    	double r= end;
		double key=r-sqrt( pow(r,2.0)-pow(l/2.0, 2.0) );
    	printf("%.3lf\n", key);
    }

    return 0;
}

