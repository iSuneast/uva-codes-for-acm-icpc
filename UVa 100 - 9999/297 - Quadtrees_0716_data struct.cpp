/*
297 - Quadtrees

data struct...
四叉树...
规模这么小,直接搜索...
然后填充即可...
*/

#include<iostream>
#define MAXN 32
using namespace std;

bool g[MAXN+3][MAXN+3];
char s[MAXN*MAXN*2];
int p;

void dfs(int x,int y,int jump)
{
	if(s[p]=='p')
	{
		++p;
		dfs(x,y,jump/2);
		dfs(x+jump/2,y,jump/2);
		dfs(x,y+jump/2,jump/2);
		dfs(x+jump/2,y+jump/2,jump/2);
	}
	else if(s[p++]=='f')
	{
		for(int i=x;i<x+jump;++i)
			for(int j=y;j<y+jump;++j)
				g[i][j]=true;
	}
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
		memset(g,0,sizeof(g));
		scanf("%s",s);	p=0;
		dfs(1,1,MAXN);
		scanf("%s",s);	p=0;
		dfs(1,1,MAXN);

		int key=0;
		for(int i=1;i<=MAXN;++i)
			for(int j=1;j<=MAXN;++j)
				if(g[i][j])
					++key;
		printf("There are %d black pixels.\n",key);
	}

	return 0;
}
