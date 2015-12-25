/*
10196 - Check The Check

这么长的代码竟然可以一次AC.
果然认真是很重要的.
题目的意思很简单.
照着模拟就可以了.
*/

#include<iostream>

using namespace std;

char chess[13][13],key;

void chk_P(int x,int y,char c)
{
	if(chess[x-1][y-1]==c || chess[x-1][y+1]==c)
		key=c;
}

void chk_p(int x,int y,char c)
{
	if(chess[x+1][y-1]==c || chess[x+1][y+1]==c)
		key=c;
}

void chk_r(int x,int y,char c)
{
	int i;
	for(i=x+1;i<=8;i++)
		if(chess[i][y]==c)
		{
			key=c;
			return ;
		}
		else if(chess[i][y]!='.')
			break;
	for(i=x-1;i;i--)
		if(chess[i][y]==c)
		{
			key=c;
			return ;
		}
		else if(chess[i][y]!='.')
			break;
	for(i=y+1;i<=8;i++)
		if(chess[x][i]==c)
		{
			key=c;
			return ;
		}
		else if(chess[x][i]!='.')
			break;
	for(i=y-1;i;i--)
		if(chess[x][i]==c)
		{
			key=c;
			return ;
		}
		else if(chess[x][i]!='.')
			break;
}

void chk_b(int x,int y,char c)
{
	int i;
	for(i=1;x+i<=8 && y+i<=8;i++)
		if(chess[x+i][y+i]==c)
		{
			key=c;
			return ;
		}
		else if(chess[x+i][y+i]!='.')
			break;
	for(i=1;x-i && y-i;i++)
		if(chess[x-i][y-i]==c)
		{
			key=c;
			return ;
		}
		else if(chess[x-i][y-i]!='.')
			break;
	for(i=1;x+i<=8 && y-i;i++)
		if(chess[x+i][y-i]==c)
		{
			key=c;
			return ;
		}
		else if(chess[x+i][y-i]!='.')
			break;
	for(i=1;x-i && y+i<=8;i++)
		if(chess[x-i][y+i]==c)
		{
			key=c;
			return ;
		}
		else if(chess[x-i][y+i]!='.')
			break;
}

void chk_q(int x,int y,char c)
{
	chk_b(x,y,c);
	chk_r(x,y,c);
}

void chk_k(int x,int y,char c)
{
	if(	chess[x-1][y-1]==c || chess[x-1][y]==c	|| chess[x-1][y+1]==c
	||	chess[x][y-1]==c						|| chess[x][y+1]==c
	||	chess[x+1][y-1]==c || chess[x+1][y]==c	|| chess[x+1][y+1]==c	)
		key=c;
}

void chk_n(int x,int y,char c)
{
	if( (x-2>0 && chess[x-2][y-1]==c) || (y-2>0 && chess[x-1][y-2]==c)
	||	(x-2>0 && chess[x-2][y+1]==c) || chess[x-1][y+2]==c
	||	(y-2>0 && chess[x+1][y-2]==c) || chess[x+2][y-1]==c
	||	chess[x+1][y+2]==c || chess[x+2][y+1]==c	)
		key=c;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,cas=1;
	bool next;
	memset(chess,0,sizeof(chess));
	do
	{
		next=false;
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
			{
				cin>>chess[i][j];
				if(chess[i][j]!='.')
					next=true;
			}
		key=0;
		for(i=1;i<=8;i++)
			for(j=1;j<=8 && key==0;j++)
				if(chess[i][j]!='.')
					switch(chess[i][j])
					{
					case 'P':
						chk_P(i,j,'k');
						break;
					case 'R':
						chk_r(i,j,'k');
						break;
					case 'B':
						chk_b(i,j,'k');
						break;
					case 'Q':
						chk_q(i,j,'k');
						break;
					case 'K':
						chk_k(i,j,'k');
						break;
					case 'N':
						chk_n(i,j,'k');
						break;
					case 'p':
						chk_p(i,j,'K');
						break;
					case 'r':
						chk_r(i,j,'K');
						break;
					case 'b':
						chk_b(i,j,'K');
						break;
					case 'q':
						chk_q(i,j,'K');
						break;
					case 'k':
						chk_k(i,j,'K');
						break;
					case 'n':
						chk_n(i,j,'K');
						break;
					}
		if(next)
		{
			if(key=='k')
				cout<<"Game #"<<cas++<<": black king is in check."<<endl;
			else if(key=='K')
				cout<<"Game #"<<cas++<<": white king is in check."<<endl;
			else
				cout<<"Game #"<<cas++<<": no king is in check."<<endl;
		}
	}while(next);

return 0;
}
