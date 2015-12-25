/*
 * 11934 - Magic Formula
 *
 * Brute force..
 * 这种数据规模，显然是要大家暴力的。。。
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

	int a, b, c, d, l;
	while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &l)!=EOF && (a||b||c||d||l)) {
		int key=0;
		for(int i=0; i<=l; ++i) {
			int t=i*(a*i+b)+c;
			if(t%d==0)
				++key;
		}

		printf("%d\n", key);
	}

	return 0;
}

