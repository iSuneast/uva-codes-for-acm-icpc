/*
 * 10017 - The Never Ending Towers of Hanoi
 *
 * Ad hoc...
 * simulation...
 * 
 * just an easy problem
 * simulate as the problem description
 */


#include<cstdio>
#define MAXN 256

int n,m,cnt;
int q[3][MAXN],sz[3];
const char key[]="ABC";

void output()
{
    ++cnt;
    if(cnt>m)
        return ;
    for(int i=0;i<3;++i)
    {
        printf("%c=>",key[i]);
        if(sz[i])
            printf("  ");
        for(int j=0;j<sz[i];++j)
            printf(" %d",q[i][j]);
        putchar(10);
    }
    
    putchar(10);
}

void move(int start,int end)
{
    q[ end ][ sz[end]++ ]=q[ start ][ --sz[start] ];
}

void dfs(int n,int start,int tmp,int end)
{
    if(cnt>m)
        return ;
    if(n==1)
    {
        move(start,end);
        output();
    }
    else
    {
        dfs(n-1,start,end,tmp);
        move(start,end);
        output();
        dfs(n-1,tmp,start,end);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int cas=1;
    while(scanf("%d%d",&n,&m)!=EOF && (n||m))
    {
        printf("Problem #%d\n\n",cas++);
        
        sz[0]=sz[1]=sz[2]=0;
        for(int i=n;i;--i)
            q[0][ sz[0]++ ]=i;

        cnt=-1;
        output();
        dfs(n,0,1,2);
    }
    
    return 0;
}

