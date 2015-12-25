/*
 * 321 - The New Villa
 *
 * graph theory...
 * sssp...
 * bitmask
 *
 * using bitmask to store the state and extended
 * and then just simulation as the problem description
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
#define MAXN 10
#define MERGE(s, u) ((s)|(1<<(u)))
#define DELETE(s, u) ((s)^(1<<(u)))
#define INSIDE(s, u) ((s)&(1<<(u)))
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct ANSWER {
	int room, state, op, what;
	ANSWER(){}
	ANSWER(int r, int s, int o, int w) :
		room(r), state(s), op(o), what(w+1) {}
} fa[MAXN][1<<MAXN];

bool ctrl[MAXN][MAXN], g[MAXN][MAXN], inq[MAXN][1<<MAXN];
int r, d, s, dis[MAXN][1<<MAXN];

typedef pair<int, int> pii;
queue< pii > q;

void Slack(int u, int s, int d, ANSWER pre) {
	if(dis[u][s]<d)
		return ;
	fa[u][s]=pre;
	dis[u][s]=d;
	if(!inq[u][s]) {
		q.push( make_pair(u, s) );
		inq[u][s]=true;
	}
}

void dfs(int u, int s) {
	if(u==0 && s==1)
		return ;
	dfs( fa[u][s].room, fa[u][s].state );

	if(fa[u][s].op==0)
		printf("- Move to room %d.\n", fa[u][s].what);
	else if(fa[u][s].op==1)
		printf("- Switch on light in room %d.\n", fa[u][s].what);
	else
		printf("- Switch off light in room %d.\n", fa[u][s].what);
}

void spfa() {
	memset(dis, 0x3f, sizeof(dis));
	Slack(0, MERGE(0, 0), 0, ANSWER(0, 0, 0, 0));

	while(!q.empty()) {
		pii cur=q.front();	q.pop();
		int room=cur.first, state=cur.second, d=dis[room][state]+1;
		inq[room][state]=false;

		for(int p=0; p<r; ++p) {
			if(g[room][p] && INSIDE(state, p)) {
				Slack(p, state, d, ANSWER(room, state, 0, p));
			}
		}

		for(int l=0; l<r; ++l) {
			if(ctrl[room][l] && !INSIDE(state, l)) {
				Slack(room, MERGE(state,l), d, ANSWER(room, state, 1, l));
			}
		}

		for(int l=0; l<r; ++l) {
			if(ctrl[room][l] && INSIDE(state, l) && l!=room) {
				Slack(room, DELETE(state,l), d, ANSWER(room, state, 2, l));
			}
		}
	}

	if(dis[r-1][ MERGE(0, r-1) ]==INF)
		puts("The problem cannot be solved.");
	else {
		printf("The problem can be solved in %d steps:\n", dis[r-1][ MERGE(0, r-1) ]);
		dfs(r-1, MERGE(0, r-1));
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int cas=1, u, v;
    while(scanf("%d %d %d", &r, &d, &s)!=EOF && (r||d||s)) {
    	memset(g, 0, sizeof(g));
    	for(int i=0; i<d; ++i) {
    		scanf("%d %d", &u, &v);
    		--u;	--v;
    		g[u][v]=g[v][u]=true;
    	}

    	memset(ctrl, 0, sizeof(ctrl));
    	for(int i=0; i<s; ++i) {
    		scanf("%d %d", &u, &v);
    		--u;	--v;
    		ctrl[u][v]=true;
    	}

        printf("Villa #%d\n", cas++);
        spfa();
        putchar(10);
    }

    return 0;
}

