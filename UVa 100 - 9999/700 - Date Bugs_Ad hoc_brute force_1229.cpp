/*
 * 700 - Date Bugs
 *
 * Ad hoc...
 *
 * A simple problem, just brute force find the number
 * which can be visit by all the N computers...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 10000
using namespace std;

int cnt[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n,y,a,b,cas=1;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(cnt,0,sizeof(cnt));
        int bgn=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&y,&a,&b);
            bgn=max(bgn,y);
            for(int jump=b-a;y<MAXN;y+=jump)
            {
                ++cnt[y];
            }
        }

        for(;bgn<MAXN;++bgn)
        {
            if(cnt[bgn]==n)
                break;
        }

        printf("Case #%d:\n",cas++);
        if(cnt[bgn]==n)
            printf("The actual year is %d.\n",bgn);
        else
            puts("Unknown bugs detected.");
        putchar(10);
    }

    return 0;
}

