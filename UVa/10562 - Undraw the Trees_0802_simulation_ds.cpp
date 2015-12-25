/*
10562 - Undraw the Trees

ds...
simulation
二叉树的模拟题...
直接dfs即可
注意树为空的情况

------------------------IN
1
#
------------------------OUT
()
------------------------END
*/

#include<iostream>
#define MAXN 210
using namespace std;

char g[MAXN][MAXN];
int sz;
bool hash[MAXN];

void dfs(int x,int y)
{
	putchar(g[x][y]);
	putchar('(');
	if(g[x+1][y]=='|')
	{
		int tx=x+2,ty=y;
		while(g[tx][ty]=='-')
			--ty;
		++ty;
		for(;g[tx][ty]=='-';++ty)
			if(!hash[ g[tx+1][ty] ])
				dfs(tx+1,ty);
	}
	putchar(')');
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(hash,0,sizeof(hash));
	hash['-']=hash[' ']=hash['|']=hash['#']=hash[0]=true;
	int dataset;
	scanf("%d",&dataset);gets(g[0]);
	while(dataset--)
	{
		sz=1;
		memset(g,0,sizeof(g));
		while(gets(g[sz]+1) && strcmp(g[sz]+1,"#"))
			++sz;
		g[sz][1]=0;
		if(sz==1)
		{
			puts("()");
			continue;
		}
		for(int i=1;g[1][i];++i)
			if(!hash[ g[1][i] ])
			{
				putchar('(');
				dfs(1,i);
				putchar(')');
			}
		putchar(10);
	}

	return 0;
}
