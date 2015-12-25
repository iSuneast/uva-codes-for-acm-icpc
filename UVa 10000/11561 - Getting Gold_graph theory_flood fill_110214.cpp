/*
 * 11561 - Getting Gold
 *
 * graph theory..
 * flood fill..
 * 种子填充，搜索到(x,y)的时候，如果发现四周有'T'就不继续搜了
 * 写个dfs就够了~
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 53
using namespace std;

char g[MAXN][MAXN];
bool flag[MAXN][MAXN];
int key;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

void dfs(int x,int y) {
	if(flag[x][y] || g[x][y]=='#')
		return ;

	flag[x][y]=true;
	if(g[x][y]=='G')
		++key;

	for(int d=0;d<4;++d) {
		int tx=x+dx[d];
		int ty=y+dy[d];
		if(g[tx][ty]=='T')
			return ;
	}

	for(int d=0;d<4;++d) {
		int tx=x+dx[d];
		int ty=y+dy[d];
		dfs(tx,ty);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int n, m; scanf("%d %d", &m, &n)!=EOF; ) {
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;++i) {
			scanf("%s", g[i]);
		}

		bool bk=false;
		for(int i=0; i<n && !bk; ++i) {
			for(int j=0; j<m && !bk; ++j) {
				if(g[i][j]=='P') {
					key=0;
					dfs(i,j);
					bk=true;
				}
			}
		}

		printf("%d\n", key);
	}

	return 0;
}
