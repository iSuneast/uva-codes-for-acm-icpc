/*
114 - Simulation Wizardry

simulation...
直接模拟...
不过题目描述很不清楚啊...
边界是[1,n],[1,m]...
不是从0开始...

然后直接做就可以了...
题目不难,
以前做不出来只能说题目描述太BT...
*/

#include<iostream>
#define MAXN 55
using namespace std;

struct BUMPER
{
	int v,c;
}bumper[MAXN*MAXN];

struct BALL
{
	int x,y,dir,life;
}ball;

int n,m,cnt;
int g[MAXN][MAXN];

void bound()
{
	for(int x=0;x<=n;++x)
		g[x][1]=g[x][m]=0;
	for(int y=0;y<=m;++y)
		g[1][y]=g[n][y]=0;
}

void modify(int grid,int &key)
{
	ball.life-=bumper[grid].c;
	key+=bumper[grid].v;
	ball.dir=(ball.dir+3)%4;
}

int simulation()
{
	int key=0;

	while(ball.life>1)
	{
		--ball.life;
		if(ball.dir==0)
		{
			int grid=g[ ball.x+1 ][ ball.y ];
			if(grid!=-1)
				modify(grid,key);
			else
				++ball.x;
		}
		else if(ball.dir==1)
		{
			int grid=g[ ball.x ][ ball.y+1 ];
			if(grid!=-1)
				modify(grid,key);
			else
				++ball.y;
		}
		else if(ball.dir==2)
		{
			int grid=g[ ball.x-1 ][ ball.y ];
			if(grid!=-1)
				modify(grid,key);
			else
				--ball.x;
		}
		else if(ball.dir==3)
		{
			int grid=g[ ball.x ][ ball.y-1 ];
			if(grid!=-1)
				modify(grid,key);
			else
				--ball.y;
		}
	}

	printf("%d\n",key);
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	scanf("%d%d",&n,&m);
	scanf("%d",&bumper[0].c);
	bumper[0].v=0;

	memset(g,-1,sizeof(g));
	bound();

	scanf("%d",&cnt);
	int x,y;
	for(int i=1;i<=cnt;++i)
	{
		scanf("%d%d%d%d",&x,&y,&bumper[i].v,&bumper[i].c);
		g[x][y]=i;
	}

	int final=0;
	while(scanf("%d%d%d%d",&ball.x,&ball.y,&ball.dir,&ball.life)!=EOF)
		final+=simulation();
	printf("%d\n",final);

	return 0;
}
