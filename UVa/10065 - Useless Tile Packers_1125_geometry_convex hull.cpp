/*
 * 10065 - Useless Tile Packers
 *
 * geometry...
 * convex hull...
 *
 * use definite integral to calc the original square at first
 * work out the convex polygon, and calc the square of the polygon
 *
 * solved...
 */

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 103
using namespace std;

struct POINT
{
    int x,y;
}bgn;

int cross(const POINT &a,const POINT &b,const POINT &c)
{
    return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}

int sqr(const int &t)
{
    return t*t;
}

int dis(const POINT &a,const POINT &b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}

int GrahamCmp(const POINT &a,const POINT &b)
{
    int tmp=cross(bgn,a,b);
    return tmp>0 || (tmp==0 && dis(bgn,a)<dis(bgn,b));
}

struct CONVEX
{
    POINT pnt[MAXN];
    int n;
    int linesqr(POINT &a,POINT &b)
    {
        return (b.x-a.x)*(b.y+a.y);
    }
    bool read()
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d%d",&pnt[i].x,&pnt[i].y);
        pnt[n]=pnt[0];
        return n;
    }
    double OriginalSqr()
    {
        double key=0;
        for(int i=0;i<n;++i)
            key+=linesqr(pnt[i],pnt[i+1]);
        return fabs(key/2.0);
    }

    void Graham()
    {
        int p=0;
        for(int i=1;i<n;++i)
            if(pnt[i].x<pnt[p].x || (pnt[i].x==pnt[p].x && pnt[i].y<pnt[p].y))
                p=i;
        swap(pnt[p],pnt[0]);
        bgn=pnt[0];
        sort(pnt+1,pnt+n,GrahamCmp);

        p=2;
        for(int i=2;i<n;++i)
        {
            while(p>2 && cross(pnt[p-2],pnt[p-1],pnt[i])<0)
                --p;
            pnt[p++]=pnt[i];
        }
        pnt[n=p]=pnt[0];
    }

    double PolygonSqr()
    {
        Graham();
        double key=0;
        for(int i=2;i<n;++i)
            key+=cross(pnt[0],pnt[i-1],pnt[i]);
        return key/2.0;
    }
}polygon;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int cas=1;
    while(polygon.read())
    {
        printf("Tile #%d\n",cas++);
        printf("Wasted Space = %.2lf %%\n\n",100.0-polygon.OriginalSqr()/polygon.PolygonSqr()*100.0);
    }

    return 0;
}

