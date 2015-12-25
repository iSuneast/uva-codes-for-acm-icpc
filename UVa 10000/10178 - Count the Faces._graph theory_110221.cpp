/*
 * 10178 - Count the Faces.
 *
 * graph theory...
 * 首先，必须能观察到，图可能是不连通的
 * 其次，图可能有自环 && 重边
 * 然后，没了 = =
 * 用欧拉公式 V+F-E=2  （点+面-线=2）即可～
 *
 * happy coding～
 */

#include<cstdio>
#include<cstring>
#define MAXN 128
using namespace std;

bool flag[MAXN];
int node, edge, g[MAXN][MAXN];

void dfs(int u) {
	flag[u]=true;
	++node;

	for(int v=0; v<MAXN; ++v) {
		if(!g[u][v])
			continue;
		edge+=g[u][v];
		g[u][v]=g[v][u]=0;
		if(!flag[v])
			dfs(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n, e;
    while( scanf("%d%d", &n, &e)!=EOF) {
    	char a[2], b[2];
    	memset(g, 0, sizeof(g));
    	memset(flag, 0, sizeof(flag));
    	for(int i=0; i<e; ++i) {
    		scanf("%s%s", a, b);
    		g[ a[0] ][ b[0] ]++;
    		if( a[0]!=b[0] )		//self - loop
    			g[ b[0] ][ a[0] ]++;
    	}

    	int key=1;
    	for(int i=0; i<MAXN; ++i) {
    		if(!flag[i]) {
    			node=edge=0;
    			dfs(i);
    			if(edge)
    				key += edge+1-node;
    		}
    	}

    	printf("%d\n", key);
    }

    return 0;
}

