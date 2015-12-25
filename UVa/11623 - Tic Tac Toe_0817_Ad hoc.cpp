/*
11623 - Tic Tac Toe

Ad hoc...
给定一个棋盘,判定当前的状态

令o为'O'个数,x为'X'个数
又x先手,则必有o+1=x || o=x

如果x win,则枚举x的棋子,删除,判断棋盘局势
如果无论删除x的哪个棋子,x的状态一直是win,则error
对o同理

如果x win 并且o win,则error
如果两者都没有win的局势,判断棋盘满,则draw,否则IN PROGRESS

这么暴力的代码o(n^4*k)的复杂度,竟然排在rank 3...
*/

#include<iostream>
#define MAXN 1003
using namespace std;

int n,m;
char g[MAXN][MAXN];
bool error;

bool ok(int x,int y,int dx,int dy,char c)
{
	int cnt=0;
	while(g[x][y]==c && cnt<m)
	{
		x+=dx,y+=dy;
		++cnt;
	}
	return m==cnt;
}

bool win(char c)
{
	int bound=n-m+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(g[i][j]==c)
			{
				if(j<=bound && ok(i,j,0,1,c))
					return true;
				if(i<=bound && ok(i,j,1,0,c))
					return true;
				if(i<=bound && j<=bound && ok(i,j,1,1,c))
					return true;
			}
	return false;
}

bool chk(char c)
{
	if(!win(c))
		return false;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(g[i][j]==c)
			{
				g[i][j]=0;
				if(!win(c))
					return true;
				g[i][j]=c;
			}
	error=true;
	return false;
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
		int x=0,o=0;
		bool end=true;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=n;++j)
				if(g[i][j]!='.')
					g[i][j]=='O'?++o:++x;
				else
					end=false;
		}

		error=false;
		bool x_win=chk('X');
		bool o_win=chk('O');

		if((o+1!=x && o!=x) || error || (x_win && o_win))
			puts("ERROR");
		else if(!x_win && !o_win)
			puts(end?"DRAW":"IN PROGRESS");
		else if(x_win || o_win)
			puts(x_win?"X WINS":"O WINS");
		else
			puts("ERROR");
	}

	return 0;
}
