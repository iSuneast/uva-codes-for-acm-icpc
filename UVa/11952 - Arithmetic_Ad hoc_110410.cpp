/*
 * 11952 - Arithmetic
 *
 * Ad hoc...
 *
 * I'm so curious about what the valid expression will be in Base 1
 * 111 + 11 = 11111, just like linking two strings which only contain '1's
 *
 * for other base, we can brute force search the exact answer
 * the answer won't be so large, just have a try
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
#define MAXN 10
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

char a[MAXN], b[MAXN], c[MAXN];

int base(char *s) {
	int key=0;
	for(int i=0; s[i]; ++i) {
		key=max(key, s[i]-'0'+1);
	}

	return key;
}

LL trans(char *s, int base) {
	LL key=0;
	for(int i=0; s[i]; ++i) {
		key=key*base+s[i]-'0';
	}
	return key;
}

int ok(int base) {
	LL x=trans(a, base), y=trans(b, base), z=trans(c, base);

	if(x+y==z)
		return 1;
	return 0;
}

bool spj() {
	for(int i=0; a[i]; ++i) {
		if(a[i]!='1')
			return false;
	}
	for(int i=0; b[i]; ++i) {
		if(b[i]!='1')
			return false;
	}

	for(int i=0; c[i]; ++i) {
		if(c[i]!='1')
			return false;
	}

	return strlen(a)+strlen(b)==strlen(c);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%s %*s %s %*s %s", a, b, c);

    	if(spj()) {
    		puts("1");
    		continue;
    	}

    	int key=max(base(a), base(b));
    	key=max(key, base(c));
    	key=max(key, 2);

    	bool got=false;
    	for(int base=key; base<=30; ++base) {
    		if(ok(base)==1) {
    			printf("%d\n", base);
    			got=true;
    			break;
    		}
    	}

    	if(!got)
    		puts("0");
    }

    return 0;
}

