/*
 * 290 - Palindroms <---> smordnilaP
 *
 * Ad hoc...
 * brute force enum all the BASE
 * and use BigInteger two add up two integers
 * stop looping while the result is palindrom
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
#define MAXN 16
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int h(const char &c) {
	if('0'<=c && c<='9')
		return c-'0';
	return c-'A'+10;
}

char _h(const int &t) {
	if(t<10)
		return t+'0';
	return t-10+'A';
}

bool chk(string s) {
	int l=s.length();
	for(int i=0; i*2<l; ++i) {
		if(s[i]!=s[l-1-i])
			return false;
	}
	return true;
}

string rev(string s) {
	int l=s.length();
	for(int i=0; i*2<l; ++i) {
		swap(s[i], s[l-1-i]);
	}
	return s;
}

int process(string num, int base) {
	int step=0;
	num=rev(num);

	for( ; !chk(num); ++step) {
		int add=0, len=num.length();
		string next="";
		for(int i=0; i<len; ++i) {
			int t=h(num[i]) + h(num[len-1-i]) + add;
			add=t/base;
			next=next + _h(t%base);
		}

		if(add)
			next=next + _h(add);
		num=next;
	}

	return step;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    string buf;
    while(cin>>buf) {
    	int end=2;
    	for(int i=buf.length()-1; i>=0; --i) {
    		end=max(end, (int)(h(buf[i])+1) );
    	}

    	for(int i=15; i>=end; --i) {
    		printf("%d", process(buf, i));
    		if(i!=2)
    			putchar(' ');
    		else
    			putchar(10);
    	}

    	for(int i=end-1; i>=2; --i) {
    		putchar('?');
    		if(i!=2)
    			putchar(' ');
    		else
    			putchar(10);
    	}
    }

    return 0;
}

