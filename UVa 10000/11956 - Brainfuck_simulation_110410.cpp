/*
 * 11956 - Brainfuck
 *
 * simulation~
 * just simulation as the problem description
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

char buf[100003];

void asc(int t) {
	if(t<10)
		putchar('0'+t);
	else
		putchar('A'+t-10);
}

void out(int v) {
	putchar(' ');
	asc(v/16);
	asc(v%16);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	int var[100]={}, p=0;
    	scanf("%s", buf);
    	printf("Case %d:", cas);
    	for(int i=0; buf[i]; ++i) {
    		if(buf[i]=='>') {
    			p = (p+1)%100;
    		} else if(buf[i]=='<') {
    			p= (p+99)%100;
    		} else if(buf[i]=='+') {
    			var[p]= (var[p]+1)%256;
    		} else if(buf[i]=='-') {
    			var[p]= (var[p]+255)%256;
    		}
    	}

    	for(int i=0; i<100; ++i) {
    		out(var[i]);
    	}

    	putchar(10);
    }


    return 0;
}

