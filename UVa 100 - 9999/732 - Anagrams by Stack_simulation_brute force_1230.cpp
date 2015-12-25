/*
 * 732 - Anagrams by Stack
 *
 * brute force..
 * use a simple dfs function to simulate find all valid answers...
 * notices that, if possible we should do the "i" function at first, no "o"
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1003
using namespace std;

struct STACK
{
    char str[MAXN];
    int pstk;
}stk;

char s[MAXN],e[MAXN];
char ts[MAXN],te[MAXN];
int ls,le,end;
bool push[MAXN];

void yes()
{
    for(int i=0;i+1<end;++i)
        printf("%c ",push[i]?'i':'o');
    printf("%c\n",push[end-1]?'i':'o');
}

void dfs(int ps,int pe,int p,STACK stk)
{
    if(p==end)
        return yes();

    if(ps!=ls)
    {
        stk.str[stk.pstk++]=s[ps];
        push[p]=true;
        dfs(ps+1,pe,p+1,stk);
        stk.pstk--;
    }

    if(stk.pstk && e[pe]==stk.str[stk.pstk-1])
    {
        push[p]=false;
        stk.pstk--;
        dfs(ps,pe+1,p+1,stk);
    }
}


void process()
{
    ls=strlen(s);
    le=strlen(e);
    if(ls!=le)
        return ;
    
    strcpy(ts,s);   sort(ts,ts+ls);
    strcpy(te,e);   sort(te,te+le);
    if(strcmp(ts,te))
        return ;

    end=ls+le;
    stk.pstk=0;
    dfs(0,0,0,stk);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(gets(s) && gets(e))
    {
        puts("[");
        process();
        puts("]");
    }

    return 0;
}

