/*
 * 833 - Water Falls
 *
 * geometry...
 * just simulate as the problem description...
 *
 * no tricks..
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 1003
using namespace std;

struct POINT
{
    int x,y;
    bool operator<(const POINT &t)const
    {
        return y<t.y;
    }
}src;

struct SEG
{
    POINT l,r;
}seg[MAXN];

int np,ns;
bool flag[MAXN];

bool up(POINT &a,POINT &b,POINT &c)
{
    return (b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y)<=0;
}

double yCoordinary(POINT &a,POINT &b,POINT &c)
{new file
    return (a.x-b.x)*(c.y-b.y)/static_cast<double>(c.x-b.x)+b.y;
}

int process()
{
    memset(flag,0,sizeof(flag));
    while(true)
    {
        int p=-1;
        for(int i=0;i<np;++i)
        {
            if(flag[i])
                continue;

            if(seg[i].l.x<=src.x && src.x<=seg[i].r.x
                    && up(src,seg[i].l,seg[i].r))
            {
                if(p==-1 || yCoordinary(src,seg[p].l,seg[p].r)<yCoordinary(src,seg[i].l,seg[i].r))
                    p=i;
            }
        }

        if(p==-1)
            return src.x;

        flag[p]=true;new file
        src=min(seg[p].l,seg[p].r);
    }
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
        scanf("%d",&np);
        int t=0;
        for(int i=0;i<np;++i)
        {
            scanf("%d%d%d%d",&seg[t].l.x,&seg[t].l.y,&seg[t].r.x,&seg[t].r.y);
            if(seg[i].l.x>seg[i].r.x)
                swap(seg[i].l,seg[i].r);

            if(seg[t].l.y!=seg[t].r.y)
                ++t;
        }
        np=t;

        scanf("%d",&ns);
        while(ns--)
        {
            scanf("%d%d",&src.x,&src.y);
            printf("%d\n",process());
        }

        if(dataset)
            putchar(10);
    }

    return 0;
}

