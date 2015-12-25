/*
 * 799 - Safari Holiday
 *
 * math...
 *
 * if n<=kmax just print n+" persons/group, 1 day"(not days)
 * if we can find a group of K
 *    @ n%K==0, obvirously...
 *    @ there are remaining (n-1) people we need to company with
 *      every day, we can company at most (k-1) people we can company with
 *      so come out the format : (n-1)%(k-1)==0
 *      then days = (n-1)/(k-1)
 * solved...
 */

#include<cstdio>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n,kmax;
    while(scanf("%d%d",&n,&kmax)!=EOF)
    {
        if(n<=kmax)
            printf("%d persons/group, %d day\n",n,1);
        else
        {
            int key=kmax;
            for(;key>1;--key)
            {
                if(n%key==0 && (n-1)%(key-1)==0)
                    break;
            }
            if(key<=1)
                puts("No solution");
            else
                printf("%d persons/group, %d days\n",key,(n-1)/(key-1));
        }
    }

    return 0;
}

