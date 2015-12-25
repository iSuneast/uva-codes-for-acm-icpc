/*
 * 10759 - Dice Throwing
 * 
 * dp...
 * use an array dp[N][SUM] to store the current number of sum we can achieve using N integers
 * then the answer is SUM( dp[N][i] ) / SUM( dp[N][j] )
 * 						x<=i<=SUM , 0<=j<=SUM
 * 
 * happy coding..
 */

#include<cstdio>
#include<cstring>
#define MAXN 25
#define SUM 145
using namespace std;

long long dp[MAXN][SUM];

long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int n=1;n<MAXN;++n)
    {
    	for(int s=0;s<SUM;++s)
    	{
    		for(int d=1;d<=6 && s>=d;++d)
    		{
    			dp[n][s]+=dp[n-1][s-d];
    		}
    	}
    }
    
    for(int n,x; scanf("%d%d",&n,&x)!=EOF && (n||x); )
    {
    	long long a=0,b=0;
    	for(int s=0;s<SUM;++s)
    	{
    		b+=dp[n][s];
    		if(s>=x)
    			a+=dp[n][s];
    	}
    	
    	long long g=gcd(a,b);
    	a/=g;
    	b/=g;

    	if(b==1)
    		printf("%lld\n",a);
    	else
    		printf("%lld/%lld\n",a,b);
    }

    return 0;
}

