/*
 * 10989 - Bomb, Divide and Conquer
 *
 * graph theory
 * stoer wagner min cut
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
#define MAXN 153
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int g[MAXN][MAXN], n, m;
int w[MAXN], id[MAXN];
bool flag[MAXN];

int SW() {
	for(int i=0; i<n; ++i) {
		id[i]=i;
	}

	int key=INF;
	while(n>1) {
		memset(flag, 0, sizeof(flag));
		memset(w, 0, sizeof(w));

		int pre, end;
		for(int p=0; p<n; ++p) {
			pre=end;
			end=-1;
			for(int i=0; i<n; ++i) {
				if(!flag[ id[i] ] && (end==-1 || w[ id[i] ]>w[ id[end] ]) ) {
					end=i;
				}
			}

			flag[ id[end] ]=true;
			for(int i=0; i<n; ++i) {
				if(!flag[ id[i] ])
					w[ id[i] ] += g[ id[end] ][ id[i] ];
			}
		}

		key=min(key, w[ id[end] ]);
		for(int i=0; i<n; ++i) {
			g[ id[i] ][ id[pre] ] = g[ id[pre] ][ id[i] ]
			= g[ id[i] ][ id[pre] ]+g[ id[i] ][ id[end] ];
		}
		id[ end ]=id[--n];
	}

	return key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &m);
    	memset(g, 0, sizeof(g));
    	for(int i=0, u, v, w; i<m; ++i) {
    		scanf("%d %d %d", &u, &v, &w);
    		--u;	--v;
    		g[u][v]=g[v][u]=g[u][v]+w;
    	}

    	printf("Case #%d: %d\n", cas, SW());
    }

    return 0;
}

