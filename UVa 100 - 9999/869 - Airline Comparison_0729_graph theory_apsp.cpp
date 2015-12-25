/*
869 - Airline Comparison

graph theory...
apsp...
图的传递闭包...
比较一下两张图的传递闭包即可..
*/

#include<iostream>
#define MAXN 256
using namespace std;

bool g1[MAXN][MAXN],g2[MAXN][MAXN];

void floyd(bool g[MAXN][MAXN])
{
	for(int k=0;k<256;++k)
	{
		for(int i=0;i<256;++i)
			for(int j=0;j<256;++j)
				if(g[i][k] && g[k][j])
					g[i][j]=true;
		g[k][k]=true;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n;
		char a[3],b[3];

		memset(g1,0,sizeof(g1));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s%s",a,b);
			g1[ a[0] ][ b[0] ]=g1[ b[0] ][ a[0] ]=true;
		}
		floyd(g1);

		memset(g2,0,sizeof(g2));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s%s",a,b);
			g2[ a[0] ][ b[0] ]=g2[ b[0] ][ a[0] ]=true;
		}
		floyd(g2);

		puts(memcmp(g1,g2,sizeof(g1))==0?"YES":"NO");

		if(dataset)
			putchar(10);
	}

	return 0;
}
