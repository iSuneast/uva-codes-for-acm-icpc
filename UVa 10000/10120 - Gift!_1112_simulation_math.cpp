/*
 * 10120 - Gift?!
 *
 * simulation...
 * 
 * beautiful solution...
 * http://www.algorithmist.com/index.php/UVa_10120
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 1000003
using namespace std;

int n,m,sz[2],q[2][MAXN],got[2][MAXN],flag[MAXN];
bool yes;

void done(int q2[MAXN],int &sz2,int &dep,int &ori,int &t,int &next)
{
    if(flag[t]!=dep)
        q2[sz2++]=t;
    flag[t]=dep;
    
    if(t==m)
        got[next][t]=dep;
    if(got[1-next][ori]==dep-1)
        got[next][t]=dep;
}

bool process(int q1[MAXN],int &sz1,int q2[MAXN],int &sz2,int &dep,int &next)
{
    sz2=0;
    int jump=dep*2-1;
    flag[0]=flag[n+1]=dep;

    for(int i=0;i<sz1;++i)
    {
        int t=q1[i]-jump;
        if(t>=0)
            done(q2,sz2,dep,q1[i],t,next);

        t=q1[i]+jump;
        if(t<=n+1)
            done(q2,sz2,dep,q1[i],t,next);
        else if(got[1-next][ q1[i] ]==dep-1)
            yes=true;
    }
}

bool ok()
{
    if(n>=49)
        return true;
    int dep=0,cur=0,next=1;
    sz[0]=sz[1]=0;
    
    q[ cur ][ sz[ cur ]++ ]=0;
    memset(got,-1,sizeof(got));
    memset(flag,0,sizeof(flag));
    yes=false;
    
    while(sz[ cur ])
    {
        process(q[cur],sz[cur],q[next],sz[next],++dep,next);
        if(got[next][0]==dep || got[next][n+1]==dep || yes)
            return true;

        swap(cur,next);
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d%d",&n,&m)!=EOF && (n||m))
    {
        puts(ok()?"Let me try!":"Don't make fun of me!");
    }

    return 0;
}

