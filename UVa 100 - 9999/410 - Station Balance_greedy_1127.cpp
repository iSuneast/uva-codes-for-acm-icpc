/*
 * 410 - Station Balance
 *
 * greedy...
 * 
 * it's an fairy simple greedy problem...
 * sort array A[]
 * we can divide array into tree type of sub-groups
 * @ 1 element only: the maximum integer remains in the array
 * @ 2 elements    : the maximum integer and sub-maximum integer remain in the array
 * @ 0 element     : a group with none integer...
 *
 * so the final answer is to imply the above greedy method and calculate the answer...
 */

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 13
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int var[MAXN],g,n,cas=1;
    while(scanf("%d%d",&g,&n)!=EOF)
    {
        double s=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&var[i]);
            s+=var[i];
        }
        sort(var,var+n);
        s/=g;

        printf("Set #%d\n",cas++);
        double key=s*g;
        int gp=0,pre=0,end=n-1;
        while(pre<=end)
        {
            key-=s;
            if((g-gp)*2 == end-pre+1)
            {
                key+=fabs(var[end]+var[pre]-s);
                printf(" %d: %d %d\n",gp++,var[pre++],var[end--]);
            }
            else
            {
                key+=fabs(var[end]-s);
                printf(" %d: %d\n",gp++,var[end--]);
            }
        }
        for(;gp<g;++gp)
            printf(" %d:\n",gp);

        printf("IMBALANCE = %.5lf\n\n",key);
    }

    return 0;
}

