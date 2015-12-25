/*
 * 10364 - Square
 *
 * dp..
 * bitmask...
 *
 * use bitmask to represent numbers we have already selected...
 * and dp[STATE s] store the sum of total selected numbers.
 * key = SUM_OF_ALL_NUMBERS%4
 * for(each i NOT_IN_STATE s)
 *      if(dp[STATE s]%key+value[i]<=key)       (why? Please have a think:)
 *           dp[(1<<i) + STATE s]=max(dp[STATE s] + value[i])
 * finally, if dp[(1<<n)-1] equals SUM_OF_ALL_NUMBERS
 * the answer is "yes"
 * otherwist, "no"
 *
 * we should first check whether SUM%4==0 and MAXIMUM_NUMBER <= SUM/4
 * to make our program more faster...
 */

#include<cstdio>
#include<cstring>
#define MAXN 20
using namespace std;

int n,var[MAXN],dp[1<<MAXN];

void ChkMax(int &cur,int t)
{
    if(cur<t)
        cur=t;
}

bool ok()
{
    scanf("%d",&n);
    int m=0,sum=0,key;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&var[i]);
        ChkMax(m,var[i]);
        sum+=var[i];
    }
    key=sum>>2;
    if(sum%4 || m>key)
        return false;

    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<(1<<n);++i)
    {
        if(dp[i]==-1)
            continue;
        
        dp[i]%=key;
        for(int j=0;j<n;++j)
            if(!(i&(1<<j)) && dp[i]+var[j]<=key)
                ChkMax(dp[i|(1<<j)],dp[i]+var[j]);
    }

    return dp[(1<<n)-1]==0;
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
        puts(ok()?"yes":"no");
    }

    return 0;
}

