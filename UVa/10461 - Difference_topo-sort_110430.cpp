/*
 * 10461 - Difference
 *
 * topo-sort
 * we can try to do the job as early as possible to get the minimum time
 * and if we try to do it as late as possible , we'll get the maximum time
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
#define MAXN 503
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

vector<int> edge[MAXN], rev[MAXN];
int w[MAXN], n, e;
bool flag[MAXN];

void dfs(const int &u, const vector<int> E[MAXN]) {
	flag[u]=true;
	for(int i=E[u].size()-1; i>=0; --i) {
		if(!flag[ E[u][i] ]) {
			dfs(E[u][i], E);
		}
	}
}

int chk(const int &u, const vector<int> E[MAXN]) {
	memset(flag, 0, sizeof(flag));
	dfs(u, E);
	int key=0;
	for(int i=1; i<=n; ++i) {
		if(flag[i] && i!=u)
			key+=w[i];
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for(int cas=1; scanf("%d %d", &n, &e)!=EOF && (n||e); ++cas) {
    	int sum=0;
    	for(int i=1; i<=n; ++i) {
    		scanf("%d", &w[i]);
    		sum+=w[i];
    		edge[i].clear();
    		rev[i].clear();
    	}
    	for(int u, v; e; --e) {
    		scanf("%d %d", &u, &v);
    		edge[u].push_back(v);
    		rev[v].push_back(u);
    	}
    	int q;
    	scanf("%d", &q);
    	printf("Case #%d:\n", cas);
    	for(int u; q; --q) {
    		scanf("%d", &u);
    		int minV=chk(u, edge);
    		int maxV=sum-w[u]-chk(u, rev);
    		printf("%d\n", maxV-minV);
    	}

    	putchar(10);
    }

    return 0;
}

