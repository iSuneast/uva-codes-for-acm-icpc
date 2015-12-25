/*
 * 10855 - Rotated square
 *
 * Ad hoc...
 * a straight brute force solution will do~
 * just do as the problem description
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
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

char a[MAXN][MAXN], b[MAXN][MAXN], buf[MAXN][MAXN];
int sa, sb;

void rotate() {
	for(int i=0; i<sb; ++i) {
		for(int j=0; j<sb; ++j) {
			buf[i][j]=b[i][j];
		}
	}

	for(int i=0; i<sb; ++i) {
		for(int j=0; j<sb; ++j) {
			b[j][i]=buf[sb-1-i][j];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d %d", &sa, &sb)!=EOF && (sa||sb)) {
    	for(int i=0; i<sa; ++i) {
    		scanf("%s", a[i]);
    	}
    	for(int i=0; i<sb; ++i) {
    		scanf("%s", b[i]);
    	}

    	int p=0, key[4]={}, end=sa-sb+1;
    	while(true) {
    		for(int i=0; i<end; ++i) {
    			for(int j=0; j<end; ++j) {
    				bool ok=true;
    				for(int x=0; x<sb && ok; ++x) {
    					for(int y=0; y<sb && ok; ++y) {
    						if(a[i+x][j+y]!=b[x][y])
    							ok=false;
    					}
    				}

    				key[p]+=ok;
    			}
    		}

    		if(++p==4)
    			break;
    		rotate();
    	}

    	printf("%d %d %d %d\n", key[0], key[1], key[2], key[3]);
    }

    return 0;
}

