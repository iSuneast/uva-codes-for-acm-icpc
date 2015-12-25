/*
 * 10735 - Euler Circuit
 *
 * graph theory...
 * euler path in complex graph
 *
 * use max_flow to make the edge become directed
 * build the graph and use Circle_Finding_Algorithm to find the euler path
 */

#include<cstdio>
#include<cstring>
#define MAXN 105
#define MAXE 100000
#define NODE_CNT 1003
using namespace std;
const int INF=0x3f3f3f3f;

struct ISAP
{
    struct EDGE
    {
        int v,cap;
        EDGE *next,*rev;
    }*edge[MAXN],data[MAXE],*cur_edge[MAXN],*rev_edge[MAXN];
    int tot,node,src,snk;

    void graph_init(int _src,int _snk,int _node)
    {
        src=_src;   snk=_snk;   node=_node;
        tot=0;
        memset(edge,0,sizeof(edge));
    }

    void make_edge(EDGE *cur,int u,int v,int cap,EDGE *rev)
    {
        cur->v=v;   cur->cap=cap;
        cur->next=edge[u];  edge[u]=cur;    cur->rev=rev;
    }
    void link(int u,int v,int cap)
    {
        make_edge(&data[tot],u,v,cap,&data[tot+1]);
        make_edge(&data[tot+1],v,u,0,&data[tot]);
        tot+=2;
    }

    int q[MAXN],dis[MAXN],cnt[MAXN];

    void rev_bfs()
    {
        memset(dis,0x3f,sizeof(dis));
        memset(cnt,0,sizeof(cnt));

        int u=snk,front=0,rear=0;
        q[rear++]=u;    dis[u]=0;   cnt[0]=1;
        while(front<rear)
        {
            u=q[front++];
            for(EDGE *cur=edge[u];cur;cur=cur->next)
            {
                if(dis[cur->v]!=INF)
                    continue;
                dis[cur->v]=dis[u]+1;
                ++cnt[ dis[cur->v] ];
                q[rear++]=cur->v;
            }
        }
    }

    void ChkMin(int &cur,int t)
    {
        if(cur>t)
            cur=t;
    }

    int augment()
    {
        int flow=INF;
        for(int u=src;u!=snk;u=cur_edge[u]->v)
            ChkMin(flow,cur_edge[u]->cap);

        for(int u=src;u!=snk;u=cur_edge[u]->v)
        {
            cur_edge[u]->cap-=flow;
            cur_edge[u]->rev->cap+=flow;
        }

        return flow;
    }

    int isap()
    {
        int flow=0,u=src;
        rev_bfs();
        memcpy(cur_edge,edge,sizeof(edge));

        while(dis[src]<node)
        {
            if(u==snk)
            {
                flow+=augment();
                u=src;
            }

            EDGE *cur=cur_edge[u];
            for(;cur;cur=cur->next)
                if(cur->cap && dis[u]==dis[cur->v]+1)
                    break;

            if(cur)
            {
                cur_edge[u]=cur;
                rev_edge[cur->v]=cur->rev;
                u=cur->v;
            }
            else
            {
                if(!(--cnt[dis[u]]))
                    break;
                cur_edge[u]=edge[u];
                int dist=node;
                for(cur=edge[u];cur;cur=cur->next)
                    if(cur->cap)
                        ChkMin(dist,dis[cur->v]);
                dis[u]=dist+1;
                ++cnt[ dis[u] ];
                if(u!=src)
                    u=rev_edge[u]->v;
            }
        }

        return flow;
    }
}MaxFlow;

struct EULER
{
    struct EDGE
    {
        int v;
        bool flag;
        EDGE *next;
    }*edge[MAXN],data[MAXE];
    int tot;

    void graph_init()
    {
        memset(edge,0,sizeof(edge));
        tot=0;
    }
    void link(int u,int v)
    {
        data[tot].v=v;  data[tot].flag=false;
        data[tot].next=edge[u]; edge[u]=&data[tot++];
    }

    int key[NODE_CNT],cnt;
    
    void dfs(int u)
    {
        for(EDGE *cur=edge[u];cur;cur=cur->next)
            if(!cur->flag)
            {
                cur->flag=true;
                dfs(cur->v);
            }
        key[cnt++]=u;
    }

    void find(int m)
    {
        cnt=0;
        dfs(1);
        for(int i=m;i>0;--i)
            printf("%d ",key[i]);
        puts("1");
    }
}euler;

int id[MAXN],od[MAXN],key,n,m;

bool DataInit()
{
    int u,v;
    char dir[3];

    scanf("%d%d",&n,&m);
    MaxFlow.graph_init(0,n+1,n+2);
    euler.graph_init();
    memset(id,0,sizeof(id));
    memset(od,0,sizeof(od));
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%s",&u,&v,dir);
        if(dir[0]=='U')
            MaxFlow.link(u,v,1);
        else
            euler.link(u,v);
        ++od[u];    ++id[v];
    }

    key=0;
    for(int i=1;i<=n;++i)
    {
        int d=id[i]-od[i];
        if(d&1)
            return false;
        d/=2;
        if(d<0)
            MaxFlow.link(0,i,-d);
        else
        {
            MaxFlow.link(i,n+1,d);
            key+=d;
        }
    }

    return true;
}

int degree[MAXN];

void build()
{
    for(int u=1;u<=n;++u)
        for(ISAP::EDGE *cur=MaxFlow.edge[u];cur;cur=cur->next)
            if(cur->v && cur->v<=n && cur->cap)
                euler.link(u,cur->v);
}

bool flag[MAXN];

void dfs_vis(int u)
{
    flag[u]=true;
    for(EULER::EDGE *cur=euler.edge[u];cur;cur=cur->next)
        if(!flag[cur->v])
            dfs_vis(cur->v);
}

bool cc()
{
    build();

    memset(flag,0,sizeof(flag));
    dfs_vis(1);
    for(int i=1;i<=n;++i)
        if(!flag[i])
            return false;
    return true;
}

void process()
{
    if(!DataInit() || MaxFlow.isap()!=key || !cc())
    {
        puts("No euler circuit exist");
        return ;
    }

    euler.find(m);
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
        process();

        if(dataset)
            putchar(10);
    }

    return 0;
}

