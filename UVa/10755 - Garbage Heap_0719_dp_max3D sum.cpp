/*
10755 - Garbage Heap

dp...
max3D sum...
竟然有大型数据...
用longlong才能过...
无语...
*/

#include<iostream>
#define MAXN 23
using namespace std;

long long cube[MAXN][MAXN][MAXN];
int a,b,c;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&a,&b,&c);
		memset(cube,0,sizeof(cube));
		long long ans;
		bool first=true;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				for(int k=1;k<=c;++k)
				{
					scanf("%lld",&cube[i][j][k]);
					cube[i][j][k]+=cube[i-1][j][k]+cube[i][j-1][k]+cube[i][j][k-1]
					-cube[i-1][j-1][k]-cube[i-1][j][k-1]-cube[i][j-1][k-1]
					+cube[i-1][j-1][k-1];
					if(first)
						ans=cube[i][j][k];
					first=false;

					for(int x=1;x<=i;++x)
						for(int y=1;y<=j;++y)
							for(int z=1;z<=k;++z)
							{
								long long t=cube[i][j][k]
								-cube[x-1][j][k]-cube[i][y-1][k]-cube[i][j][z-1]
								+cube[x-1][y-1][k]+cube[i][y-1][z-1]+cube[x-1][j][z-1]
								-cube[x-1][y-1][z-1];
									ans=max(t,ans);
							}
				}

		printf("%lld\n",ans);
		if(dataset)
			putchar('\n');
	}

	return 0;
}
