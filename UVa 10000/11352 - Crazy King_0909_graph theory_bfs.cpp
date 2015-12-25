/*
11352 - Crazy King

graph theory...
simple bfs...
*/

#include<iostream>
#include<queue>
#define MAXN 103
#define INF 0x3f3f3f3f
using namespace std;

char g[MAXN][MAXN];
int dis[MAXN][MAXN];
int m,n;
const int zDx[]={-2,-1,1,2,-2,-1,1,2};
const int zDy[]={1,2,2,1,-1,-2,-2,-1};
const int kDx[]={-1,0,1,-1,1,-1,0,1};
const int kDy[]={1,1,1,0,0,-1,-1,-1};
pair<int,int> bgn,end;

bool ok(int x,int y)
{
	return 0<x && x<=m && 0<y && y<=n;
}

int h(int x,int y)
{
	return x*MAXN+y;
}

int bfs()
{
	dis[bgn.first][bgn.second]=0;
	dis[end.first][end.second]=INF;

	queue<int> q;
	q.push(h(bgn.first,bgn.second));
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		int x=u/MAXN,y=u%MAXN;
		for(int d=0;d<8;++d)
		{
			int tx=x+kDx[d],ty=y+kDy[d];
			if(ok(tx,ty) && dis[tx][ty]==INF)
			{
				dis[tx][ty]=dis[x][y]+1;
				q.push(h(tx,ty));
			}
		}
	}

	return dis[end.first][end.second];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&m,&n);
		memset(dis,0x3f,sizeof(dis));

		for(int i=1;i<=m;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=n;++j)
			{
				if(g[i][j]=='Z')
				{
					dis[i][j]=-1;
					for(int d=0;d<8;++d)
					{
						int tx=i+zDx[d],ty=j+zDy[d];
						if(ok(tx,ty))
							dis[tx][ty]=-1;
					}
				}
				else if(g[i][j]=='A')
					bgn=make_pair(i,j);
				else if(g[i][j]=='B')
					end=make_pair(i,j);
			}
		}

		int key=bfs();
		if(key==INF)
			puts("King Peter, you can't go now!");
		else
			printf("Minimal possible length of a trip is %d\n",key);
	}

	return 0;
}
