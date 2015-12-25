/*
 * 10350 - Liftless EME
 *
 * dp...
 * a simple problem
 * Floor(K)[i][j] = min( Floor(K-1)[u][i] + dis[k-1][i][j] + 2 )
 * is fine
 *          dis[][][] is the input data
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 125
using namespace std;
const int INF=0x3f3f3f3f;

char name[17];
int n,m,g[2][MAXN][MAXN];

void ChkMin(int &cur,int t)
{
    if(t<cur)
        cur=t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int t;
    while(scanf("%s",name)!=EOF)
    {
        puts(name);
        scanf("%d%d",&n,&m);
        memset(g[0],0,sizeof(g[0]));
        int pre=1,next=0;
        for(int k=0;k<n-1;++k)
        {
            swap(pre,next);
            memset(g[next],0x3f,sizeof(g[next]));
            for(int i=0;i<m;++i)
            {
                for(int j=0;j<m;++j)
                {
                    scanf("%d",&t);
                    t+=2;
                    for(int u=0;u<m;++u)
                        ChkMin(g[next][i][j],g[pre][u][i]+t);
                }
            }
        }

        int key=INF;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<m;++j)
            {
                ChkMin(key,g[next][i][j]);
            }
        }
        printf("%d\n",key);
    }
    
    return 0;
}

