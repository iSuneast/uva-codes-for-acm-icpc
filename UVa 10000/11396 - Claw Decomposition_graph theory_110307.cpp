/*
 * 11396 - Claw Decomposition
 *
 * graph theory...
 * bi-color
 *
 * notice that:
 * "every vertex has degree 3"
 * "define claw as K(1,3)"
 *
 * every node has degree 3, so for node u
 * there are three and only three edges
 * (u, v1), (u, v2), (u, v3)
 * if these three edge belong to u, we should leave v1, v2, v3 alone
 *
 * so, you can transform this problem to
 * if we select node u, we shouldn't select it's neighbors
 * in fact, a bi-color problem...
 *
 * happy coding~
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#define MAXN 303
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct EDGE {
	int v;
	EDGE *next;
}*edge[MAXN], data[MAXN*MAXN];
int n, tot, color[MAXN];

void link(const int &u, const int &v) {
	data[tot].v=v;
	data[tot].next=edge[u];
	edge[u]=&data[tot++];
}

bool dfs(const int &u, const int &c) {
	color[u]=c;
	--n;
	for(EDGE *cur=edge[u]; cur; cur=cur->next) {
		if(!color[ cur->v ]) {
			if( !dfs(cur->v, -c) )
				return false;
		} else if(color[cur->v]==c)
			return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int u, v;
    while(scanf("%d", &n)!=EOF && n) {
    	memset(edge, 0, sizeof(edge));
    	memset(color, 0, sizeof(color));
    	tot=0;
    	while(scanf("%d%d", &u, &v)!=EOF && (u||v)) {
    		link(u,v);
    		link(v,u);
    	}

    	puts(dfs(1, 1) && !n? "YES": "NO");
    }

    return 0;
}

