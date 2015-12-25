/*
 * 10587 - Mayor's posters
 *
 * data struct
 * segment tree
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
#define MAX_DEP 16
#define MAXN 10003
#define LS(p) ((p)<<1)
#define RS(p) (((p)<<1)|1)
#define MID(l, r) (((l)+(r))>>1)
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct SegTree {
	struct NODE {
		int l, r, v;
		NODE(){}
		NODE(const int &l, const int &r) :
			l(l), r(r), v(-1){};
	}node[1<<MAX_DEP];
	set<int> color;

	void build(int l, int r, const int &p=1) {
		node[p]=NODE(l, r);
		if(l+1!=r) {
			build(l, MID(l,r), LS(p));
			build(MID(l,r), r, RS(p));
		}
	}

	void insert(int l, int r, int v, const int &p=1) {
		if(node[p].l+1==node[p].r) {
			node[p].v=v;
			return ;
		}

		if(node[p].v!=-1) {
			node[LS(p)].v=node[RS(p)].v=node[p].v;
			node[p].v=-1;
		}

		if(l<=node[p].l && node[p].r<=r) {
			node[p].v=v;
			return ;
		}
		if( l<MID(node[p].l, node[p].r) )
			insert(l, r, v, LS(p));
		if( MID(node[p].l, node[p].r)<r )
			insert(l, r, v, RS(p));
	}

	void down(const int &p=1) {
		if(node[p].l+1==node[p].r) {
			if(node[p].v!=-1) {
				color.insert(node[p].v);
			}
		} else {
			if(node[p].v!=-1) {
				node[ LS(p) ].v=node[ RS(p) ].v=node[p].v;
				node[p].v=-1;
			}
			down(LS(p));
			down(RS(p));
		}
	}

	int count() {
		color.clear();
		down();
		return color.size();
	}
}st;

pii post[MAXN];
int n, ls[MAXN*2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	int sz=0;
    	scanf("%d", &n);
    	for(int i=0; i<n; ++i) {
    		scanf("%d %d", &post[i].first, &post[i].second);
    		++post[i].second;
    		ls[sz++]=post[i].first;
    		ls[sz++]=post[i].second;
    	}
    	sort(ls, ls+sz);

    	st.build(0, sz);
    	for(int i=0; i<n; ++i) {
    		int s=lower_bound(ls, ls+sz, post[i].first)-ls;
    		int e=lower_bound(ls, ls+sz, post[i].second)-ls;
    		st.insert(s, e, i);
    	}

    	printf("%d\n", st.count());
    }

    return 0;
}

