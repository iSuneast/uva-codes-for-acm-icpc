/*
 * 914 - Jumping Champion
 *
 * number theory...
 * sieve all the prime till 10^6
 * O(N) scan and statistics will do...
 *
 * no strick...
 */

#include<cstdio>
#include<algorithm>
#include<map>
#define MAXN 1000001
#define SZ 78500
using namespace std;

bool fade[MAXN];
int prime[SZ],tot;
int l,u;

void init()
{
    prime[0]=2; tot=1;
    for(int i=3;i<MAXN;i+=2)
    {
        if(fade[i])
            continue;
        prime[tot++]=i;
        for(int j=i<<1;j<MAXN;j+=i)
            fade[j]=true;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d",&dataset);
    init();
    while(dataset--)
    {
        scanf("%d%d",&l,&u);
        int bgn=lower_bound(prime,prime+tot,l)-prime;
        int end=lower_bound(prime,prime+tot,u)-prime;
        if(prime[end]>u)
            --end;

        map<int,int> mii;
        int key,cnt=0,keyn=0,tmp;
        for(;bgn<end;++bgn)
        {
            tmp=prime[bgn+1]-prime[bgn];
            if(mii.find(tmp)==mii.end())
            {
                mii[tmp]=1;
                if(1>cnt)
                {
                    cnt=1;
                    key=tmp;
                    keyn=1;
                }
                else if(1==cnt)
                    keyn++;
            }
            else
            {
                int buf=++mii[tmp];
                if(buf>cnt)
                {
                    cnt=buf;
                    key=tmp;
                    keyn=1;
                }
                else if(buf==cnt)
                    keyn++;
            }
        }

        if(keyn==1)
            printf("The jumping champion is %d\n",key);
        else
            puts("No jumping champion");
    }

    return 0;
}

