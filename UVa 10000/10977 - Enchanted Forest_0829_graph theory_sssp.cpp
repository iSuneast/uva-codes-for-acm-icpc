/*
10977 - Enchanted Forest

graph theory...
sssp...
this is quite a simple problem...
but a have make a lot of mistakes such as spelling and variable error...

fill the block with INF at first...
then mark the illegal block with -INF so that we won't slack it later
use simple bfs to find the shortest path...
be careful when the source is unavailable at first ,
we should output impossible instead of init it with variable 0...
*/

#include<iostream>
#include<queue>
#define MAXN 205
#define INF 0x3f3f3f3f
using namespace std;

int r,c,m,n,x,y,l;
int g[MAXN][MAXN];
const int dx[]={-1,1,0,0},dy[]={0,0,1,-1};

struct Jigglypuffs
{
	int x,y,l;
}data[MAXN];

int sqr(int var)
{
	return var*var;
}

void spfa()
{
	if(g[1][1]!=INF || g[r][c]!=INF)
	{
		puts("Impossible.");
		return ;
	}

	g[1][1]=0;
	queue<int> q;	q.push(1*MAXN+1);
	while(!q.empty())
	{
		x=q.front()/MAXN,y=q.front()%MAXN;	q.pop();
		for(int d=0;d<4;++d)
		{
			int tx=x+dx[d],ty=y+dy[d];
			if(0<tx && tx<=r && 0<ty && ty<=c && g[tx][ty]>g[x][y]+1)
			{
				g[tx][ty]=g[x][y]+1;
				q.push(tx*MAXN+ty);
			}
		}
	}

	if(g[r][c]==INF)
		puts("Impossible.");
	else
		printf("%d\n",g[r][c]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&r,&c)!=EOF && (r||c))
	{
		memset(g,0x3f,sizeof(g));
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&x,&y);
			g[x][y]=-INF;
		}
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].l);
			data[i].l*=data[i].l;
			g[ data[i].x ][ data[i].y ]=-INF;
		}

		for(int i=1;i<=r;++i)
		{
			for(int j=1;j<=c;++j)
				if(g[i][j]==INF)
					for(int k=0;k<n;++k)
						if(sqr(data[k].x-i)+sqr(data[k].y-j)<=data[k].l)
						{
							g[i][j]=-INF;
							break;
						}
		}
		spfa();
	}

	return 0;
}
