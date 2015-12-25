/*
 * 11048 - Automatic Correction of Misspellings
 *
 * String...
 *
 * Quite a simple problem, but unfornatunally I got WA many times...
 *
 * first, try to put strings into different categories according to their length
 * find the string with the same length,
 *      If there is a one matches with S, we now find it
 *      else we should check rule 2
 * we check rule 1 then, it's a simple task...
 *
 * p.s there are no tricks in the problem, but
 *      "In the case that there are several possibilities,
 *      select the word from the dictionary which appeared earlier in the input."
 *
 * I got WA, because of silly mistake. = =
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 10003
#define LEN 27
using namespace std;

struct STR
{
    char s[LEN];
    int p;
}data[LEN][MAXN],buf;
int sz[LEN];
int n,q;

bool FewLetter(char *a,char *b,const int &l)
{
    for(int i=0;i<l;++i)
        if(a[i]!=b[i])
            return strcmp(a+i,b+i+1)==0;
}

bool SwapOnce(char *a,char *b,int &l)
{
    int wrong=0;
    for(int i=0;i<l;++i)
    {
        if(a[i]!=b[i])
        {
            ++wrong;
            if(i==l-1)
                continue;
            
            swap(a[i],a[i+1]);
            bool yes=(strcmp(a,b)==0);
            swap(a[i],a[i+1]);

            if(yes)
                return true;
        }
    }
    return wrong==1;
}

void process(char *s,int l)
{    
    for(int i=0;i<sz[l];++i)
    {
        if(strcmp(data[l][i].s,s)==0)
        {
            printf("%s is correct\n",s);
            return ;
        }
    }

    int p=n,x,y;
    for(int i=0;i<sz[l];++i)
    {
        if(SwapOnce(data[l][i].s,s,l))
        {
            if(data[l][i].p<p)
            {
                p=data[l][i].p;
                x=l;    y=i;
            }
            break;
        }
    }

    l--;
    for(int i=0;i<sz[l];++i)
    {
        if(FewLetter(data[l][i].s,s,l+1))
        {
            if(data[l][i].p<p)
            {
                p=data[l][i].p;
                x=l;    y=i;
            }
            break;
        }
    }

    l+=2;
    for(int i=0;i<sz[l];++i)
    {
        if(FewLetter(s,data[l][i].s,l))
        {
            if(data[l][i].p<p)
            {
                p=data[l][i].p;
                x=l;    y=i;
            }
            break;
        }
    }

    if(p!=n)
        printf("%s is a misspelling of %s\n", s, data[x][y].s);
    else
        printf("%s is unknown\n",s);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int l;
    memset(sz,0,sizeof(sz));
    
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%s",buf.s);
        buf.p=i;
        l=strlen(buf.s);
        data[l][ sz[l]++ ]=buf;
    }

    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",buf.s);
        process(buf.s,strlen(buf.s));
    }

    return 0;
}

