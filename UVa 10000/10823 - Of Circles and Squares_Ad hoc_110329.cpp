/*
 * 10823 - Of Circles and Squares
 *
 * Ad hoc..
 * nothing special~
 * carefully reading the problem description and got ac
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
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct DATA {
	bool circle;
	int px, py, length, r, g, b;
	void read() {
		char buf[10];
		scanf("%s %d %d %d %d %d %d", buf, &px, &py, &length, &r, &g, &b);
		circle=(buf[0]=='C');
	}
}data[MAXN];
int x, y, n, p;

int sqr(const int &t) {
	return t*t;
}

int dist(int sx, int sy, int ex, int ey) {
	return sqr(sx-ex)+sqr(sy-ey);
}

bool inside(const DATA &t) {
	return t.px<x && x<t.px+t.length
		&& t.py<y && y<t.py+t.length;
}

bool border(const DATA &t) {
	return t.px<=x && x<=t.px+t.length
		&& t.py<=y && y<=t.py+t.length;
}

int chk(const DATA &t) {
	if(inside(t))
		return 1;
	else if(border(t))
		return 0;
	else
		return -1;
}

void process() {
	double r=0, g=0, b=0, cnt=0;
	for(int i=0; i<n; ++i) {
		if(data[i].circle) {
			int d=dist( x, y, data[i].px, data[i].py);
			if(d==data[i].length) {
				printf("(%d, %d, %d)\n", 0, 0, 0);
				return ;
			} else if(d<data[i].length) {
				++cnt;
				r+=data[i].r;
				g+=data[i].g;
				b+=data[i].b;
			}
		} else {
			int key=chk(data[i]);
			if(key==0) {
				printf("(%d, %d, %d)\n", 0, 0, 0);
				return ;
			} else if(key==1) {
				++cnt;
				r+=data[i].r;
				g+=data[i].g;
				b+=data[i].b;
			}
		}
	}

	if(cnt==0)
		printf("(%d, %d, %d)\n", 255, 255, 255);
	else
		printf("(%.0lf, %.0lf, %.0lf)\n", round(r/cnt), round(g/cnt), round(b/cnt));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	if(cas!=1)
    		putchar(10);
    	printf("Case %d:\n", cas);

    	scanf("%d %d", &n, &p);
    	for(int i=0; i<n; ++i) {
    		data[i].read();
    		if(data[i].circle)
    			data[i].length=sqr(data[i].length);
    	}
    	while(p--) {
    		scanf("%d %d", &x, &y);
    		process();
    	}
    }

    return 0;
}

