/*
 * 658 - It's not a Bug, it's a Feature!
 *
 * graph theory...
 * sssp...
 *
 * use binary_code to represent the state
 * and then just doing any SSSP algorithm is enough
 *
 * B_YES = 0        -> B_Yes += (1<<p) if operat[ n-1-p ]=='+'
 * B_NO = (1<<n)-1  -> B_NO  -= (1<<p) if operat[ n-1-p ]=='-'
 * the same as F_YES and F_NO
 * if current state is U, and ( (U|B_YES)==U && (U&B_NO)==U )
 * we get new state V = ( U|F_YES ) & F_NO
 *
 * we don't need to build the whole graph, just function the above method when necessary...
 *
 * happy coding: )
 */

#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 20
#define MAXE 103
using namespace std;
const int INF=0x7f7f7f7f;

struct SSSP
{
    int dis[1<<MAXN],n,m;
    bool inq[1<<MAXN];

    struct EDGE
    {
        int byes,bno;
        int fyes,fno,time;
    }edge[MAXE];

    void process(int &a,int &b)
    {
        char s[MAXN+3];
        scanf("%s",s);
        a=0;    b=(1<<n)-1;
        for(int i=0;i<n;++i)
        {
            int p=n-i-1;
            if(s[i]=='+')
                a|=(1<<p);
            else if(s[i]=='-')
                b-=(1<<p);
        }
    }
    void read(int _n,int _m)
    {
        n=_n;   m=_m;
        for(int i=0;i<m;++i)
        {
            scanf("%d",&edge[i].time);
            process(edge[i].byes,edge[i].bno);
            process(edge[i].fyes,edge[i].fno);
        }
    }

    void spfa()
    {
        int u=(1<<n)-1;
        queue<int> q;
        memset(dis,0x7f,sizeof(dis));
        memset(inq,0,sizeof(inq));
        q.push(u);  inq[u]=true;    dis[u]=0;
        while(!q.empty())
        {
            u=q.front();    q.pop();    inq[u]=false;
            for(int i=0;i<m;++i)
            {
                if(((u|edge[i].byes)!=u) || ((u&edge[i].bno)!=u))
                    continue;
                int v=(u|edge[i].fyes)&edge[i].fno;
                if(dis[v]>dis[u]+edge[i].time)
                {
                    dis[v]=dis[u]+edge[i].time;
                    if(!inq[v])
                        q.push(v),inq[v]=true;
                }
            }
        }

        if(dis[0]!=INF)
            printf("Fastest sequence takes %d seconds.\n",dis[0]);
        else
            puts("Bugs cannot be fixed.");
    }

}sssp;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n,m,cas=1;
    while(scanf("%d%d",&n,&m)!=EOF && (n||m))
    {
        printf("Product %d\n",cas++);
        sssp.read(n,m);
        sssp.spfa();
        putchar(10);
    }

    return 0;
}

