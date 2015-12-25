/*
10667 - Largest Block

dp...
O(n^4)暴力算法可以过...
*/

#include<iostream>
#define MAXN 110
using namespace std;

struct MATRIX
{
	int r1,r2,c1,c2;
}mat;

int s,b,g[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&s,&b);
		memset(g,0,sizeof(g));
		for(int i=1;i<=s;++i)
			for(int j=1;j<=s;++j)
				g[i][j]=1;

		for(int i=0;i<b;++i)
		{
			scanf("%d%d%d%d",&mat.r1,&mat.c1,&mat.r2,&mat.c2);
			if(mat.r1>mat.r2)
				swap(mat.r1,mat.r2);
			if(mat.c1>mat.c2)
				swap(mat.c1,mat.c2);

			for(int j=mat.r1;j<=mat.r2;++j)
				for(int k=mat.c1;k<=mat.c2;++k)
					g[j][k]=0;
		}

		int sz=0;
		for(int i=1;i<=s;++i)
			for(int j=1;j<=s;++j)
			{
				g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
				for(int a=1;a<=i;++a)
					for(int b=1;b<=j;++b)
					{
						int t=g[i][j]+g[a-1][b-1]-g[i][b-1]-g[a-1][j];
						if(t==(i-a+1)*(j-b+1))
							sz=max(t,sz);
					}
			}

		printf("%d\n",sz);
	}

	return 0;
}
