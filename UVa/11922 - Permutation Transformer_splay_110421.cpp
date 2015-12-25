/*
 * 11922 - Permutation Transformer
 *
 * splay
 * the special operation offer by Splay tree only
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
#define MAXN 100003
#define L 0
#define R 1
#define F(idx, v) (var[idx]<=v)
#define L_SZ(x) (sz[ son[x][L] ])
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct SPLAY {
	int var[MAXN], son[MAXN][2], fa[MAXN], sz[MAXN], root, idx;
	bool rev[MAXN];

	SPLAY() {
		root=idx=0;
	}

	void rotate(int x, int op) {
		int y=fa[x];

		sz[y]=sz[y]-sz[x]+sz[ son[x][op] ];
		sz[x]=sz[x]-sz[ son[x][op] ]+sz[y];

		son[y][1-op]=son[x][op];
		if(son[x][op])	fa[ son[x][op] ]=y;

		fa[x]=fa[y];
		if(fa[y]) {
			if(y==son[ fa[y] ][L])	son[ fa[y] ][L]=x;
			else	son[ fa[y] ][R]=x;
		}

		son[x][op]=y;
		fa[y]=x;
	}

	void splay(int x, int T) {
		down(x);
		while(fa[x]!=T) {
			int y=fa[x];
			if(fa[y]==T) {
				if(x==son[y][L])	rotate(x, R);
				else	rotate(x, L);
			} else {
				if(y==son[ fa[y] ][L]) {
					if(x==son[y][L])	rotate(y, R);
					else	rotate(x, L);
					rotate(x, R);
				} else {
					if(x==son[y][R])	rotate(y, L);
					else	rotate(x, R);
					rotate(x, L);
				}
			}
		}
		if(!T)		root=x;
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
		++idx;
		int x=0;
		if(!root) {
			root=1;
		} else {
			x=search(root, v);
			son[x][ F(x, v) ]=idx;
			for(int i=x; i; i=fa[i])	++sz[i];
		}
		var[idx]=v;	fa[idx]=x;	sz[idx]=1;
		splay(idx, 0);
	}

	int size() {
		return sz[root];
	}

	void out(int x, bool r) {
		if(!x)
			return ;
		if(r==rev[x]) {
			out(son[x][L], false);
			printf("%d\n", x);
			out(son[x][R], false);
		} else {
			out(son[x][R], true);
			printf("%d\n", x);
			out(son[x][L], true);
		}
	}

	void down(const int &x) {
		if(rev[x]) {
			rev[x]=false;
			rev[ son[x][L] ]=!rev[ son[x][L] ];
			rev[ son[x][R] ]=!rev[ son[x][R] ];
			swap(son[x][L], son[x][R]);
		}
	}

	int kth(int k) {
		int x=root;
		while(true) {
			down(x);
			if( L_SZ(x)+1==k )
				break;
			if(L_SZ(x)+1<k) {
				k-=L_SZ(x)+1;
				x=son[x][R];
			} else {
				x=son[x][L];
			}
		}
		splay(x, 0);
		return x;
	}

	int adj(int x, int op) {
		down(x);
		x=son[x][op];
		while(true) {
			down(x);
			if(!son[x][1-op])
				break;
			x=son[x][1-op];
		}
		return x;
	}

	void revTree(const int &s, const int &e) {
		if(s==1 && e==size()) {
			rev[root]=!rev[root];
		} else if(s==1) {
			int z=adj(kth(e), 1);
			splay(z, 0);

			int sRoot=son[z][L];
			son[z][L]=0;
			sz[z]-=sz[sRoot];

			int x=kth(size());
			son[x][R]=sRoot;
			fa[sRoot]=x;
			sz[x]+=sz[sRoot];

			rev[sRoot]=!rev[sRoot];
		} else if(e==size()) {
			int y=adj(kth(s), 0);
			splay(y, 0);
			rev[ son[y][R] ]=!rev[ son[y][R] ];
		} else {
			int y=adj(kth(s), 0);
			int z=adj(kth(e), 1);

			splay(y, 0);
			splay(z, y);

			int sRoot=son[z][L];
			son[z][L]=0;
			sz[z]-=sz[sRoot];
			sz[y]-=sz[sRoot];

			int x=kth(size());
			son[x][R]=sRoot;
			fa[sRoot]=x;
			sz[x]+=sz[sRoot];

			rev[sRoot]=!rev[sRoot];
		}
	}
}tree;

void random_data() {
	freopen("in", "w", stdout);
	srand((unsigned)time(NULL));

	int n=30, m=100;
	cout<<n<<" "<<m<<endl;
	while(m--) {
		int a=rand()%n+1;
		int b=rand()%n+1;
		if(a>b)
			swap(a, b);
		cout<<a<<" "<<b<<endl;
	}
}

void brute_force() {
	int var[103], buf[103], n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i) {
		var[i]=i;
	}

	int a, b;
	while(m--) {
		scanf("%d %d", &a, &b);
		int sz=0;
		for(int i=b; i>=a; --i) {
			buf[sz++]=var[i];
		}
		int p=a;
		for(int i=b+1; i<=n; ++i) {
			var[p++]=var[i];
		}
		for(int i=0; i<sz; ++i) {
			var[p++]=buf[i];
		}
	}

	for(int i=1; i<=n; ++i)
		cout<<var[i]<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
//	random_data();	return 0;
    freopen("in", "r", stdin);
//  brute_force();	return 0;
#endif

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i) {
    	tree.insert(i);
    }

    for(int i=0, s, e; i<m; ++i) {
    	scanf("%d %d", &s, &e);
    	tree.revTree(s, e);
    }

	tree.out(tree.root, false);

    return 0;
}

