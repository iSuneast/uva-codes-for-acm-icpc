/*
10452 - Marcus

DFS..
*/

#include<iostream>
#define MAXN 10
using namespace std;

const char hash[]="@IEHOVA#";
char g[MAXN][MAXN],key[MAXN];

bool dfs(int x,int y,int dep)
{
	if(dep>7)
		return true;
	if(g[x][y]!=hash[dep])
		return false;
	key[dep]=8;
	if(dfs(x-1,y,dep+1))
		return true;
	key[dep]=4;
	if(dfs(x,y-1,dep+1))
		return true;
	key[dep]=6;
	if(dfs(x,y+1,dep+1))
		return true;
	return false;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=m;++j)
				if(g[i][j]=='@')
				{
					x=i;
					y=j;
				}
		}
		dfs(x,y,0);
		for(int i=0;i<7;++i)
		{
			if(i)
				putchar(' ');
			if(key[i]==8)
				printf("forth");
			else if(key[i]==4)
				printf("left");
			else if(key[i]==6)
				printf("right");
		}
		putchar('\n');
	}

	return 0;
}
