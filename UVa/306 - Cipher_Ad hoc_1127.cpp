/*
 * 306 - Cipher
 *
 * Ad hoc...
 * no trick...
 * but "Each encoded message in the output file has the lenght n."
 * so, don't delete the tail blanks of the answer...
 *
 * try to find out the Number-Cycle
 * "1 2 3"->"3 1 2" then "1->3 3->2 2->1" ------ a cycle of 3 elements...
 * final[1] : 1 3 2        mod[1]=3
 * final[2] : 2 1 3        mod[2]=3
 * final[3] : 3 2 1        mod[2]=3
 *
 * for char s[p] its final place is final[p][ N%mod[p] ]
 * output..
 * done!
 */

#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 203
using namespace std;

vector<int> final[MAXN];
int n,key[MAXN],mod[MAXN],next;
int flag[MAXN];
char s[MAXN],ans[MAXN];

void process()
{
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=n;++i)
    {
        final[i].clear();
        
        if(flag[i])
        {
            int t=i;
            while(flag[t]!=i)
            {
                flag[t]=i;
                final[i].push_back(t);
                t=key[t];
            }
            
            continue;
        }
        
        int p=0,t=i;
        while(!flag[t])
        {
            flag[t]=-1;
            t=key[t];
            ++p;
        }

        t=i;
        while(flag[t]!=i)
        {
            flag[t]=i;
            final[i].push_back(t);
            mod[t]=p;
            t=key[t];
        }
    }
}

void done()
{
    for(int i=1;i<=n;++i)
        ans[i]=' ';
    ans[n+1]=0;
    
    for(int i=1;s[i];++i)
        ans[ final[i][ next%mod[i] ] ]=s[i];
    
    puts(ans+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&key[i]);
        }
        process();
        
        while(scanf("%d",&next)!=EOF && next)
        {
            gets(s);
            done();
        }
        putchar(10);
    }

    return 0;
}

