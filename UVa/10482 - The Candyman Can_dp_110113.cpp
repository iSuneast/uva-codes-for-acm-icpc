/*
 * 10482 - The Candyman Can
 * 
 * dp...
 * Boolean dp[candyNum][Child_1][Child_2]
 * sum = SUM( candy )
 * for a new candy V
 * if dp[candyNum][Child_1][Child_2] is available
 * then we can have the new state
 *      dp[candyNum+1][Child_1+v][Child_2]
 *      dp[candyNum+1][Child_1][Child_2+v]
 *      dp[candyNum+1][Child_1][Child_2+v]		//give it to Child_3
 *      
 * finally, if dp[Total_Candy_Num][Child_1][Child_2] is OK
 * Child_3 = sum - Child_1 - Child_2
 * then you will find the answer
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 32
#define MAX_SUM 650
using namespace std;

int dp[2][MAX_SUM][MAX_SUM];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset, n;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	scanf("%d",&n);
    	memset(dp,0,sizeof(dp));
    	int s=0,v,cur=0,next=1;

    	dp[cur][0][0]=0;
    	for(int i=1;i<=n;++i)
    	{
    		scanf("%d",&v);
    		int state=i-1;
    		for(int a=0;a<=s;++a)
    		{
    			for(int b=0;b+a<=s;++b)
    			{
    				if(dp[cur][a][b]==state)
    					dp[next][a+v][b]=dp[next][a][b+v]=dp[next][a][b]=i;
    			}
    		}
    		s+=v;
    		
    		swap(cur,next);
    	}
    	
    	int key=s, m, M;
		for(int a=0;a<=s;++a)
		{
			for(int b=0;b<=s;++b)
			{
				if(dp[cur][a][b]==n)
				{
					m=min(s-a-b, min(a,b));
					M=max(s-a-b, max(a,b));
					key=min(key, M-m);
				}
			}
		}
		
		printf("Case %d: %d\n",cas, key);
    }

    return 0;
}

