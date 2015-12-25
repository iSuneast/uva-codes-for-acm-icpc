/*
 * 11496 - Musical Loop
 * 
 * Ad hoc...
 * read var[1-n],let var[0]=var[n],var[n+1]=var[1]
 * and than scan from i=1,
 * (var[i-1]<var[i] && var[i]>var[i+1])
 * or (var[i-1]>var[i] && var[i]<var[i+1])
 * ++answer...
 */

#include<iostream>
#include<cstdio>
#define MAXN 10008
using namespace std;

int var[MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&var[i]);
        }
        var[0]=var[n],var[n+1]=var[1];
        int key=0;
        for(int i=1;i<=n;++i)
        {
            if(var[i-1]<var[i] && var[i]>var[i+1])
                ++key;
            else if(var[i-1]>var[i] && var[i]<var[i+1])
                ++key;
        }
        printf("%d\n",key);
    }

    return 0;
}
