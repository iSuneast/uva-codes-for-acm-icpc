/*
 * 338 - Long Multiplication
 *
 * BigInteger
 * just simulation the process of two integer's multiply
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
#define MAXN 30
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char g[MAXN][MAXN];

int len(const LL &t) {
	char buf[MAXN];
	sprintf(buf, "%lld", t);
	return strlen(buf);
}

void out(int l, char c) {
	while(l--)
		putchar(c);
}

struct BigInteger {
	int v[MAXN];
	BigInteger() {
		memset(v, 0, sizeof(v));
	}
	BigInteger(LL t, int zero) {
		memset(v, 0, sizeof(v));
		int sz=0;
		while(zero--) {
			v[sz++]=0;
		}
		while(t) {
			v[sz++]=t%10;
			t/=10;
		}
	}
	BigInteger operator+(const BigInteger &t) const {
		BigInteger ans;
		for(int i=0; i<MAXN; ++i) {
			ans.v[i]=v[i]+t.v[i];
		}
		for(int i=1; i<MAXN; ++i) {
			ans.v[i] += ans.v[i-1]/10;
			ans.v[i-1]%=10;
		}
		return ans;
	}

	int size() {
		for(int i=MAXN-1; i>=0; --i) {
			if(v[i])
				return i+1;
		}
		return 0;
	}

	void out() {
		for(int i=size()-1; i>=0; --i) {
			printf("%d", v[i]);
		}
	}
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    LL a, b;
    vector< pair<LL, int> > data;
    while(scanf("%lld %lld", &a, &b)==2) {
    	int la=len(a), lb=len(b);
    	int maxL=max(la, lb);

    	data.clear();
        BigInteger final;
    	LL mul=b;
    	for(int i=0; mul; ++i,mul/=10) {
    		LL t=(mul%10)*a;
    		if(t) {
    			data.push_back( make_pair(t, i) );
    			maxL=max(maxL, len(t)+i);
    			final=final+BigInteger(t, i);
    		}
    	}

    	maxL=max(maxL, final.size());

		out(maxL-la, ' ');
		printf("%lld\n", a);

		out(maxL-lb, ' ');
		printf("%lld\n", b);

		out(maxL-max(la, lb), ' ');
		out(max(la, lb), '-');
		putchar(10);

    	if(!data.size()) {
    		out(maxL-1, ' ');
    		puts("0");
    	} else if(data.size()==1) {
    		out( maxL-len(data[0].first)-data[0].second, ' ' );
    		printf("%lld", data[0].first);
    		out( data[0].second, '0' );
    		putchar(10);
    	} else {
    		for(int i=0; i<(int)data.size(); ++i) {
        		out( maxL-len(data[i].first)-data[i].second, ' ' );
        		printf("%lld\n", data[i].first);
    		}
    		out(maxL, '-');
    		putchar(10);

    		out(maxL-final.size(), ' ');
    		final.out();
    		putchar(10);
    	}

    	putchar(10);
    }

    return 0;
}

