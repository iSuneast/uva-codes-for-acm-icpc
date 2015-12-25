/*
 * 11926 - Multitasking
 *
 * Ad hoc...
 * 大水题阿～
 * 我想的复杂了。。。
 * 直接对每种情况扫描一下就可以了。。。
 * 因为最坏情况下是O(10^6)的复杂度 『扫描到冲突就不扫描了= =』
 * 所以。。。
 * 不用推什么公式了。。。
 *
 * 我土了。。。
 *
 * happy coding～
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN 1000001
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

bool fade[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n, m, s, e, d;
    while(scanf("%d%d", &n, &m)!=EOF && (n||m)) {
    	memset(fade, 0, sizeof(fade));
    	bool conflict=false;

    	while(n--) {
    		scanf("%d%d", &s, &e);
    		if(conflict)
    			continue;
    		for(int i=s; i<e && i<MAXN; ++i) {
    			if(fade[i]) {
    				conflict=true;
    				break;
    			}
    			fade[i]=true;
    		}
    	}

    	while(m--) {
    		scanf("%d%d%d", &s, &e, &d);
    		while(s<MAXN && !conflict) {
        		for(int i=s; i<e && i<MAXN; ++i) {
        			if(fade[i]) {
        				conflict=true;
        				break;
        			}
        			fade[i]=true;
        		}
        		s+=d;  e+=d;
    		}
    	}

    	puts(conflict? "CONFLICT": "NO CONFLICT");
    }

    return 0;
}

