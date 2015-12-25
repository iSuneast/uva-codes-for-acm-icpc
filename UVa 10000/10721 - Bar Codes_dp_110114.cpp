/*
 * 10721 - Bar Codes
 * 
 * dp...
 * I allocate a big array dp[LastBit][N][K][tmpM][M]
 * # if LastBit is 0
 *      @ nextBit is 1, dp[1][n+1][k+1][1][M]+=dp[0][n][k][m][M]
 *      @ nextBit is 0, dp[0][n+1][k][m+1][max(M, m+1)]+=dp[0][n][k][m][M]
 * # else LastBit is 1
 *      @ nextBit is 1, dp[1][n+1][k][m+1][max(M, m+1)]+=dp[1][n][k][m][M]
 *      @ nextBit is 0, dp[0][n+1][k+1][1][M]+=dp[1][n][k][m][M]
 *      
 * so the final answer for BC(n,k,m) is
 *     bc(n,k,m) = SUM( dp[0][n][k][tmpM][m] + dp[1][n][k][tmpM][m] ) tmpM->[1,n]
 *     BC(n,k,m) = SUM( bc(n,k,i) ) i->[1,m]
 *     
 * done!
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 51
using namespace std;

long long dp[2][MAXN][MAXN][MAXN][MAXN], key[MAXN][MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    memset(dp,0,sizeof(dp));
    dp[1][1][1][1][1]=1;
    for(int n=1;n+1<MAXN;++n)
    {
    	for(int k=0;k<=n;++k)
    	{
    		for(int m=0;m<=n;++m)
    		{
    			for(int MaxL=0;MaxL<=n;++MaxL)
    			{
    				if(dp[0][n][k][m][MaxL])
    				{
            			dp[0][n+1][k][m+1][max(MaxL, m+1)]+=dp[0][n][k][m][MaxL];
            			dp[1][n+1][k+1][1][MaxL]+=dp[0][n][k][m][MaxL];
    				}
    				if(dp[1][n][k][m][MaxL])
    				{
            			dp[0][n+1][k+1][1][MaxL]+=dp[1][n][k][m][MaxL];
            			dp[1][n+1][k][m+1][max(MaxL, m+1)]+=dp[1][n][k][m][MaxL];
    				}
    			}
    		}
    	}
    }
    
    memset(key,0,sizeof(key));
    for(int n=1;n<MAXN;++n)
    {
    	for(int k=0;k<=n;++k)
    	{
    		for(int m=0;m<=n;++m)
			{
    			for(int maxL=1;maxL<=n;++maxL)
	    		{
	    			key[n][k][maxL]+=dp[0][n][k][m][maxL]+dp[1][n][k][m][maxL];
	    		}
			}
    		for(int m=1;m<=n;++m)
    			key[n][k][m]+=key[n][k][m-1];
    	}
    }
    
    for(int n,k,m; scanf("%d%d%d",&n,&k,&m)!=EOF;)
    	printf("%lld\n",key[n][k][m]);

    return 0;
}

