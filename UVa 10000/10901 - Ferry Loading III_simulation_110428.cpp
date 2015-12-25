/*
 * 10901 - Ferry Loading III
 *
 * simulation
 * get wrong answer so many times because silly bug
 * ...
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
#define MAXN 10003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, t, m, v;
pii q[2][MAXN];
int sz[2], ans[MAXN];

int process(pii q[MAXN], int &p, const int &sz, const int &cur) {
	int cnt=0;
	while(p<sz && cnt<n) {
		if(q[p].first<=cur) {
			ans[ q[p].second ]=cur+t;
			++p;
			++cnt;
		} else {
			break;
		}
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    char op[10];
    while(dataset--) {
    	scanf("%d %d %d", &n, &t, &m);
    	sz[0]=sz[1]=0;
    	for(int i=0; i<m; ++i) {
    		scanf("%d %s", &v, op);
    		if(op[0]=='l') {
    			q[0][ sz[0]++ ]=make_pair(v, i);
    		} else {
    			q[1][ sz[1]++ ]=make_pair(v, i);
    		}
    	}
    	sort(q[0], q[0]+sz[0]);
    	sort(q[1], q[1]+sz[1]);
    	int p[2]={};

    	int cur=0;
    	for( bool right=false; p[0]<sz[0] || p[1]<sz[1]; right=!right, cur+=t) {
    		int cnt=process(q[right], p[right], sz[right], cur);
    		if(!cnt) {
    			if( p[!right]<sz[!right] ) {
    				if(p[right]<sz[right] && q[right][ p[right] ].first<=q[!right][ p[!right] ].first) {
            			cur=q[right][ p[right] ].first;
            			process(q[right], p[right], sz[right], cur);
    				} else {
        				cur=max(cur, q[!right][ p[!right] ].first);		// WA because I mistake obtaining the current time
        			}
    			} else {
    				cur=q[right][ p[right] ].first;
    				process(q[right], p[right], sz[right], cur);
    			}
    		}
    	}

    	for(int i=0; i<m; ++i) {
    		printf("%d\n", ans[i]);
    	}

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

