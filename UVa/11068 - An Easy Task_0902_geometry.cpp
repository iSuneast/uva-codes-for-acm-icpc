/*
 * 11068 - An Easy Task
 *
 * geometry...
 * find the intersect of two line
 */

#include<iostream>
using namespace std;

struct TLine{    double a,b,c;  }u,v;
struct TPoint{    double x,y;   };

TPoint line_intersect(TLine l1,TLine l2)
{
    TPoint key;
    if(l1.b==0)
    {
        key.x=l1.c/l1.a;
        key.y=(l2.c-l2.a*key.x)/l2.b;
    }
    else
    {
        key.x=(l1.b*l2.c-l1.c*l2.b)/(l1.b*l2.a-l2.b*l1.a);
        key.y=(l1.c-l1.a*key.x)/l1.b;
    }
    return key;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%lf%lf%lf",&u.a,&u.b,&u.c)!=EOF && (u.a || u.b || u.c))
    {
        scanf("%lf%lf%lf",&v.a,&v.b,&v.c);
        if(u.a*v.b==v.a*u.b)
            puts("No fixed point exists.");
        else
        {
            TPoint ans=line_intersect(u,v);
            printf("The fixed point is at %.2lf %.2lf.\n",ans.x,ans.y);
        }
    }

    return 0;
}
