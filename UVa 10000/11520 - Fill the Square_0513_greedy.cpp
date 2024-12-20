/*
11520 - Fill the Square

greedy...
保证字典序最小...
从行开始贪心即可...
*/

#include<iostream>
#define MAXN 15
using namespace std;

char g[MAXN][MAXN];
bool flag[128];

char next(int x,int y)
{
	memset(flag,0,sizeof(flag));
	flag[ g[x-1][y] ]=true;
	flag[ g[x][y-1] ]=true;
	flag[ g[x+1][y] ]=true;
	flag[ g[x][y+1] ]=true;
	for(char i='A';;++i)
		if(!flag[i])
			return i;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
			scanf("%s",g[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(g[i][j]=='.')
					g[i][j]=next(i,j);
		printf("Case %d:\n",cas);
		for(int i=1;i<=n;++i)
			puts(g[i]+1);
	}

	return 0;
}
