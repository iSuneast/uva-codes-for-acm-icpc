/*
 * 10160 - Servicing Stations
 *
 * complete search~
 * dancing links
 *
 * 重复覆盖
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
#define MAXN 36
#define NODE MAXN*MAXN
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct DLX {
	int u[NODE], d[NODE], l[NODE], r[NODE], row[NODE], col[NODE];
	int s[MAXN], tot, c, key, h[NODE];
	int flag[MAXN], kth;

	void init(const int &_c) {
		c=_c;
		for(int i=0; i<=c; ++i) {
			l[i]=i-1;	r[i]=i+1;
			col[i]=u[i]=d[i]=i;
		}
		l[0]=c;	r[c]=0;

		memset(s, 0, sizeof(s));
		memset(h, -1, sizeof(h));
		s[0]=INF;
		tot=c+1;

		memset(flag, 0, sizeof(flag));
		kth=0;
	}

	int H() {
		++kth;
		int ret=0;
		for(int i=r[0]; i; i=r[i]) {
			if(flag[i]!=kth) {
				++ret;
				flag[i]=kth;
				for(int j=d[i]; j!=i; j=d[j]) {
					for(int k=r[j]; k!=j; k=r[k]) {
						flag[ col[k] ]=kth;
					}
				}
			}
		}
		return ret;
	}

	void remove(int c) {
		for(int i=d[c]; i!=c; i=d[i]) {
			l[ r[i] ]=l[i];
			r[ l[i] ]=r[i];
			s[ col[i] ]--;
		}
	}

	void resume(int c) {
		for(int i=u[c]; i!=c; i=u[i]) {
			l[ r[i] ]=r[ l[i] ]=i;
			s[ col[i] ]++;
		}
	}

	void add(const int &i, const int &j) {
		row[tot]=i;
		col[tot]=j;

		u[tot]=j;
		d[tot]=d[j];
		u[ d[j] ]=tot;
		d[j]=tot;

		if(h[i]==-1) {
			h[i]=tot;
			l[tot]=r[tot]=tot;
		} else {
			l[tot]=h[i];
			r[tot]=r[ h[i] ];
			l[ r[ h[i] ] ]=tot;
			r[ h[i] ]=tot;
		}

		++s[j];
		++tot;
	}

	bool dfs(int dep) {
		if(dep+H()>key)
			return false;
		if(!r[0])
			return true;

		int idx=0;
		for(int i=r[0]; i; i=r[i]) {
			if(s[i]<s[idx]) {
				idx=i;
			}
		}

		for(int i=d[idx]; i!=idx; i=d[i]) {
			remove(i);
			for(int j=r[i]; j!=i; j=r[j]) {
				remove(j);
			}
			if(dfs(dep+1))
				return true;
			for(int j=l[i]; j!=i; j=l[j]) {
				resume(j);
			}
			resume(i);
		}
		return false;
	}
}dlx;


int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m, u, v;
    while(scanf("%d %d", &n, &m)!=EOF && (n||m)) {
    	dlx.init(n);
    	for(int i=1; i<=n; ++i) {
    		dlx.add(i, i);
    	}
    	for(int i=0; i<m; ++i) {
    		scanf("%d %d", &u, &v);
    		dlx.add(u, v);
    		dlx.add(v, u);
    	}

    	dlx.key=1;
    	while(!dlx.dfs(0))
    		++dlx.key;

    	printf("%d\n", dlx.key);
    }

    return 0;
}

