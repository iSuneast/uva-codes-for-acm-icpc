/*
260 - Il Gioco dell'X

graph theory..
flood fill...
传说中的种子填充法...
填一个就可以了...
题目说至少一个有解...
*/

#include<iostream>
#define MAXN 205
using namespace std;

const int dx[]={-1,-1,0,0,1,1};
const int dy[]={-1,0,-1,1,0,1};
char g[MAXN][MAXN];
bool flag[MAXN][MAXN];
int n;

void dfs(int x,int y)
{
	if(flag[x][y] || g[x][y]!='b')
		return ;
	flag[x][y]=true;
	for(int i=0;i<6;++i)
		dfs(x+dx[i],y+dy[i]);
}

bool chk()
{
	for(int i=1;i<=n;++i)
		if(flag[n][i])
			return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(g,0,sizeof(g));
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;++i)
			scanf("%s",g[i]+1);
		for(int i=1;i<=n;++i)
			if(g[1][i]=='b')
				dfs(1,i);

		if(chk())
			printf("%d B\n",cas++);
		else
			printf("%d W\n",cas++);
	}

	return 0;
}
