/*
 * 11987 - Almost Union-Find
 *
 * union find set
 * I have a question at first
 * how to handle operation 2 ?
 * if we have to just move out a node from a UFS tree
 * how to handle their children?
 * just ignore it! build a new node insteaded
 *
 * happy coding~
 */

/*
5 7
1 1 2
2 3 4
1 3 5
3 4
2 4 1
3 4
3 3

define F(i) as the root of i's UFS tree

# 5 7
initialization :
h[i]=i;	fa[i]=i;	cnt[i]=1;	sum[i]=i;

# 1 1 2
u=F(h[1]);	v=F(h[2]);
fa[u]=v;	cnt[v]+=cnt[u];	sum[v]+=sum[u];

# 2 3 4
u=F(h[3]);	v=F(h[4]);
cnt[u]--;	sum[u]-=3;
h[3]=6;	fa[3]=v;
cnt[v]++;	sum[v]+=3;

# 1 3 5
u=F(h[3]);	v=F(h[5]);
fa[u]=v;	cnt[v]+=cnt[u];	sum[v]+=sum[u];

# 2 4 1
u=F(h[4]);	v=F(h[1]);
cnt[u]--;	sum[u]-=4;
h[4]=7;	fa[4]=v;
cnt[v]++;	sum[v]+=4;
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
#define MAXN 200003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int h[MAXN], fa[MAXN], cnt[MAXN];
LL sum[MAXN];
int n, m;

int find(int p) {
	return p==fa[p]? p: fa[p]=find(fa[p]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int op, p, q;
    while(scanf("%d %d", &n, &m)!=EOF) {
    	for(int i=1; i<=n; ++i) {
    		fa[i]=i;
    		sum[i]=i;
    		cnt[i]=1;
    		h[i]=i;
    	}

    	while(m--) {
        	scanf("%d", &op);
        	if(op==1) {
        		scanf("%d %d", &p, &q);
        		p=find(h[p]);
        		q=find(h[q]);
        		if(p!=q) {
        			fa[p]=q;
        			cnt[q]+=cnt[p];
        			sum[q]+=sum[p];
        		}
        	} else if(op==2) {
        		scanf("%d %d", &p, &q);
        		int hp=find(h[p]);
        		q=find(h[q]);

        		if(hp!=q) {
        			--cnt[hp];
        			sum[hp]-=p;

        			h[p]=++n;
        			fa[ h[p] ]=q;
        			cnt[q]++;
        			sum[q]+=p;
        		}
        	} else {
        		scanf("%d", &p);
        		p=h[p];
        		printf("%d %lld\n", cnt[ find(p) ], sum[ find(p) ]);
        	}
    	}
    }

    return 0;
}

