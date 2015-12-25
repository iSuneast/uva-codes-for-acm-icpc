/*
 * 11286 - Conformity
 *
 * Ad hoc...
 *
 * find the sets with maximum number of students
 * and count how many students in these sets...
 * (they can be in different sets)
 */

#include<iostream>
#include<algorithm>
#define MAXN 10003
using namespace std;

struct DATA
{
    int var[5];
    bool operator<(const DATA &t)const
    {
        for(int i=0;i<4;++i)
        {
            if(var[i]!=t.var[i])
                return var[i]<t.var[i];
        }
        return var[4]<t.var[4];
    }
    bool operator==(const DATA &t)const
    {
        return memcmp(var,t.var,sizeof(var))==0;
    }
}data[MAXN];
int n,ans[MAXN],cnt[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<5;++j)
            {
                scanf("%d",&data[i].var[j]);
            }
            sort(data[i].var,data[i].var+5);
        }

        sort(data,data+n);

        int p=0;
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));

        cnt[0]=1;
        ans[ cnt[0] ]++;
        for(int i=1;i<n;++i)
        {
            if(data[i]==data[p])
            {
                cnt[p]++;
            }
            else
            {
                p=i;
                cnt[p]++;
            }
            ans[ cnt[p] ]++;
        }

        for(int i=n-1;i>=0;--i)
            if(ans[i])
            {
                printf("%d\n",i*ans[i]);
                break;
            }
    }
    
    return 0;
}
