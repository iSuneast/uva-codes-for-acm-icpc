/*
 * 11894 - Genius MJ
 *
 * Ad hoc...
 *
 * move the points to new coordinary with min(x)=0,min(y)=0
 * try to match this two sets
 * if failed, rotate the nodes 90 degree
 * (x,y) -> ( y , max(x)-min(x)-x )
 * continued matching until the graph is rotated 4 times...
 */

#include<cstdio>
#include<algorithm>
#define MAXN 100003
#define INF 0x3f3f3f3f
using namespace std;

struct POINT
{
    int x,y;
    bool operator<(const POINT &t)const
    {
        if(x==t.x)
            return y<t.y;
        return x<t.x;
    }
}a[MAXN],ma[2],b[MAXN],mb[2];
int n;

void input(POINT *p,POINT *m)
{
    m[0].x=m[0].y=INF;
    m[1].x=m[1].y=-INF;
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
        m[0].x=min(m[0].x,p[i].x);
        m[0].y=min(m[0].y,p[i].y);

        m[1].x=max(m[1].x,p[i].x);
        m[1].y=max(m[1].y,p[i].y);
    }

    for(int i=0;i<n;++i)
    {
        p[i].x-=m[0].x;
        p[i].y-=m[0].y;
    }
}

bool ok()
{
    for(int i=0;i<n;++i)
        if(a[i].x!=b[i].x || a[i].y!=b[i].y)
            return false;
    return true;
}

bool process()
{
    int dx=mb[1].x-mb[0].x;
    int dy=mb[1].y-mb[0].y;

    sort(a,a+n);

    for(int d=0;d<4;++d)
    {
        for(int i=0;i<n;++i)
        {
            int x=b[i].x;

            b[i].x=b[i].y;
            b[i].y=dx-x;
        }
        sort(b,b+n);

        if(ok())
            return true;

        swap(dx,dy);
    }

    return false;
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
        scanf("%d",&n);
        input(a,ma);
        input(b,mb);

        puts(process()?"MATCHED":"NOT MATCHED");
    }

    return 0;
}

