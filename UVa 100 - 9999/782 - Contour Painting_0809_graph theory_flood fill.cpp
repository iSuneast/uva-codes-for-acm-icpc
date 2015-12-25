/*
782 - Contour Painting

graph theory...
flood fill...
种子填充...
莫名其妙的就过了...
*/

#include<iostream>
#define MAXX 40
#define MAXY 86
using namespace std;

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char g[MAXX][MAXY];
bool flag[MAXX][MAXY];
int sz;

void dfs(int x,int y)
{
	if(g[x][y]!=' ' || flag[x][y] || x<=0 || x>=MAXX || y<=0 || y>=MAXY)
		return ;
	flag[x][y]=true;
	dfs(x+1,y);	dfs(x-1,y);
	dfs(x,y+1);	dfs(x,y-1);
}

void init()
{
	for(int i=0;i<MAXX;++i)
		for(int j=0;j<MAXY;++j)
			g[i][j]=' ';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);gets(g[0]);
	while(dataset--)
	{
		init();
		memset(flag,0,sizeof(flag));
		sz=1;
		int x,y,p;
		while(gets(g[sz]+1) && g[sz][1]!='_')
		{
			p=1;
			while(g[sz][p])
			{
				if(g[sz][p]=='*')
				{
					x=sz,y=p;
					g[sz][p]=' ';
				}
				++p;
			}
			g[sz][p]=' ';
			++sz;
		}

		dfs(x,y);

		for(int i=1;i<sz;++i)
		{
			for(int j=1;j<MAXY;++j)
				if(g[i][j]!='*' && g[i][j]!=' ' && g[i][j]!='#' && g[i][j]!='_')
					for(int d=0;d<4;++d)
					{
						int tx=i+dx[d],ty=j+dy[d];
						if(flag[tx][ty] && g[tx][ty]==' ')
							g[tx][ty]='#';
					}
		}

		for(int i=1;i<=sz;++i)
		{
			int j;
			for(j=MAXY-1;j;--j)
				if(g[i][j]!=' ')
				{
					g[i][j+1]=0;
					break;
				}
			if(!j)
				putchar(10);
			else
				puts(g[i]+1);
		}
	}

	return 0;
}
