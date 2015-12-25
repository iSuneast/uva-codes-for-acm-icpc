/*
 * 10446 - The Marriage Interview :-)
 * 
 * dp...
 * memorization...
 * just use an array to store the value...
 * use unsigned long long to avoid overflow
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 63
using namespace std;
typedef unsigned long long ULL;

ULL dp[MAXN][MAXN];

ULL trib(int n,int back)
{
	if(n<0)					return 1;
	if(dp[n][back]!=-1)		return dp[n][back];
	if(n<=1)				return dp[n][back]=1;

    dp[n][back]=1;
    for(int i=1;i<=back;++i)
    	dp[n][back]+=trib(n-i,back);
    
    return dp[n][back];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    memset(dp,-1,sizeof(dp));
    for(int cas=1, n, back; scanf("%d%d",&n,&back)!=EOF && n<=60; ++cas)
    {
    	cout<<"Case "<<cas<<": "<<trib(n,back)<<endl;
    }

    return 0;
}

