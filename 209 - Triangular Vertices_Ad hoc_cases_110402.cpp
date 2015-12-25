/*
 * 209 - Triangular Vertices
 *
 * Ad hoc...
 * remember: "keep it simple, stupid"
 * don't use too many "if", it'll make your code much harder to understand
 *
 * so just sort all the points
 * and check whether they can format a valid polygon
 * for TRIGNGLE, there are only 3 edges
 * for PARALLELOGRAM, there are 4 edges
 * for HEXAGON, there are 6 edges
 *
 * so just do like this, take PARALLELOGRAM for example
 * length = calc(v[0], v[1])
 * return calc(v[0], v[2])!=length
		|| calc(v[1], v[3])!=length
		|| calc(v[2], v[3])!=length ? "": "";
	   # calc(a, b) function here, return the distance between a and b
 *
 * almost the same to TRIANGLE and HEXAGON
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
#define MAXN 32768
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

vector<pii> v;
pii pnt[MAXN];
const char key[][100]={
		"are not the vertices of an acceptable figure",
		"are the vertices of a triangle",
		"are the vertices of a parallelogram",
		"are the vertices of a hexagon"
};
int length;

void init() {
	for(int r=1, p=1; ; ++r) {
		for(int c=1; c<=r; ++c) {
			pnt[p++]=make_pair(r, c);
			if(p==MAXN)
				return ;
		}
	}
}

int calc(const pii &a, const pii &b) {
	if(a.first==b.first)
		return abs(a.second-b.second);
	if(a.second==b.second)
		return abs(a.first-b.first);
	if(a.first-a.second == b.first-b.second)
		return abs(a.first-b.first);

	return -1;
}

int triangle() {
	return calc(v[0], v[2])!=length
		|| calc(v[1], v[2])!=length ? 0: 1;
}

int parallelogram() {
	return calc(v[0], v[2])!=length
		|| calc(v[1], v[3])!=length
		|| calc(v[2], v[3])!=length ? 0: 2;
}

int hexagon() {
	return calc(v[0], v[2])!=length
		|| calc(v[1], v[3])!=length
		|| calc(v[2], v[4])!=length
		|| calc(v[3], v[5])!=length
		|| calc(v[4], v[5])!=length ? 0: 3;
}

int process() {
	sort(v.begin(), v.end());

	length=calc(v[0], v[1]);
	if(length==-1)
		return 0;

	if(v.size()==3) {
		return triangle();
	} else if(v.size()==4) {
		return parallelogram();
	} else if(v.size()==6) {
		return hexagon();
	} else {
		return 0;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

    init();
    char buf[100];
    int t;
    while(gets(buf)) {
    	v.clear();
    	for(char *token=strtok(buf, " "); token; token=strtok(NULL, " ")) {
    		sscanf(token, "%d", &t);
    		v.push_back(pnt[t]);
    		printf("%d ", t);
    	}

    	puts( key[process()] );
    }

    return 0;
}

