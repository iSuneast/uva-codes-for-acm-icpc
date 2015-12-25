/*
 * 758 - The Same Game
 * 
 * Ad hoc...
 * simulation...
 * just do as the problem description...
 * no trick...
 * 
 * happy coding ...
 */

#include<cstdio>
#include<cstring>
#define MAX_C 15
#define MAX_R 10
using namespace std;

struct SAME_GAME
{
	char board[MAX_R+3][MAX_C+3];
	bool flag[MAX_R+3][MAX_C+3];
	void read()
	{
		memset(board,0,sizeof(board));
		for(int i=MAX_R;i;--i)
			scanf("%s",board[i]+1);
	}
	
	struct CUBE
	{
		int x,y,n;
	};
	
	int cnt;
	void dfs(int x,int y,char c)
	{
		if(board[x][y]!=c || flag[x][y])
			return ;
		flag[x][y]=true;
		++cnt;
		dfs(x+1,y,c);
		dfs(x,y+1,c);
		dfs(x-1,y,c);
		dfs(x,y-1,c);
	}
	
	CUBE select()
	{
		CUBE key;	key.n=0;
		memset(flag,0,sizeof(flag));
		for(int j=1;j<=MAX_C;++j)
		{
			for(int i=1;i<=MAX_R;++i)
			{
				if(board[i][j] && !flag[i][j])
				{
					cnt=0;
					dfs(i,j,board[i][j]);
					if(cnt>key.n)
					{
						key.n=cnt;
						key.x=i;	key.y=j;
					}
				}
			}
		}
		
		return key;
	}
	
	void tout()
	{
		for(int i=1;i<=MAX_R;++i)
		{
			for(int j=1;j<=MAX_C;++j)
				if(!board[i][j])
					printf(" ");
				else
					putchar(board[i][j]);
			putchar(10);
		}
		putchar(10);
	}
	
	void remove(CUBE &pos)
	{
		memset(flag,0,sizeof(flag));
		dfs(pos.x, pos.y, board[pos.x][pos.y]);
		for(int j=1;j<=MAX_C;++j)
		{
			int p=1;
			for(int i=1;i<=MAX_R;++i)
			{
				if(!flag[i][j])
					board[p++][j]=board[i][j];
			}
			for(;p<=MAX_R;++p)
				board[p][j]=0;
		}
		
		int p=1;
		for(int j=1;j<=MAX_C;++j)
		{
			if(board[1][j])
			{
				for(int i=1;i<=MAX_R;++i)
					board[i][p]=board[i][j];
				++p;
			}
		}
		for(;p<=MAX_C;++p)
		{
			for(int i=1;i<=MAX_R;++i)
				board[i][p]=0;
		}
		
//		tout();
	}
	
	void simulation()
	{
		CUBE pos;
		int scr=0,rem=MAX_R*MAX_C;
		for(int move=1;(pos=select()).n>1;++move)
		{
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
					move, pos.x, pos.y, pos.n, board[pos.x][pos.y], (pos.n-2)*(pos.n-2));
			scr+=(pos.n-2)*(pos.n-2);
			rem-=pos.n;
			remove(pos);
		}
		if(!rem)
			scr+=1000;
		printf("Final score: %d, with %d balls remaining.\n",scr,rem);
	}
}final;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	printf("Game %d:\n\n",cas);
    	final.read();
    	final.simulation();
    	if(cas!=dataset)
    		putchar(10);
    }

    return 0;
}

