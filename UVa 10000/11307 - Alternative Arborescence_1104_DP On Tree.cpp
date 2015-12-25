/*
 * 11307 - Alternative Arborescence
 *
 * DP On Tree...
 *
 * it's not an Bin-Color problem
 * but a DP On Tree
 * because we can use more than two colors and product better answer
 *
 * so use dp[Node][Color] to store the minimum answer in the tree of root Node
 * for ColorOfNodeU = 1 -> MaxPossibleColor
 *      dp[ u ][ ColorOfNodeU ] = ColorOfNodeU
 *      for ChildOfNodeU
 *          dp[ u ][ ColorOfNodeU ] += min( dp[v][ ColorOfNodeV ] )
 *              ------ColorOfNodeV = 1 -> MaxPossibleColor
 *              ------ && ColorOfNodeV != ColorOfNodeU
 *
 * finally, the minimum value of dp[0][ Color ] is the answer...
 *
 * p.s. I used MaxPossibleColor = log( MAXNode ) to store the correct and got AC
 *      but I don't know the exact value of MaxPossibleColor
 */

#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 10003
#define DEPTH 12
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
    int v;
    EDGE *next;
}*edge[MAXN],data[MAXN<<1];
int n,pos,dp[MAXN][DEPTH];
bool flag[MAXN];

void link(int u,int v)
{
    data[pos].v=v;
    data[pos].next=edge[u];
    edge[u]=&data[pos++];
}

bool input()
{
    scanf("%d",&n);
    int u,v;
    pos=0;
    memset(edge,0,sizeof(edge));
    for(int i=0;i<n;++i)
    {
        scanf("%d%*c",&u);
        while(getchar()!='\n')
        {
            scanf("%d",&v);
            link(u,v);
            link(v,u);
        }
    }

    return n;
}

void dfs(int u)
{
    flag[u]=true;
    vector<int> child;
    for(EDGE *cur=edge[u];cur;cur=cur->next)
        if(!flag[cur->v])
        {
            dfs(cur->v);
            child.push_back(cur->v);
        }
    int sz=child.size();

    for(int color=1;color<DEPTH;++color)
    {
        dp[u][color]=color;
        for(int v=0;v<sz;++v)
        {
            int tmp=INF;
            for(int ChildColor=1;ChildColor<DEPTH;++ChildColor)
            {
                if(ChildColor==color)
                    continue;
                tmp=min(tmp,dp[ child[v] ][ ChildColor ]);
            }
            dp[u][color]+=tmp;
        }
    }
}

int process()
{
    memset(flag,0,sizeof(flag));
    memset(dp,0x3f,sizeof(dp));

    dfs(0);

    int key=INF;
    for(int i=1;i<DEPTH;++i)
        key=min(key,dp[0][i]);

    printf("%d\n",key);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(input())
    {
        process();
    }

    return 0;
}

