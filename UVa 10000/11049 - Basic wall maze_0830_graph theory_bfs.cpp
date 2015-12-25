/*
11049 - Basic wall maze

graph theory...
bfs...
while slack the distance, store the father direction...
don't use backtrack to find the path or you'll get WA
you can verify it use below test data

3 6
6 2
0 3 3 3
1 2 6 2
0 4 4 4
EENNWNWWWNEEEEE
*/

#include<iostream>
#include<queue>
#include<set>
#define MAXN 10
#define L 0
#define R 1
#define U 2
#define D 3
using namespace std;
const int INF=0x3f3f3f3f;

struct POINT
{
	int x,y;
}s,e,w1,w2;

int g[MAXN][MAXN],fa[MAXN][MAXN];
set<int> si;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
const char key[]="SNEW";

int hash(int x,int y)
{
	return x*MAXN+y;
}

void bfs()
{
	queue<int> q;
	memset(fa,-1,sizeof(fa));
	q.push(hash(s.x,s.y));
	while(!q.empty())
	{
		int cur=q.front();	q.pop();
		int x=cur/MAXN,y=cur%MAXN;
		for(int d=0;d<4;++d)
		{
			int tx=x+dx[d],ty=y+dy[d];
			if(tx && tx<=6 && ty && ty<=6 && g[tx][ty]>g[x][y]+1
				&& si.find( hash(tx,ty)*100+hash(x,y) )==si.end())
			{
				g[tx][ty]=g[x][y]+1;
				fa[tx][ty]=d;
				q.push(hash(tx,ty));
			}
		}
	}
}

void dfs(int x,int y)
{
	if(fa[x][y]==-1)
		return ;
	int tx=x-dx[ fa[x][y] ],ty=y-dy[ fa[x][y] ];
	dfs(tx,ty);
	putchar(key[ fa[x][y] ]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&s.x,&s.y)!=EOF && (s.x||s.y))
	{
		scanf("%d%d",&e.x,&e.y);

		memset(g,0x3f,sizeof(g));
		g[s.x][s.y]=0;
		si.clear();

		for(int i=0;i<3;++i)
		{
			scanf("%d%d%d%d",&w1.x,&w1.y,&w2.x,&w2.y);
			if(w1.x==w2.x)
			{
				if(w1.y>w2.y)
					swap(w1.y,w2.y);
				for(int j=w1.y+1;j<=w2.y;++j)
				{
					si.insert( hash(w1.x,j)*100 + hash(w1.x+1,j) );
					si.insert( hash(w1.x+1,j)*100 + hash(w1.x,j) );
				}
			}
			else
			{
				if(w1.x>w2.x)
					swap(w1.x,w2.x);
				for(int j=w1.x+1;j<=w2.x;++j)
				{
					si.insert( hash(j,w1.y)*100 + hash(j,w1.y+1) );
					si.insert( hash(j,w1.y+1)*100 + hash(j,w1.y) );
				}
			}
		}

		bfs();
		dfs(e.x,e.y);
		putchar(10);
	}

	return 0;
}
