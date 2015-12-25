/*
10377 - Maze Traversal

simulation...
just do as problem description...
*/

#include<iostream>
#define MAXN 66
using namespace std;

const char dir[]="NESW";
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char g[MAXN][MAXN],buf[MAXN*MAXN];
int n,m,x,y,d;
bool quit;

void process(char c)
{
	if(quit)
		return ;

	if(c=='R')
		++d;
	else if(c=='L')
		--d;
	else if(c=='F')
	{
		d=(d%4+4)%4;
		int tx=x+dx[d],ty=y+dy[d];
		if(tx>0 && ty>0 && g[tx][ty]==' ')
			x=tx,y=ty;
	}
	else if(c=='Q')
		quit=true;
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
		scanf("%d%d%*c",&n,&m);
		for(int i=1;i<=n;++i)
			gets(g[i]+1);
		scanf("%d%d%*c",&x,&y);

		d=0;
		quit=false;

		while(gets(buf) && buf[0])
		{
			for(int i=0;buf[i];++i)
				process(buf[i]);
		}

		printf("%d %d %c\n",x,y,dir[(d%4+4)%4]);
		if(dataset)
			putchar(10);
	}

	return 0;
}
