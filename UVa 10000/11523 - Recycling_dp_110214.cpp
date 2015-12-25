/*
 * 11523 - Recycling
 *
 * dp...
 * 非常裸的石子合并问题。。。
 * 因为题目没有认真看，以为垃圾也是可以拿出来丢掉的。。。
 * 于是WA了好多次。。。
 *
 * 垃圾是不可以拿出来的。
 * 那么问题其实就被垃圾隔成好多个小问题了，但是如果真的分解的话，会变得有点麻烦
 * 只要合并的时候看一下两者中间有没有垃圾就可以了，有垃圾是不能合并的。。。
 *
 * 代码其实和经典的石子合并一样，加了一句判断而已。。。
 *
 * happy coding~
 */

#include<iostream>
#include<map>
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;

int dp[MAXN][MAXN], var[MAXN], fa[MAXN];

void ChkMin(int &a,const int &t) {
	if(a>t)
		a=t;
}

int dfs(int s,int e) {
	if(dp[s][e]!=INF)
		return dp[s][e];
	else if(s==e)
		return dp[s][e]=(var[s]!=0);

	ChkMin(dp[s][e], dfs(s,e-1)+(var[e]!=0));
	for(int p=e; p && fa[p]>=s; p=fa[p]) {
		ChkMin( dp[s][e], dfs(s,fa[p])+dfs(fa[p]+1,e-1) );
	}

	return dp[s][e];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, h[MAXN];
	char buf[30];

	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		memset(var,-1,sizeof(var));
		map<string,int> msi;
		int t, sz=1, p, n=0;

		scanf("%d", &t);
		while(t--) {
			scanf("%s", buf);
			if( isupper( buf[0] ) ) {
				p=0;
			} else if(msi.find(buf)==msi.end()) {
				p=sz;
				msi[buf]=sz++;
			} else {
				p=msi[buf];
			}

			if(var[n] != p)
				var[++n]=p;
		}

		memset(h,0,sizeof(h));
		for(int i=1;i<=n;++i) {
			fa[i]=h[ var[i] ];
			for(int j=fa[i];j<=i;++j) {
				if(var[j]==0) {
					fa[i]=0;
					break;
				}
			}
			h[ var[i] ]=i;
		}

		memset(dp,0x3f,sizeof(dp));
		printf("Case %d: %d\n", cas, dfs(1,n) );
	}

	return 0;
}
