/*
 * 10677 - Base Equality
 *
 * Ad hoc...
 * base convert
 * brute force...
 *
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
#define MAXN 20
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int b1, b2, r1, r2, dig[MAXN];

bool chk(int n) {
	int sz=0;
	for(int t=n; t; t/=b1, ++sz) {
		dig[sz]=t%b1;
	}

	int key=0;
	for(int i=sz-1; i>=0; --i) {
		key=key*b2+dig[i];
	}

	return key%n==0;
}

void process() {
	for(int i=r2-1; i>r1; --i) {
		if(chk(i)) {
			printf("%d\n", i);
			return ;
		}
	}

	puts("Non-existent.");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d %d %d", &b1, &b2, &r1, &r2);
    	process();
    }

    return 0;
}

