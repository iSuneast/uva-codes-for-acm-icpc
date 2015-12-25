/*
 * 11610 - Reverse Prime
 *
 * data struct
 * Fenwick tree...
 * Binary Indexed Trees
 * init the Reverse Prime and there number of factors
 * then use BIT to solve the query
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
#define MAXN 1000000
#define MAX_SZ 78500
#define lowbit(t) ((t)&(-(t)))
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

bool fade[MAXN];
int key[MAX_SZ], sz, fac[MAX_SZ], prime[MAX_SZ], load[MAXN];
char buf[10];

int sum[MAX_SZ], flag[MAX_SZ];

void insert(int p, int v) {
	int d=v>0? 1: -1;
	for(; p<MAX_SZ; p+=lowbit(p)) {
		sum[p]+=v;
		flag[p]+=d;
	}
}

int calc(int p) {
	int s=0;
	for( ; p; p-=lowbit(p)) {
		s+=sum[p];
	}
	return s;
}

int pos(int p) {
	int s=0;
	for( ; p; p-=lowbit(p)) {
		s+=flag[p];
	}
	return s;
}

int located(int v) {
	int bgn=1, end=sz;
	while(bgn<=end) {
		int mid=(bgn+end)>>1;
		if(pos(mid)<=v) {
			bgn=mid+1;
		} else
			end=mid-1;
	}
	return end;
}

void add(const int &v) {
	sprintf(buf, "%07d", v);
	for(int i=0; i<3; ++i) {
		swap(buf[i], buf[6-i]);
	}

	prime[sz]=v;
	key[sz++]=atol(buf);
}

void init() {
	sz=0;
	for(int i=2; i<MAXN; i++) {
		if(!fade[i]) {
			add(i);
			load[i]=1;
			for(int j=i<<1; j<MAXN; j+=i) {
				int t=j;
				while(t%i==0) {
					t/=i;
					++load[j];
				}
				fade[j]=true;
			}
		}
	}
	sort(key, key+sz);

	for(int i=0; i<sz; ++i) {
		fac[i]=0;
		int t=key[i];
		for(int j=0; j<sz && prime[j]<=t; ++j) {
			if(t%prime[j]==0) {
				while(t%prime[j]==0) {
					t/=prime[j];
					fac[i]++;
				}
				if(t<MAXN) {
					fac[i]+=load[t];
					break;
				}
			}
		}
		insert(i+1, fac[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    char op[3];
    int v;
    while(scanf("%s %d", op, &v)!=EOF) {
    	if(op[0]=='q') {
    		printf("%d\n", calc( located(v+1) ));
    	} else {
    		int p=lower_bound(key, key+sz, v)-key;
    		insert( p+1, -fac[p] );
    	}
    }

    return 0;
}

