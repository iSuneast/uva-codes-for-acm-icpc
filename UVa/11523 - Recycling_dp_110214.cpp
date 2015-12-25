/*
 * 11523 - Recycling
 *
 * dp...
 * �ǳ����ʯ�Ӻϲ����⡣����
 * ��Ϊ��Ŀû�����濴����Ϊ����Ҳ�ǿ����ó��������ġ�����
 * ����WA�˺ö�Ρ�����
 *
 * �����ǲ������ó����ġ�
 * ��ô������ʵ�ͱ��������ɺö��С�����ˣ����������ķֽ�Ļ��������е��鷳
 * ֻҪ�ϲ���ʱ��һ�������м���û�������Ϳ����ˣ��������ǲ��ܺϲ��ġ�����
 *
 * ������ʵ�;����ʯ�Ӻϲ�һ��������һ���ж϶��ѡ�����
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
