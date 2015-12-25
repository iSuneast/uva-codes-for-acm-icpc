/*
711 - Dividing up

dp...
knapsack...

in the general solution...
we have to reduce the numbers
I don't know the exact value, 
just try to make it into a little larger number 
in order to keep my algorithm fine

but during coding, I have made some silly mistake cause me WA for many times...
*/

#include<cstdio>
#include<cstring>
#define MAXN 60001
using namespace std;

int a[7],s;
bool dp[MAXN];

bool input()
{
    s=0;
    for(int i=1;i<=6;++i)
    {
        if(scanf("%d",&a[i])==EOF)
            return false;
        if(a[i]>12)
            a[i]=(a[i]&1)?11:12;
        s+=a[i]*i;
    }
    return s;
}

bool ok()
{
    if(s&1)
        return false;
    s>>=1;
    memset(dp,0,sizeof(dp));
    dp[0]=true;
    for(int i=1;i<=6;++i)
    {
        for(int k=1;k<=a[i];++k)
        {
            for(int j=s;j>=i;--j)
                if(dp[j-i])
                    dp[j]=true;
        }
    }

    return dp[s];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int cas=1;
    while(input())
    {
        printf("Collection #%d:\n",cas++);
        puts(ok()?"Can be divided.":"Can't be divided.");
        putchar(10);
    }

	return 0;
}
