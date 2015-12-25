/*
10443 - Rock

simulation...
模拟题...
省赛前练练手...
*/

#include<iostream>
#define MAXN 110
using namespace std;

char g[2][MAXN][MAXN];
int r,c,n;

char judge(int x,int y,int cur,char c)
{
	switch(c)
	{
		case 'R':
			if(g[cur][x+1][y]=='P' || g[cur][x][y+1]=='P'
				 || g[cur][x-1][y]=='P' || g[cur][x][y-1]=='P')
				 return 'P';
			return 'R';
		case 'S':
			if(g[cur][x+1][y]=='R' || g[cur][x][y+1]=='R'
				|| g[cur][x-1][y]=='R' || g[cur][x][y-1]=='R')
				return 'R';
			return 'S';
		case 'P':
			if(g[cur][x+1][y]=='S' || g[cur][x][y+1]=='S'
				|| g[cur][x-1][y]=='S' || g[cur][x][y-1]=='S')
				return 'S';
			return 'P';
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
		scanf("%d%d%d",&r,&c,&n);
		memset(g,0,sizeof(g));
		for(int i=1;i<=r;++i)
			scanf("%s",g[0][i]+1);
		int cur=0;
		while(n--)
		{
			cur=1-cur;
			for(int i=1;i<=r;++i)
				for(int j=1;j<=c;++j)
					g[cur][i][j]=judge(i,j,1-cur,g[1-cur][i][j]);
		}
		for(int i=1;i<=r;++i)
			puts(g[cur][i]+1);
		if(dataset)
			putchar('\n');
	}

	return 0;
}
