/*
10653 - Bombs! NO they are Mines!!

graph theory...
bfs...
简单的bfs...
做这种题最好把图画出来...
标好r,c与x,y的关系...
不然很容易逻辑错乱...
*/

#include<iostream>
#include<queue>
#define MAXN 1010
#define INF 0x7f7f7f7f
using namespace std;

int g[MAXN][MAXN],r,c,rows,t,x,y,ex,ey;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&r,&c)!=EOF && (r||c))
	{
		memset(g,0x7f,sizeof(g));
		scanf("%d",&rows);
		while(rows--)
		{
			scanf("%d",&x);
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&y);
				g[x][y]=-1;
			}
		}

		scanf("%d%d",&x,&y);
		scanf("%d%d",&ex,&ey);

		queue<int> q;
		int cur=x*MAXN+y;	g[x][y]=0;
		q.push(cur);
		while(!q.empty())
		{
			if(g[ex][ey]!=INF)
				break;
			cur=q.front();	q.pop();
			x=cur/MAXN;	y=cur%MAXN;
			for(int d=0;d<4;++d)
			{
				int tx=x+dx[d],ty=y+dy[d];
				if(tx>=0 && ty>=0 && tx<r && ty<c && g[tx][ty]==INF)
				{
					g[tx][ty]=g[x][y]+1;
					q.push(tx*MAXN+ty);
				}
			}
		}

		printf("%d\n",g[ex][ey]);
	}

	return 0;
}
