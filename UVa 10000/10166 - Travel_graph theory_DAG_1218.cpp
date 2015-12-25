/*
 * 10166 - Travel
 *
 * graph theory...
 * DAG...
 *
 * find the shortest path in a DAG graph
 * notice the sentesence: "print 2 four-digit numbers"
 * no other tricks...
 * use spfa to handle the shortest path...
 */

#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;

struct EDGE
{
    int v,s,e;
    EDGE *next;
}*edge[MAXN],data[MAXN*MAXN*MAXN];
int bgn,end,start,tot,dis[MAXN];

void link(int u,int s,int v,int e)
{
    data[tot].s=s;  data[tot].v=v;  data[tot].e=e;
    data[tot].next=edge[u]; edge[u]=&data[tot++];
}

bool inq[MAXN];

void dp()
{
    queue<int> q;
    int bestS=0,bestE=INF;
    for(EDGE *now=edge[bgn];now;now=now->next)
    {
        if(now->s<start)
            continue;
        
        memset(dis,0x3f,sizeof(dis));   dis[now->v]=now->e;     dis[bgn]=now->s;
        q.push(now->v);
        while(!q.empty())
        {
            int u=q.front();    q.pop();
            inq[u]=false;
            for(EDGE *cur=edge[u];cur;cur=cur->next)
            {
                if(cur->s<dis[u])
                    continue;
                
                int v=cur->v;
                if(dis[v]>=cur->e)
                {
                    dis[v]=cur->e;
                    if(!inq[v])
                        q.push(v);
                    inq[v]=true;
                }
            }
        }

        if(dis[end]!=INF)
        {
            if(bestE>dis[end])
            {
                bestE=dis[end];
                bestS=now->s;
            }
            else if(bestE==dis[end])
                bestS=max(bestS,now->s);
        }
    }

    if(bestE==INF)
        puts("No connection");
    else
        printf("%04d %04d\n",bestS,bestE);
}

struct TRAIN
{
    int tm,u;
    bool operator<(const TRAIN &t)const
    {
        return tm<t.tm;
    }
}train[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int c,t,ti;
    char city[33];
    while(scanf("%d",&c)!=EOF && c)
    {
        memset(edge,0,sizeof(edge));
        tot=0;
        
        map<string,int> msi;
        for(int i=1;i<=c;++i)
        {
            scanf("%s",city);
            msi[city]=i;
        }
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&ti);
            for(int i=0;i<ti;++i)
            {
                scanf("%d%s",&train[i].tm,city);
                train[i].u=msi[city];
            }
            sort(train,train+ti);
            for(int i=1;i<ti;++i)
                link(train[i-1].u,train[i-1].tm,train[i].u,train[i].tm);
        }

        scanf("%d%s",&start,city);     bgn=msi[city];
        scanf("%s",city);           end=msi[city];

        dp();
    }

    return 0;
}

