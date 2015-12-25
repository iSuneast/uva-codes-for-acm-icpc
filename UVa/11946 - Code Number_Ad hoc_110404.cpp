/*
 * 11946 - Code Number
 *
 * Ad hoc...
 * mapping the code numbers '1'-'9' to alpha
 * using the example giving by in the problem description
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
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

char h[128];
char a[]="H3LL0 MY L0V3, 1 M H499Y 83C4U53 500N 1 W1LL 83 70 Y0UR 51D3.7H15 71M3 W17H0U7 Y0U H45 833N 373RN4L. 1 1NV173 Y0U 70 7H3 2000N3 70 533 7H3 238R42 4ND 60R1L42.";
char b[]="HELLO MY LOVE, I M HAPPY BECAUSE SOON I WILL BE TO YOUR SIDE.THIS TIME WITHOUT YOU HAS BEEN ETERNAL. I INVITE YOU TO THE ZOOONE TO SEE THE ZEBRAS AND GORILAS.";

void init() {
	for(int i=0; i<128; ++i) {
		h[i]=i;
	}
	int l=strlen(a);
	for(int i=0; i<l; ++i) {
		h[a[i]]=b[i];
	}

	h['2']='Z';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    int dataset;
    char buf[100];
    scanf("%d", &dataset);	gets(buf);
    while(dataset--) {
    	while(gets(buf) && buf[0]) {
    		for(int i=0; buf[i]; ++i) {
    			putchar(h[ buf[i] ]);
    		}
    		putchar(10);
    	}

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

