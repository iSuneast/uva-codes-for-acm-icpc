/*
 * 10779 - Collectors Problem
 *
 * graph theory~
 * max-flow
 * the main difficult of this problem is how to build the graph
 * I have describe it in my code
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
#define MAXN 100
#define MAXE 10000
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int n, m;

struct EDGE {
	int v, cap;
	EDGE *next, *rev;
}*edge[MAXN], data[MAXE], *curE[MAXN], *revE[MAXN];
int tot, src, snk, node;

void initG() {
	tot=0;
	src=0; snk=m+n+m+1;	node=snk+1;
	memset(edge, 0, sizeof(edge));
}

void makeE(EDGE *cur, EDGE *rev, int u, int v, int c) {
	cur->v=v;	cur->cap=c;	cur->rev=rev;
	cur->next=edge[u];	edge[u]=cur;
}

void link(int u, int v, int c) {
	makeE(&data[tot], &data[tot+1], u, v, c);
	makeE(&data[tot+1], &data[tot], v, u, 0);
	tot+=2;
}

int q[MAXN], dis[MAXN], cnt[MAXN];
void revBfs() {
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	int bgn=0, rear=0;
	q[rear++]=snk;	cnt[0]=1;	dis[snk]=0;
	while(bgn<rear) {
		int u=q[bgn++];
		for(EDGE *cur=edge[u]; cur; cur=cur->next) {
			if(dis[cur->v]==INF) {
				dis[cur->v]=dis[u]+1;
				cnt[ dis[cur->v] ]++;
				q[rear++]=cur->v;
			}
		}
	}

}

int augment() {
	int key=INF;
	for(int u=src; u!=snk; u=curE[u]->v) {
		key=min(key, curE[u]->cap);
	}

	for(int u=src; u!=snk; u=curE[u]->v) {
		curE[u]->cap -= key;
		curE[u]->rev->cap += key;
	}

	return key;
}

int isap() {
	revBfs();
	memcpy(curE, edge, sizeof(edge));

	int flow=0, u=src;
	while(dis[src]<=node) {
		if(u==snk) {
			flow+=augment();
			u=src;
		}

		EDGE *cur=curE[u];
		for( ; cur; cur=cur->next) {
			if(cur->cap && dis[cur->v]+1==dis[u])
				break;
		}

		if(cur) {
			curE[u]=cur;
			revE[cur->v]=cur->rev;
			u=cur->v;
		} else {
			if(!(--cnt[ dis[u] ]))
				break;

			curE[u]=edge[u];
			int d=node;
			for(cur=edge[u]; cur; cur=cur->next) {
				if(cur->cap) {
					d=min(d, dis[ cur->v ]);
				}
			}
			dis[u]=d+1;
			++cnt[ dis[u] ];

			if(u!=src)
				u=revE[u]->v;
		}
	}

	return flow;
}

int mat[13][28];

void build() {
   	initG();

   	for(int j=1; j<=m; ++j) {	// Bob have stick j
   		link(src, j, mat[1][j]);
   	}

   	int jmp=m;
   	for(int j=1; j<=m; ++j) {	// sticks
   		for(int i=2; i<=n; ++i) {	// people
   			if(!mat[i][j]) {	// people i don't have stick j
   				// he need at most 1
   				link(j, i+jmp, 1);
   			}
   		}
   	}

   	int jmp2=jmp+n;
   	for(int i=2; i<=n; ++i) {
   		for(int j=1; j<=m; ++j) {
   			if(mat[i][j]>1) {
   				// people i have more than 1 stick j
   				// he will keep at lease 1 sticks of this kind
   				link(i+jmp, j+jmp2, mat[i][j]-1);
   			}
   		}
   	}

   	for(int j=1; j<=m; ++j) {
   		// we just need to count how many different sticks Bob can have
   		link(j+jmp2, snk, 1);

   		// Bob will try to keep his sticks
   		link(j, j+jmp2, INF);

   		// Bob may try to change the sticks he already have
   		// Wrong Answer so many times because lack of this condition
   		link(j+jmp2, j, INF);
   	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &m);

    	memset(mat, 0, sizeof(mat));
    	for(int i=1, t, v; i<=n; ++i) {
    		scanf("%d", &t);
    		while(t--) {
    			scanf("%d", &v);
    			mat[i][v]++;
    		}
    	}

    	build();
    	printf("Case #%d: %d\n", cas, isap());
    }

    return 0;
}

