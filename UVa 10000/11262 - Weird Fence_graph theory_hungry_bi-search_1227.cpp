/*
 * 11262 - Weird Fence
 *
 * graph theory...
 * max-match...
 * divide && conquer...
 *
 * build a graph depends on "the minimum integer length of the chains"
 * if the distance between two nodes is less than that above
 * link these two nodes...
 * finally, check whether the max-match >= Require
 */

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 103
using namespace std;

struct BINARY_MATCH
{
    bool g[MAXN][MAXN];
    int n,m,match,cnt;
    int dis[MAXN][MAXN],key[MAXN*MAXN],tot;
    struct POINT
    {
        int x,y;
    }pnt,red[MAXN],blue[MAXN];

    int sqr(const int &t)const
    {
        return t*t;
    }

    int dist(const POINT &a,const POINT &b)const
    {
        return sqr(a.x-b.x)+sqr(a.y-b.y);
    }
    
    void read()
    {
        char s[10];
        scanf("%d%d",&cnt,&match);
        n=m=0;  tot=0;
        for(int i=0;i<cnt;++i)
        {
            scanf("%d%d%s",&pnt.x,&pnt.y,s);
            if(s[0]=='r')
                red[n++]=pnt;
            else
                blue[m++]=pnt;
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                key[tot++]=dis[i][j]=dist(red[i],blue[j]);
        }

        sort(key,key+tot);
    }

    void build(int bound)
    {
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                g[i][j]=(dis[i][j]<=bound);
    }

    bool flag[MAXN];
    int mat[MAXN];
    
    int dfs(int u)
    {
        for(int v=0;v<m;++v)
            if(g[u][v] && !flag[v])
            {
                flag[v]=true;
                if(mat[v]==-1 || dfs( mat[v] ))
                {
                    mat[v]=u;
                    return 1;
                }
            }
        return 0;
    }

    int hungry()
    {
        memset(mat,-1,sizeof(mat));
        int ans=0;
        for(int i=0;i<n;++i)
        {
            memset(flag,0,sizeof(flag));
            ans+=dfs(i);                    
        }
        return ans;
    }

    bool ok(int p)
    {
        build(key[p]);
        return hungry()>=match;
    }

    void process()
    {
        read();

        int bgn=0,end=tot-1;
        while(bgn<=end)
        {
            int mid=(bgn+end)>>1;
            if(ok(mid))
                end=mid-1;
            else
                bgn=mid+1;
        }

        if(bgn==tot)
            puts("Impossible");
        else
            printf("%d\n",static_cast<int>( ceil( sqrt( static_cast<double>(key[bgn]) ) ) ) );
    }
}key;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d",&dataset);
    while(dataset--)
    {
        key.process();
    }

    return 0;
}

