/*
11002 - Towards Zero

dp...
quite simple...
don't misunderstand the problem description
just use dp[60][60][50*2*60] to memorize the temp value we can got
then transport the state is enough
*/

#include<iostream>
#define MAXN 66
using namespace std;
const int jump=1510;
const int INF=0x3f3f3f3f;

bool dp[MAXN][MAXN][jump<<1];
int n,var[MAXN][MAXN];

void DP()
{
	memset(dp,0,sizeof(dp));

	dp[1][1][ var[1][1]+jump ]=true;

	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=i;++j)
			for(int k=0;k<jump*2;++k)
				if(dp[i][j][k])
				{
					dp[i+1][j][ k+var[i+1][j] ]=
						dp[i+1][j][ k-var[i+1][j] ]=
						dp[i+1][j+1][ k+var[i+1][j+1] ]=
						dp[i+1][j+1][ k-var[i+1][j+1] ]=true;
				}
	}

	for(int i=n;i<2*n-1;++i)
	{
		for(int j=1;j<=2*n-i;++j)
		{
			if(j!=1)
			{
				for(int k=0;k<jump*2;++k)
					if(dp[i][j][k])
					{
						dp[i+1][j-1][ k+var[i+1][j-1] ]=
							dp[i+1][j-1][ k-var[i+1][j-1] ]=true;
					}
			}

			if(j!=2*n-i)
			{
				for(int k=0;k<jump*2;++k)
					if(dp[i][j][k])
					{
						dp[i+1][j][ k+var[i+1][j] ]=
							dp[i+1][j][ k-var[i+1][j] ]=true;
					}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=i;++j)
				scanf("%d",&var[i][j]);

		for(int i=n+1;i<2*n;++i)
			for(int j=1;j<=2*n-i;++j)
				scanf("%d",&var[i][j]);

		DP();

		int key=INF;
		for(int k=0;k<jump*2;++k)
			if(dp[2*n-1][1][k])
				key=min(key,abs(k-jump));

		printf("%d\n",key);
	}

	return 0;
}
