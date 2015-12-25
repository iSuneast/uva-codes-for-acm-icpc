/*
 * 11965 - Extra Spaces
 *
 * Ad hoc...
 * quite a simple problem...
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
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

char buf[550];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	if(cas!=1)
    		putchar(10);
    	printf("Case %d:\n", cas);

    	scanf("%d", &n);	gets(buf);
    	for(int i=0; i<n; ++i) {
    		gets(buf);
    		for(int j=0; buf[j]; ++j) {
    			if(j && buf[j]==' ' && buf[j-1]==' ') {
    			} else
    				putchar(buf[j]);
    		}
    		putchar(10);
    	}
    }

    return 0;
}

