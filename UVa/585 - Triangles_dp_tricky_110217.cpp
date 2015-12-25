/*
 * 585 - Triangles
 *
 * dp...
 * 非常简单，也非常tricky的DP题。。。
 * 看一组数据
 * 5
 * #########
 *  #---###
 *   #-###
 *    ###
 *     #
 * 很显然，第一眼看过去就知道答案是4
 * 然后把这张图画出来就是
 * -------------------
 * \#/#\#/#\#/#\#/#\#/
 *  -----------------
 *   \#/ \ / \#/#\#/
 *    -------------
 *     \#/ \#/#\#/
 *      ---------
 *       \#/#\#/
 *        -----
 *         \#/
 *          -
 * 好吧，你应该承认你错了。。。答案应该是1，不是4。。。
 * 所以，状态转移的时候还要加上格子位置的奇偶判定
 * 从上往下，从下往上各扫描一遍就可以了~
 *
 * happy coding~
 */


#include<iostream>
#include<cmath>
#define MAXN 103
using namespace std;
const double eps=1e-9;

char g[103][MAXN*2];
int dp[103][MAXN*2], n;

bool same(int a,int b) {
	return (a-b)%2==0;
}

int DynamicP() {
	int key=0;

	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; ++i) {
		int pre=i-1, cur=i;
		for(int j=i; g[cur][j]; ++j) {
			if(g[cur][j]!='-')
				continue;
			int t=min(dp[pre][j-1],dp[pre][j+1]);
			if( g[pre][j]!='-'  || !same(i,j))
				t=0;
			dp[cur][j]=pow(sqrt(t+eps)+1.0, 2.0);
			key=max(key, dp[cur][j]);
		}
	}

	memset(dp, 0, sizeof(dp));
	for(int i=n; i>0; --i) {
		int pre=i+1, cur=i;
		for(int j=i; g[cur][j]; ++j) {
			if(g[cur][j]!='-')
				continue;
			int t=min(dp[pre][j-1],dp[pre][j+1]);
			if( g[pre][j]!='-'  || same(i,j))
				t=0;
			dp[cur][j]=pow(sqrt(t+eps)+1.0, 2.0);
			key=max(key, dp[cur][j]);
		}
	}

	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int cas=1; scanf("%d", &n)!=EOF && n; ++cas) {
		memset(g, 0, sizeof(g));
		for(int i=1; i<=n; ++i) {
			scanf("%s", g[i]+i);
		}

		printf("Triangle #%d\n", cas);
		printf("The largest triangle area is %d.\n\n", DynamicP());
	}

	return 0;
}
