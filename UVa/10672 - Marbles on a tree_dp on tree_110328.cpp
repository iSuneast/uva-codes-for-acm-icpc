/*
 * 10672 - Marbles on a tree
 *
 * dp on tree...
 * 树形dp
 * 写着写着，自己都不知道自己在写些什么，然后莫名其妙地就过了 = =
 *
 * 状态转移还是很显然的，
 * 对当前结点u，含有石头数N
 * 其所有子结点v，显然有dp[u]+=dp[v]
 * 如果v处剩下n个石头，累加到u的石头数N+=n，同时
 *     dp[u]+=n  // 把n个石头移上来
 * 或者v处需要n(n<0)个石头，也累加到u的石头数N+=n，同时
 *     dp[u]+=-n // 把n个石头移下去
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
#define MAXN 10003
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

vector<int> son[MAXN];
int n, sz[MAXN], cnt[MAXN], dp[MAXN];

void dfs(int u) {
	dp[u]=0;
	cnt[u]--;

	for(int i=0; i<sz[u]; ++i) {
		int v=son[u][i];

		dfs(v);
		dp[u]+=dp[v];

		if(cnt[v]) {
			cnt[u]+=cnt[v];
			dp[u]+=(cnt[v]<0? -cnt[v]: cnt[v]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d", &n)!=EOF && n) {
    	int root=n*(n+1)>>1;
    	for(int i=1, u; i<=n; ++i) {
    		scanf("%d", &u);
    		scanf("%d %d", &cnt[u], &sz[u]);

    		son[u].clear();
    		for(int j=0, v; j<sz[u]; ++j) {
    			scanf("%d", &v);
    			root-=v;
    			son[u].push_back(v);
    		}
    	}

    	dfs(root);
    	printf("%d\n", dp[root]);
    }

    return 0;
}

