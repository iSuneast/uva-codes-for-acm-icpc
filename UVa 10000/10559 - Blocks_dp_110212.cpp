/*
 * 10559 - Blocks
 *
 * dp...
 * 经典的石子合并问题~
 * dp[s,e,add]为区间[s,e]的石子加上
 *   后面区间传递下来add个stone[e]类型石子能获得的最大得分
 * 则,对于stone[e]这个石子,有两种选择
 *    一种是消去   dp[s][e][add] = dp[s][e-1][0] + score(add + 1)
 *    还有一种是和[s,e-1]的同类石子合并
 *              dp[s][e][add] = dp[s][i][add+1] + dp[i+1][e-1][0], s<=i && i+1<=e-1
 * 记忆化搜索即可,复杂度O(n^4)
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 203
using namespace std;

int id[MAXN], cnt[MAXN], sz;
int dp[MAXN][MAXN][MAXN], fa[MAXN], anc[MAXN];

void ChkMax(int &a, const int &t) {
	if(a < t)
		a = t;
}

int win(const int &t) {
	return t*t;
}

int dfs(int s,int e,int add) {
	if(dp[s][e][add] || s>e)
		return dp[s][e][add];
	ChkMax(dp[s][e][add], dfs(s,e-1,0)+win(add+cnt[e]) );
	for(int p=fa[e]; p>=s; p=fa[p]) {
		ChkMax(dp[s][e][add], dfs(s,p,add+cnt[e]) + dfs(p+1,e-1,0) );
	}
	return dp[s][e][add];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, pre, t, n;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas)	{
		memset(dp,0,sizeof(dp));
		memset(anc,0,sizeof(anc));
		pre=sz=0;

		scanf("%d", &n);
		for(int i=0; i<n; ++i,pre=t) {
			scanf("%d", &t);
			if(t==pre) {
				cnt[sz]++;
			} else {
				id[++sz]=t;
				cnt[sz]=1;
			}
		}

		for(int i=1; i<=sz; ++i) {
			fa[i] = anc[ id[i] ];
			anc[ id[i] ] = i;
		}

		printf("Case %d: %d\n", cas, dfs(1,sz,0));
	}

	return 0;
}
