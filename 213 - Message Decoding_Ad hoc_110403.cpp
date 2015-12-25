/*
 * 213 - Message Decoding
 *
 * Ad hoc...
 * just code as the problem description
 * no trick~
 * but in order to solve this problem,
 * you have to understand the problem at first
 *
 * for example, SAMPLE 1
TNM AEIOU
0010101100011
1010001001110110011
11000
 * "TNM AEIOU"
 * "0010101100011101000100111011001111000" -->
 * "001 0 1"			length = 1
 * "011 000 111" 		length = 3
 * "010 00 10 01 11"	length = 2
 * "011 001 111"		length = 3
 * "000"				length = 0, END_OF_CASE
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
#define MAXN (1<<8)
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

char str[MAXN];
int add[MAXN];

int getCode(const int &len) {
	char c;
	int key=0;
	for(int i=0; i<len; ++i) {
		if(scanf(" %c", &c)==EOF)
			return -1;
		key=key*2+c-'0';
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

	add[0]=0;
	for(int i=1; i<MAXN; ++i) {
		add[i]=add[i-1]+(1<<i)-1;
	}

    while(gets(str)) {
    	while(true) {
    		int len=getCode(3);
    		if(!len)
    			break;

    		int end=(1<<len)-1;
    		while(true) {
    			int code=getCode(len);
    			if(code==end)
    				break;

    			putchar(str[ code+add[len-1] ]);
    		}
    	}
    	putchar(10);
    	gets(str);
    }

    return 0;
}

