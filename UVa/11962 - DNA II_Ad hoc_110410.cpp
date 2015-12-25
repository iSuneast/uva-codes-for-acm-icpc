/*
 * 11962 - DNA II
 *
 * Add hoc
 * base convert
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int h[128];
    h['A']=0;
    h['C']=1;
    h['G']=2;
    h['T']=3;

    int dataset;
    LL base[33];
    base[0]=1;
    for(int i=1; i<33; ++i) {
    	base[i]=base[i-1]*4;
    }

    char buf[33];
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%s", buf);
    	int l=strlen(buf);
    	LL key=0;
    	for(int i=0; i<l; ++i) {
    		key+=base[l-1-i] * h[ (int)buf[i] ];
    	}

    	printf("Case %d: (%d:%lld)\n", cas, l, key);
    }

    return 0;
}

