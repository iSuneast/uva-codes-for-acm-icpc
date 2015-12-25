/*
11553 - Grid Game

dp...
bitmask...
状态dp...
Alice=Bob=(1<<n)-1
dp[Alice][Bob]保存两个人同时选择后的最小值
每次分别转移(1<<x),(1<<y)费用为[x][y]
记忆化搜索即可...
*/

#include<iostream>
#define MAXN 8
#define INF 0x3f3f3f3f
using namespace std;

int g[MAXN][MAXN],dp[1<<MAXN][1<<MAXN],n;

inline bool inside(int s,int fa)
{	
	return (1<<s)&fa;
}

int DP(int a,int b)
{
	if(dp[a][b]==INF)
		for(int i=0;i<n;++i)
			if(inside(i,a))
				for(int j=0;j<n;++j)
					if(inside(j,b))
						dp[a][b]=
						min(dp[a][b],DP(a-(1<<i),b-(1<<j))+g[i][j]);
	return dp[a][b];
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
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&g[i][j]);

		memset(dp,0x3f,sizeof(dp));	dp[0][0]=0;
		printf("%d\n",DP((1<<n)-1,(1<<n)-1) );
	}

	return 0;
}
