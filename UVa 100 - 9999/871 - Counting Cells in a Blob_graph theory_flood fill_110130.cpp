/*
871 - Counting Cells in a Blob

graph theory...
flood fill...
竟然还有这种题....

happy coding~
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 30
using namespace std;

char g[MAXN][MAXN];
int n,m,cnt;

void dfs(int x,int y)
{
	if(g[x][y]!='1')
		return ;
	g[x][y]=0;
	++cnt;
	dfs(x+1,y); dfs(x-1,y);
	dfs(x+1,y-1); dfs(x-1,y-1); dfs(x,y-1);
	dfs(x+1,y+1); dfs(x-1,y+1); dfs(x,y+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);	gets(g[0]);	gets(g[0]);
	while(dataset--)
	{
		memset(g,0,sizeof(g));
		n=1;
		while(gets(g[n]+1) && g[n][1])
			++n;
		m=strlen(g[1]+1);

		int key=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(g[i][j]=='1')
				{
					cnt=0;
					dfs(i,j);
					key=max(key,cnt);
				}
			}
		}

		printf("%d\n",key);
		if(dataset)
			putchar(10);
	}

	return 0;
}
