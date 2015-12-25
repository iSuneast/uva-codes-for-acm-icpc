/*
10360 - Rat Attack

dp...
just calc the maximum sum of block
{(x-d,y-d)-(x+d,y+d)}
use dp, we can solve it in O(n^2)time
*/

#include<iostream>
#define MAXN 1030
using namespace std;

int g[MAXN][MAXN],d,n;

int calc(int x,int y)
{
	int tx=max(0,x-d-1),ty=max(0,y-d-1);
	return g[x+d][y+d]-g[tx][y+d]-g[x+d][ty]+g[tx][ty];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,x,y,p;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&d,&n);
		memset(g,0,sizeof(g));
		while(n--)
		{
			scanf("%d%d%d",&x,&y,&p);
			g[x+1][y+1]=p;
		}
		for(int i=1;i<MAXN;++i)
		{
			for(int j=1;j<MAXN;++j)
				g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
		}

		int key=0;
		for(int i=1;i+d<MAXN;++i)
		{
			for(int j=1;j+d<MAXN;++j)
			{
				int cnt=calc(i,j);
				if(cnt>key)
				{
					key=cnt;
					x=i-1;y=j-1;
				}
			}
		}

		printf("%d %d %d\n",x,y,key);
	}
	
	return 0;
}
