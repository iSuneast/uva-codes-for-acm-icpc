/*
 * 11955 - Binomial Theorem
 *
 * Ad hoc...
 * in order to solve this problem
 * you have to achieve little knowledge of combination math
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
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int gcd(int a, int b) {
	return b? gcd(b, a%b): a;
}

int arr[2][MAXN];

void out(int n, int k) {
	int a=0, b=0;
	for(int i=n-k+1; i<=n; ++i) {
		arr[0][a++]=i;
	}
	for(int i=2; i<=k; ++i) {
		arr[1][b++]=i;
	}

	for(int i=0; i<a; ++i) {
		for(int j=0; j<b; ++j) {
			int t=gcd(arr[0][i], arr[1][j]);
			arr[0][i]/=t;
			arr[1][j]/=t;
		}
	}

	LL key=1;
	for(int i=0; i<a; ++i) {
		key*=arr[0][i];
	}

	if(key>1)
		printf("%lld*", key);
}

char buf[MAXN], a[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n;

    scanf("%d", &dataset);	gets(buf);
    for(int cas=1; cas<=dataset; ++cas) {
    	gets(buf);
    	for(int i=0; buf[i]; ++i) {
    		if(!isdigit(buf[i]) && !isalpha(buf[i]))
    			buf[i]=' ';
    	}

    	sscanf(buf, "%s %s %d", a, b, &n);

    	printf("Case %d: ", cas);

    	for(int i=0; i<=n; ++i) {
    		out(n, i);
    		if(i!=n) {
    			printf("%s", a);
    			if(n-i>1)
    				printf("^%d", n-i);
    		}

    		if(i) {
    			if(i!=n)
    				printf("*");
    			printf("%s", b);
    			if(i>1)
    				printf("^%d", i);
    		}

    		if(i!=n)
    			putchar('+');
    	}
    	putchar(10);
    }

    return 0;
}

