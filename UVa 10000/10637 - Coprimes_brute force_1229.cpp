/*
 * 10637 - Coprimes
 *
 * brute force...
 *
 * a brute force solution with simple pruning will do...
 */

#include<cstdio>
#include<cstring>
#define MAXN 103
using namespace std;

bool ok[MAXN][MAXN];

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

void init()
{
    memset(ok,0,sizeof(ok));
    for(int i=1;i<MAXN;++i)
    {
        for(int j=1;j<=i;++j)
            ok[i][j]=ok[j][i]=(gcd(i,j)==1);
    }
}

int key[MAXN],dep;

void output()
{
    for(int i=dep;i>1;--i)
        printf("%d ",key[i]);
    printf("%d\n",key[1]);
}

bool add(int a,int t)
{
    for(int i=t+1;i<=dep;++i)
        if(!ok[a][ key[i] ])
            return false;
    return true;
}

void dfs(int s,int t)
{
    if(!t)
    {
        if(!s)
            output();
        return ;
    }

    if(s<key[t+1]*t)
        return ;

    for(int i=key[t+1];i<=s;++i)
    {
        if(!add(i,t))
            continue;
        key[t]=i;
        dfs(s-i,t-1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    int dataset,s,t;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
        scanf("%d%d",&s,&t);
        printf("Case %d:\n",cas);
        memset(key,0,sizeof(key));  key[t+1]=1;
        dfs(s,dep=t);
    }

    return 0;
}

