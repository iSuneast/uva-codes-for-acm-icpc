/*
928 - Eternal Truths

graph theory...
bfs...
if not necessary, don't use STL...
it may cause u TLE

use dis[x][y][pase] to store the distance
then just simple bfs will do
*/

#include<iostream>
#define MAXN 303
using namespace std;
const int INF=0x3f3f3f3f;

struct PASE
{
	int x,y,pase;
};

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m,dis[MAXN][MAXN][4],front,rear;
char g[MAXN][MAXN];
PASE cur,e,q[MAXN*MAXN*3];

bool inside(int x,int y)
{
	return 0<x && x<=n && 0<y && y<=m;
}

void chk(PASE cur,int d)
{
	PASE key=cur;
	while(key.pase--)
	{
		key.x+=dx[d];
		key.y+=dy[d];
		if(!inside(key.x,key.y) || g[key.x][key.y]!='.')
			return ;
	}
	key.pase=cur.pase%3+1;

	if(dis[key.x][key.y][key.pase]>dis[cur.x][cur.y][cur.pase]+1)
	{
		dis[key.x][key.y][key.pase]=dis[cur.x][cur.y][cur.pase]+1;
		q[rear++]=key;
	}
}

int bfs()
{
	cur.pase=1;
	dis[cur.x][cur.y][1]=0;
	front=0,rear=0;
	q[rear++]=cur;

	while(front<rear)
	{
		cur=q[front++];
		for(int d=0;d<4;++d)
			chk(cur,d);
	}

	int key=INF;
	for(int i=1;i<=3;++i)
		key=min(key,dis[e.x][e.y][i]);
	return key;
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
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=m;++j)
			{
				for(int k=1;k<=3;++k)
					dis[i][j][k]=INF;
				if(g[i][j]=='S')
				{
					cur.x=i;	cur.y=j;
					g[i][j]='.';
				}
				else if(g[i][j]=='E')
				{
					e.x=i;	e.y=j;
					g[i][j]='.';
				}
			}
		}

		int key=bfs();
		if(key==INF)
			puts("NO");
		else
			printf("%d\n",key);
	}

	return 0;
}
