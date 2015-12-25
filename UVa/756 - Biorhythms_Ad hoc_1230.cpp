/*
 * 756 - Biorhythms
 *
 * Ad hoc...
 * a simple problem with no tricks...
 */

#include<cstdio>
#include<cstring>
#define MAXN 22000
using namespace std;

int p,e,i,d,cnt[MAXN];

void process(int n,int j)
{
    for(n%=j;n<MAXN;n+=j)
        cnt[n]++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    for(int cas=1;scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF && (p!=-1 || e!=-1 || i!=-1 || d!=-1);++cas)
    {
        memset(cnt,0,sizeof(cnt));
        process(p,23);
        process(e,28);
        process(i,33);

        for(int j=d+1;j<MAXN;++j)
        {
            if(cnt[j]==3)
            {
                printf("Case %d: the next triple peak occurs in %d days.\n",cas,j-d);
                break;
            }
        }
    }

    return 0;
}

