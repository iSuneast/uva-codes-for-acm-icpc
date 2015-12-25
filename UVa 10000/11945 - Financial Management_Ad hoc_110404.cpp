/*
 * 11945 - Financial Management
 *
 * Ad hoc
 *
 * "Note: Used comma (,) to separate the thousands."
 * this sentence means, if ans>=1000, we should output
 * the decimal part of the answer using the format below
 * ("%d,%03d", ans/1000, ans%1000)
 *
 * if you still keep getting WA
 * try using string to handle the input to avoid the precision error
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    char buf[100];
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	printf("%d $", cas);

    	int key=0;
    	for(int i=0; i<12; ++i) {
        	scanf("%s", buf);
        	int p, l=strlen(buf);
        	for(p=0; p<l; ++p) {
        		if(buf[p]=='.') {
        			buf[p]=0;
        			key+=atol(buf)*100+atol(buf+p+1);
        			break;
        		}
        	}

        	if(p==l)
    			key+=atol(buf)*100;
    	}

    	key=round(key/12.0);
    	int rem=key%100;
    	key/=100;

    	if(key<1000) {
    		printf("%d.%02d\n", key, rem);
    	} else {
    		printf("%d,%03d.%02d\n", key/1000, key%1000, rem);
    	}
    }

    return 0;
}

