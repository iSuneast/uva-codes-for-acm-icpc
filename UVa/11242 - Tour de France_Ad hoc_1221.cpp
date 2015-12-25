/*
 * 11242 - Tour de France
 *
 * Ad hoc...
 * just try to calculate all the ratio, sort, and divide...
 * the maximum value is the answer...
 */

#include<cstdio>
#include<algorithm>
#define MAXN 13
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    double d[MAXN*MAXN],t;
    int f,r,n[MAXN];
    while(scanf("%d%d",&f,&r)!=EOF && f)
    {
        for(int i=0;i<f;++i)
        {
            scanf("%d",&n[i]);
        }
        
        int p=0;
        for(int j=0;j<r;++j)
        {
            scanf("%lf",&t);
            for(int i=0;i<f;++i,++p)
            {
                d[p]=t/n[i];
            }
        }
        sort(d,d+p);

        double key=0;
        for(int i=1;i<p;++i)
        {
            key=max(key,d[i]/d[i-1]);
        }
        
        printf("%.2lf\n",key);
    }

    return 0;
}

