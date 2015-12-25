/*
10500 - Robot maps

graph theory...
dfs±©ËÑÒ»±é¼´¿É...
*/

#include<iostream>
#define MAXN 13
using namespace std;

char buf[3];
bool vis[MAXN][MAXN],g[MAXN][MAXN];
int n,m,x,y,pase;

void dfs(int x,int y)
{
	vis[x][y]=true;	++pase;
	if(x-1 && g[x-1][y] && !vis[x-1][y])
		dfs(x-1,y);
	else if(y+1<=m && g[x][y+1] && !vis[x][y+1])
		dfs(x,y+1);
	else if(x+1<=n && g[x+1][y] && !vis[x+1][y])
		dfs(x+1,y);
	else if(y-1 && g[x][y-1] && !vis[x][y-1])
		dfs(x,y-1);

	vis[x+1][y]=vis[x-1][y]=vis[x][y-1]=vis[x][y+1]=true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		scanf("%d%d",&x,&y);
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%s",buf);
				g[i][j]=(buf[0]=='0'?true:false);
			}

		pase=-1;
		dfs(x,y);

		putchar(10);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("|---");
			puts("|");

			for(int j=1;j<=m;++j)
				if(vis[i][j])
					printf("%s",g[i][j]?"| 0 ":"| X ");
				else
					printf("| ? ");
			puts("|");
		}

		for(int j=1;j<=m;++j)
			printf("|---");
		puts("|");

		printf("\nNUMBER OF MOVEMENTS: %d\n",pase);
	}

	return 0;
}
