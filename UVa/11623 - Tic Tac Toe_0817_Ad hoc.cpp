/*
11623 - Tic Tac Toe

Ad hoc...
����һ������,�ж���ǰ��״̬

��oΪ'O'����,xΪ'X'����
��x����,�����o+1=x || o=x

���x win,��ö��x������,ɾ��,�ж����̾���
�������ɾ��x���ĸ�����,x��״̬һֱ��win,��error
��oͬ��

���x win ����o win,��error
������߶�û��win�ľ���,�ж�������,��draw,����IN PROGRESS

��ô�����Ĵ���o(n^4*k)�ĸ��Ӷ�,��Ȼ����rank 3...
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
