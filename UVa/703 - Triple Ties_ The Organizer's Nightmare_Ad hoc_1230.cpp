/*
 * 703 - Triple Ties: The Organizer's Nightmare
 *
 * Ad hoc...
 * just need to check for TRIPLE LOOP or TRIPLE TIE
 * so an O(n^3) is fine...
 *
 * for i : 1->n
 *    for j : 1->n
 *       for k : 1->n
 *          if i>j>k && LOOP(i,j,k)
 *          else if i<j<k && LOOP(k,j,i)
 *          else if i>j>k && TIE(i,j,k)
 *
 * sorted and output all valid answers...
 * done~
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 103
#define SZ 1000000
using namespace std;

int n,g[MAXN][MAXN];

bool none(int a,int b,int c)
{
    return !(g[a][b] || g[a][c] || g[b][a] || g[b][c] || g[c][a] || g[c][b]);
}

bool cyc(int a,int b,int c)
{
    return g[a][b] && g[b][c] && g[c][a];
}

struct ANSWER
{
    int a[3];
    bool operator<(const ANSWER &t)const
    {
        for(int i=0;i<2;++i)
            if(a[i]!=t.a[i])
                return a[i]<t.a[i];
        return a[2]<t.a[2];
    }
}ans[SZ];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                scanf("%d",&g[i][j]);
        }

        int key=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                for(int k=j+1;k<=n;++k)
                {
                    if( cyc(i,j,k) || none(i,j,k) )
                    {
                        ans[key].a[0]=i;
                        ans[key].a[1]=j;
                        ans[key].a[2]=k;
                        ++key;
                    }
                    else if(cyc(k,j,i))
                    {
                        ans[key].a[0]=k;
                        ans[key].a[1]=j;
                        ans[key].a[2]=i;
                        ++key;
                    }
                }
            }
        }

        printf("%d\n",key);
        sort(ans,ans+key);
        for(int i=0;i<key;++i)
        {
            printf("%d %d %d\n",ans[i].a[0],ans[i].a[1],ans[i].a[2]);
        }
    }

    return 0;
}

