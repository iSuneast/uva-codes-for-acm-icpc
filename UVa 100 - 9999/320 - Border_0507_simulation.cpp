/*
320 - Border

simulation...
*/

#include<iostream>
#define MAXN 36
using namespace std;

char g[MAXN][MAXN],buf[1000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int x,y,p=0;
		scanf("%d%d",&x,&y);
		scanf("%s",buf);
		for(int i=0;i<32;++i)
			for(int j=0;j<32;++j)
				g[i][j]='.';
		while(buf[p])
		{
			if(buf[p]=='E')
				g[y-1][x]='X',++x;
			else if (buf[p] == 'W')
				g[y][x - 1] = 'X',--x;
			else if (buf[p] == 'N')
				g[y][x] = 'X',++y;
			else if (buf[p] == 'S')
				g[y-1][x-1] = 'X',--y;
			else
				break;
			++p;
		}
		printf("Bitmap #%d\n",cas);
		for(int i=31;i>=0;--i)
			puts(g[i]);
		putchar('\n');
	}

	return 0;
}
