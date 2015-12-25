/*
 * 11346 - Probability
 *
 * math...
 * calculus...
 *
 *   双曲线x*y=s，与矩形(0,0) (a,b)的公共面积
 *   Square
 * = dx*dy {x: s/y, a} {y: s/a, b}
 * = a*b - s - s*log(a*b/s)
 * 所以，面积>=s的概率是 Square/(a*b)
 *
 * happy coding~
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#define MAXN
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

double process() {
    double a, b, s;
	scanf("%lf %lf %lf", &a, &b, &s);
	if(a*b<=s)
		return 0;
	if(s<eps)
		return 1;

	return ( a*b-s - s*log(a*b/s) ) / (a*b);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	printf("%.6lf%%\n", process()*100);
    }

    return 0;
}

