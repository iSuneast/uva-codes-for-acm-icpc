/*
 * 10401 - Injured Queen Problem
 * 
 * dp...
 * dp[Row][Column]
 * dp[NewRow][Column+1] += dp[Row][Column]
 *     Row+2 <= NewRow <= L
 *     1 <= NewRow <= Row-2
 *     
 * there is something wrong with the data input
 * (maybe tailing blank or something similar so you'd better use scanf() instead of gets() )
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 20
using namespace std;

long long dp[MAXN][MAXN];
char s[MAXN];
int h[128];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    for(int i='1';i<='9';++i)
    {
    	h[i]=i-'1';
    }
    for(int i='A';i<='F';++i)
    {
    	h[i]=i-'A'+9;
    }
    
    while(scanf("%s",s)!=EOF)
    {
    	int l=strlen(s);
    	memset(dp,0,sizeof(dp));
    	
    	if(s[0]!='?')
    		dp[ h[ s[0] ] ][0]=1;
    	else for(int r=0;r<l;++r)
    		dp[r][0]=1;
    	
    	for(int c=0;c+1<l;++c)
    	{
    		if(s[c]!='?')
    		{
    			int curR=h[ s[c] ];
    			for(int r=curR-2; r>=0; --r)
    			{
    				dp[r][c+1]+=dp[curR][c];
    			}
    			for(int r=curR+2; r<l; ++r)
    			{
    				dp[r][c+1]+=dp[curR][c];
    			}
    		}
    		else for(int curR=0; curR<l; ++curR)
    		{
    			for(int r=curR-2; r>=0; --r)
    			{
    				dp[r][c+1]+=dp[curR][c];
    			}
    			for(int r=curR+2; r<l; ++r)
    			{
    				dp[r][c+1]+=dp[curR][c];
    			}    			
    		}
    	}
    	
    	long long key=0;
    	if(s[l-1]!='?')
    		key=dp[ h[ s[l-1] ] ][ l-1 ];
    	else for(int r=0;r<l;++r)
    		key+=dp[r][ l-1 ];
    	
    	cout<<key<<endl;
    }

    return 0;
}

