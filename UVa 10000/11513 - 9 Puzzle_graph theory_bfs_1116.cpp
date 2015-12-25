/*
 * 11513 - 9 Puzzle
 *
 * bfs...
 * almost the same with 8 puzzle...
 * a simple trick, which that the Original state is already the Final state
 * the answer is "0 " (a blank here..)
 */

#include<cstdio>
#include<cstring>
#include<vector>
#define HASH 802909
#define MAXN 362887
#define SZ 3
using namespace std;

struct DATA
{
    char puzzle[SZ][SZ];
    int fa,pase,d;
}key[MAXN];
int sz=0,q[MAXN];
vector<int> h[HASH];

int mapping(int u)
{
    long long v=0;
    for(int i=0;i<SZ;++i)
        for(int j=0;j<SZ;++j)
            v=v*10+key[u].puzzle[i][j];

    return v%HASH;
}

int insert(int &u)
{
    int p=mapping(u),_sz=h[p].size();
    for(int i=0;i<_sz;++i)
        if(memcmp(key[u].puzzle,key[ h[p][i] ].puzzle,sizeof(char)*SZ*SZ)==0)
            return h[p][i];
    return -1;
}

void bfs()
{
    for(int i=0;i<9;++i)
        key[0].puzzle[i/3][i%3]=i;
    key[0].fa=0; key[0].pase=0;    key[0].d=0;
    ++sz;

    int front=0,rear=0;
    char t;
    q[rear++]=0;
    h[ mapping(0) ].push_back(0);

    while(front<rear)
    {
        int u=q[front++];
        
        for(int i=0;i<SZ;++i)
        {
            key[sz]=key[u];
            DATA &tmp=key[sz];
            t=tmp.puzzle[i][0];
            for(int j=0;j+1<SZ;++j)
                tmp.puzzle[i][j]=tmp.puzzle[i][j+1];
            tmp.puzzle[i][2]=t;

            if(insert(sz)==-1)
            {
                tmp.fa=u;
                tmp.pase=10+i;
                h[ mapping(sz) ].push_back(sz);
                key[sz].d=key[u].d+1;
                q[rear++]=sz++;
            }
        }

        for(int j=0;j<SZ;++j)
        {
            key[sz]=key[u];
            DATA &tmp=key[sz];
            t=tmp.puzzle[SZ-1][j];
            for(int i=SZ-1;i;--i)
                tmp.puzzle[i][j]=tmp.puzzle[i-1][j];
            tmp.puzzle[0][j]=t;

            if(insert(sz)==-1)
            {
                tmp.fa=u;
                tmp.pase=j;
                h[ mapping(sz) ].push_back(sz);
                key[sz].d=key[u].d+1;
                q[rear++]=sz++;
            }
        }
    }
}

void dfs(int u)
{
    printf("%c%d",key[u].pase/10?'H':'V',key[u].pase%10+1);
    if(key[u].fa)
        dfs(key[u].fa);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    bfs();
    DATA &cur=key[sz];
    char s[3];
    while(true)
    {
        int t=0;
        do
        {
            scanf("%s",s);
        }while(s[0]!='0' && (cur.puzzle[t/3][t%3]=s[0]-'1')>-1 && ++t<9);
        if(t==0)
            break;

        if((t=insert(sz))==-1)
            puts("Not solvable");
        else
        {
            if(t==0)
            {
                puts("0 ");
                continue;
            }
            printf("%d ",key[t].d);
            dfs(t);
            putchar(10);
        }
    }

    return 0;
}

