/*
10024 - Curling up the cube

simulation...
直接dfs模拟滚动即可...
最好拿个骰子来...
比较直观...
*/

#include<iostream>
#define MAXN 10
using namespace std;

int g[MAXN][MAXN],cnt;
bool flag[MAXN];

void dfs(int x,int y,int bottom,int front,int left)
{
	g[x][y]=0;
	flag[bottom]=true;
	++cnt;

	if(g[x+1][y])
		dfs(x+1,y,front,7-bottom,left);
	if(g[x-1][y])
		dfs(x-1,y,7-front,bottom,left);
	if(g[x][y-1])
		dfs(x,y-1,left,front,7-bottom);
	if(g[x][y+1])
		dfs(x,y+1,7-left,front,bottom);
}

bool chk()
{
	for(int i=1;i<=6;++i)
		for(int j=1;j<=6;++j)
			if(g[i][j]==1)
			{
				memset(flag,0,sizeof(flag));
				cnt=0;
				dfs(i,j,1,2,3);

				if(cnt!=6)
					return false;
				for(int k=1;k<=6;++k)
					if(!flag[k])
						return false;
				return true;
			}
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
		for(int i=1;i<=6;++i)
			for(int j=1;j<=6;++j)
				scanf("%d",&g[i][j]);
		if(chk())
			puts("correct");
		else
			puts("incorrect");
		if(dataset)
			putchar('\n');
	}

	return 0;
}
