/*
 * 10909 - Lucky Number
 *
 * bst
 * using binary search tree to obtain the number in O(NlogN) time
 * if N is odd, just output NO, because all the lucky number is odd
 * so their sum is all even~
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
#define MAXN 1000003
#define MAX_SZ 136420
#define L 0
#define R 1
#define F(p, v) (var[p]<=v)
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int key[MAX_SZ], tot;
bool exist[MAXN*2];

struct SPLAY {
	int son[MAXN][2], fa[MAXN], root, idx, sz[MAXN], var[MAXN];
	SPLAY() {idx=0;}

	void rotate(int x, int op) {
		int y=fa[x];

		sz[y]=sz[y]-sz[x]+sz[ son[x][op] ];
		sz[x]=sz[x]-sz[ son[x][op] ]+sz[y];

		son[y][1-op]=son[x][op];
		if(son[x][op])	fa[ son[x][op] ]=y;

		fa[x]=fa[y];
		if(fa[y]) {
			if(y==son[ fa[y] ][L]) son[ fa[y] ][L]=x;
			else son[ fa[y] ][R]=x;
		}

		son[x][op]=y;
		fa[y]=x;
	}

	void splay(int x) {
		while(fa[x]) {
			int y=fa[x];
			if(!fa[y]) {
				if(x==son[y][L]) rotate(x, R);
				else rotate(x, L);
			} else {
				if(y==son[ fa[y] ][L]) {
					if(x==son[y][L]) rotate(y, R);
					else rotate(x, L);
					rotate(x, R);
				} else {
					if(x==son[y][R]) rotate(y, L);
					else rotate(x, R);
					rotate(x, L);
				}
			}
		}
		root=x;
	}

	int search(int x, const int &v) {
		while(var[x]!=v) {
			if(!son[x][ F(x, v) ])
				break;
			x=son[x][ F(x, v) ];
		}
		return x;
	}

	void insert(const int &v) {
		int p=0;
		++idx;
		if(!root) {
			root=idx;
		} else {
			p=search(root, v);
			++sz[p];
			son[p][ F(p, v) ]=idx;
		}
		var[idx]=v;	sz[idx]=1;	fa[idx]=p;
		splay(idx);
	}

	int kth(int x) {
		int idx=root;
		while(x!=sz[ son[idx][L] ]+1) {
			if(x>sz[ son[idx][L] ]+1) {
				x=x-sz[ son[idx][L] ]-1;
				idx=son[idx][R];
			} else {
				idx=son[idx][L];
			}
		}

		splay(idx);
		return idx;
	}

	int size() const{
		return sz[root];
	}

	int extreme(int x, int op) {
		int p=search(x, op*INF);
		splay(p);
		return p;
	}

	void del(const int &v) {
		int idx=search(root, v);
		splay(idx);
		if(var[idx]==v) {
			if(!son[idx][L]) {
				root=son[idx][R];
			} else {
				fa[ son[idx][L] ]=0;
				root=extreme(son[idx][L], 1);
				son[root][R]=son[idx][R];
				sz[root]=sz[root]+sz[ son[idx][R] ];
				fa[ son[idx][R] ]=root;
			}
		}
	}

	void delKth(const int &k) {
		int idx=kth(k);
		if(!son[idx][L]) {
			root=son[idx][R];
		} else {
			fa[ son[idx][L] ]=0;
			root=extreme(son[idx][L], 1);
			son[root][R]=son[idx][R];
			sz[root]=sz[root]+sz[ son[idx][R] ];
			fa[ son[idx][R] ]=root;
		}
	}

	void dfs(int x) {
		if(!x)
			return ;
		dfs(son[x][0]);
		key[tot++]=var[x];
		exist[ var[x] ]=true;
		dfs(son[x][1]);
	}
}tree;

void init() {
	for(int i=1; i<=2000000; i+=2) {
		tree.insert(i);
	}

	for(int p=2; p<=tree.size(); ++p) {
		int j=tree.var[ tree.kth(p) ];
		for(int end=tree.size()/j*j; end; end-=j)
			tree.delKth(end);
	}

	tot=0;
	tree.dfs(tree.root);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

    init();
    for(int n; scanf("%d", &n)!=EOF; ) {
    	if(n&1) {
    		printf("%d is not the sum of two luckies!\n", n);
    		continue;
    	}
    	int p=upper_bound(key, key+tot, n/2)-key-1;
    	bool fade=true;
    	for(int i=p; i>=0; --i) {
    		if(exist[ n-key[i] ]) {
    			fade=false;
    			printf("%d is the sum of %d and %d.\n", n, key[i], n-key[i]);
    			break;
    		}
    	}
    	if(fade)
    		printf("%d is not the sum of two luckies!\n", n);
    }

    return 0;
}

