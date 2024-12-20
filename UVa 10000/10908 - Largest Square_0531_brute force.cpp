/*
10908 - Largest Square

Brute force...
之前还一直纠结会不会TLE...
没想到数据果然很水...
*/

#include<iostream>
#define MAXN 110
using namespace std;

char g[MAXN][MAXN];

bool bigger(int dis,int &x,int &y)
{
	for(int tx=x-dis;tx<=x+dis;++tx)
		if(g[tx][y-dis]!=g[x][y] || g[tx][y+dis]!=g[x][y])
			return false;
	for(int ty=y-dis+1;ty<y+dis;++ty)
		if(g[x-dis][ty]!=g[x][y] || g[x+dis][ty]!=g[x][y])
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,m,n,q;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&m,&n,&q);
		printf("%d %d %d\n",m,n,q);
		gets(g[0]);
		memset(g,0,sizeof(g));
		for(int i=1;i<=m;++i)
			gets(g[i]+1);
		int x,y;
		while(q--)
		{
			scanf("%d%d",&x,&y);
			++x,++y;
			int key=1;
			while(bigger(key,x,y))
				++key;
			printf("%d\n",2*key-1);
		}
	}

	return 0;
}
