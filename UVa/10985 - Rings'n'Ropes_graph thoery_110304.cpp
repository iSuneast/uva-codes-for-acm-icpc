/*
 * 10985 - Rings'n'Ropes
 *
 * graph theory...
 * bfs...
 * in fact, this problem should have a better than O(N^2*E) brute force
 *
 * even though, an O(N^2*E) solution is enough to past the time limit
 * we can initialization the distance between any two nodes
 * then enum start and end pair (s, e)
 *    for every edge(u, v) check whether
 *       dis[s][u]+dis[v][e]+1==dis[s][e] ||
 *       dis[s][v]+dis[u][e]+1==dis[s][e]
 *       if it does, then ++your answer
 * refresh your answer
 *
 * happy coding
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
#define MAXN 123
#define MAXE 10000
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct EDGE {
	int u, v;
}edge[MAXE];

int dis[MAXN][MAXN];
bool g[MAXN][MAXN];
int n, m, q[MAXN];

void bfs(int u, int d[MAXN]) {
	memset(d, 0x3f, sizeof(int)*MAXN);
	d[u]=0;
	int front=0, rear=0;
	q[rear++]=u;
	while(front<rear) {
		u=q[front++];
		for(int v=0; v<n; ++v) {
			if(g[u][v] && d[v]==INF) {
				d[v]=d[u]+1;
				q[rear++]=v;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset, u, v;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	memset(g, 0, sizeof(g));
    	scanf("%d%d", &n, &m);

    	for(int i=0; i<m; ++i) {
    		scanf("%d%d", &u, &v);
    		edge[i].u=u;
    		edge[i].v=v;
    		g[u][v]=g[v][u]=true;
    	}

    	for(int i=0; i<n; ++i) {
    		bfs(i, dis[i]);
    	}

    	int key=0;
    	for(int s=0; s<n; ++s) {
    		for(int e=s+1; e<n; ++e) {
        		int t=0;
        		for(int p=0; p<m; ++p) {
        			u=edge[p].u;
        			v=edge[p].v;
        			if( dis[s][u]+dis[v][e]+1==dis[s][e] ||
        				dis[s][v]+dis[u][e]+1==dis[s][e])
        				++t;
        		}
    			key=max(key, t);
    		}
    	}

    	printf("Case #%d: %d\n", cas, key);
    }

    return 0;
}

