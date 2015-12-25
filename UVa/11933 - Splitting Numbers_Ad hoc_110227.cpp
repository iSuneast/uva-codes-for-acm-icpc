/*
 * 11933 - Splitting Numbers
 *
 * Ad hoc...
 * 按题目说的做就可以了～
 *
 * happy coding～
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int n; scanf("%d", &n)!=EOF && n; ) {
		int a=0, b=0, pos[32], cnt=0;
		for(int i=0; i<31; i++) {
			if(n&(1<<i))
				pos[cnt++]=i;
		}

		for(int i=0; i<cnt; i+=2) {
			a|=(1<<pos[i]);
			if(i+1<cnt)
				b|=(1<<pos[i+1]);
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}

