/*
 * 11414 - Dream
 * 
 * graph theory...
 * given the degree of every vertex..
 * check whether the graph is a simple graph...
 * 
 * let n be the number of remaining vertex..
 * first, just sort the degree up to down
 * del the vertex with degree=0
 *  and check whether n-1>=vertex[0],
 * if yes scan from i=[1-vertex[0]], vertex[i]-=1
 * finally ,if there is no more vertex exist
 * the ans is Yes
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1003
using namespace std;

int var[MAXN],n;

int cmp(const int a,const int b)
{
    return a>b;
}

bool process()
{
    while(n)
    {
        sort(var,var+n,cmp);
        while(n && !var[n-1])
            --n;
        if(!n)
            return true;
        if(var[0]<=n-1)
        {
            for(int i=1;i<=var[0];++i)
            {
                --var[i];
            }
            var[0]=0;
        }
        else
            return false;
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
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&var[i]);

        puts(process()?"Yes":"No");
    }

    return 0;
}
