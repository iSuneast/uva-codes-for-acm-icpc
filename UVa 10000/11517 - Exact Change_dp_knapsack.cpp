/*
 * 11517 - Exact Change
 * 
 * dp...
 * knapsack...
 * this method of dp is some kinds of brute force...
 * but the time is just O(10^6)for each testcase at most...
 * so I think it's enough for this problem...
 */

#include<iostream>
#include<cstring>
#define MAXN 10003
#define INF 0x3f3f3f3f
using namespace std;

int dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d",&dataset);
    while(dataset--)
    {
        int money,n,var;
        scanf("%d",&money);
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&var);
            for(int i=MAXN-1;i>=var;--i)
                dp[i]=min(dp[i],dp[i-var]+1);
        }

        for(int i=money;i<MAXN;++i)
            if(dp[i]!=INF)
            {
                printf("%d %d\n",i,dp[i]);
                break;
            }
    }

    return 0;
}
