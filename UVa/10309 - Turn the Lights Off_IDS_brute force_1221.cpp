/*
 * 10309 - Turn the Lights Off
 *
 * brute force...
 * IDS...
 *
 * Iterative Deepening Search with Pruning...
 *
 * clearly, for every grid, we have to PRESS at most ONCE...
 * scan from top to bottom, and left too right,
 * check
 * if(g[x-1][y]=='O') we must PRESS
 * if(g[x-1][y]=='X') we must NOT PRESS
 * otherwise, we don't know how to do, so just try above two ways...
 */

#include<cstdio>
#include<cstring>
#define MAXN 13
using namespace std;

char anti[128];
const int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};
char g[MAXN][MAXN],name[10000];
bool got;
int end;

void chk()
{
    for(int i=1;i<=10;++i)
    {
        for(int j=1;j<=10;++j)
            if(g[i][j]=='O')
                return ;
    }
    got=true;
}

bool fine(int x)
{
    for(int i=1;i<=10;++i)
        if(g[x][i]=='O')
            return false;
    return true;
}

void press(int x,int y)
{
    for(int d=0;d<5;++d)
        g[ x+dx[d] ][ y+dy[d] ]=anti[ g[ x+dx[d] ][ y+dy[d] ] ];
}

void dfs(int x,int y,int depth)
{
    if(got)
        return ;
    if(depth==end || x==11)
        return chk();

    if(y==11)
    {
        if(fine(x-1))
            dfs(x+1,1,depth);
        return ;
    }

    if(g[x-1][y]=='O')  //must PRESS!
    {
        press(x,y);
        dfs(x,y+1,depth+1);
        press(x,y);
    }
    else if(g[x-1][y]=='#') //mustn't PRESS!
        dfs(x,y+1,depth);
    else                //don't know how to do. just have a TRY...
    {
        press(x,y);
        dfs(x,y+1,depth+1);
        press(x,y);
        dfs(x,y+1,depth);
    }
}

void init()
{
    for(int i=0;i<128;++i)
        anti[i]=i;
    anti['O']='#';
    anti['#']='O';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    while(scanf("%s",name)!=EOF && strcmp(name,"end"))
    {
        for(int i=1;i<=10;++i)
            scanf("%s",g[i]+1);
        got=false;
        for(end=0;end<=100;++end)
        {
            dfs(1,1,0);
            if(got)
                break;
        }
        
        if(!got)
            end=-1;
        printf("%s %d\n",name,end);
    }

    return 0;
}

