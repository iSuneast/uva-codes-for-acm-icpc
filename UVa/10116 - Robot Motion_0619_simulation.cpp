/*
10116 - Robot Motion

simulation...
Ö±½ÓÄ£Äâ...
*/

#include<iostream>
#define MAXN 13
using namespace std;

char grid[MAXN][MAXN];
int dis[MAXN][MAXN],r,c,p;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d%d",&r,&c,&p)!=EOF && (r||c||p))
	{
		gets(grid[0]);
		memset(grid,0,sizeof(grid));
		memset(dis,-1,sizeof(dis));

		for(int i=1;i<=r;++i)
			gets(grid[i]+1);

		bool loop=false;
		int x=1,y=p,d=0;
		dis[x][y]=d;

		while(true)
		{
			if(!x || !y || x>r || y>c)
				break;
			if(grid[x][y]=='N')
				--x;
			else if(grid[x][y]=='S')
				++x;
			else if(grid[x][y]=='E')
				++y;
			else if(grid[x][y]=='W')
				--y;

			if(dis[x][y]==-1)
				dis[x][y]=++d;
			else
			{
				loop=true;
				break;
			}
		}

		if(loop)
			printf("%d step(s) before a loop of %d step(s)\n",dis[x][y],d-dis[x][y]+1);
		else
			printf("%d step(s) to exit\n",d);
	}



	return 0;
}
