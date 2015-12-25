/*
10913 - Walking on a Grid

dp...
use array dp[x][y][k][state] to store the state
initial dp[1][1][ var[1][1]<0?1:0 ][ DOWN ]=var[1][1]
then we scan from top to bottom
1. from left to right
2. from right to left
3. from up to down
refresh the dp[][][][] if the state is valid

final the maximum value of dp[n][n][][] is the right answer
*/

#include<iostream>
#define L 0
#define R 1
#define D 2
#define MAXN 80
#define MAXK 7
#define INF 0x3f3f3f3f
using namespace std;

int n,k;
int dp[MAXN][MAXN][MAXK][3],var[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d%d",&n,&k)!=EOF && (n||k))
	{
		for(int i=0;i<MAXN;++i)
		{
			for(int j=0;j<MAXN;++j)
				for(int a=0;a<MAXK;++a)
					for(int b=0;b<3;++b)
						dp[i][j][a][b]=-INF;
		}

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				scanf("%d",&var[i][j]);
		}

		dp[1][1][ var[1][1]<0?1:0 ][D]=var[1][1];
		for(int i=1;i<=n;++i)
		{
			for(int a=0;a<=k;++a)
			{
				int key;
				for(int j=1;j<n;++j)	//right
				{
					key=max(dp[i][j][a][R],dp[i][j][a][D]);
					if(key!=-INF)
						dp[i][j+1][ a+(var[i][j+1]<0?1:0) ][R]=key+var[i][j+1];
				}

				for(int j=n;j>1;--j)	//left
				{
					key=max(dp[i][j][a][L],dp[i][j][a][D]);
					if(key!=-INF)
						dp[i][j-1][ a+(var[i][j-1]<0?1:0) ][L]=key+var[i][j-1];
				}

				if(i==n)
					continue;

				for(int j=1;j<=n;++j)	//down
				{
					key=max(dp[i][j][a][D],max(dp[i][j][a][L],dp[i][j][a][R]));
					if(key!=-INF)
						dp[i+1][j][ a+(var[i+1][j]<0?1:0) ][D]=key+var[i+1][j];
				}
			}
		}

		int key=-INF;
		for(int a=0;a<=k;++a)
		{
			key=max(key,dp[n][n][a][L]);
			key=max(key,dp[n][n][a][R]);
			key=max(key,dp[n][n][a][D]);
		}

		if(key<=-INF)
			printf("Case %d: impossible\n",cas++);
		else
			printf("Case %d: %d\n",cas++,key);
	}

	return 0;
}
