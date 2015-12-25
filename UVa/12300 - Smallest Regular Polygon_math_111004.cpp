/*
12300 - Smallest Regular Polygon

math
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

double xa, ya, xb, yb;
int n;

double sqr(const double &t) {
	return t*t;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	const double pi=acos(-1.0);
	while(scanf("%lf %lf %lf %lf %d", &xa, &xb, &ya, &yb, &n)!=EOF && n) {
		double d=sqrt(sqr(xa-ya)+sqr(xb-yb)), r=d/2.0;
		if(n&1) {
			r/=sin(pi*(n-1)/n/2.0);
		}
		printf("%.6lf\n", sqr(r)*sin(2*pi/n)*n/2.0);
	}

	return 0;
}
