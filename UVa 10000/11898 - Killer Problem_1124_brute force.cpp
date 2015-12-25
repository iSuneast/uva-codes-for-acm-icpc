/*
 * 11898 - Killer Problem
 *
 * brute force...
 *
 * first, we sort the data ascending
 * then we sort the sections ascending store the sections use be-directed links
 *
 * according to the data range
 * if the length of a section is larger than 10000, the answer should be 0
 * we delete the node from the links
 *
 * for every integer
 * scan from the head of the links
 *  if the integer's original place lie in current section
 *  we store the integer as the largest value of the current section
 *  and also we refresh the answer according to pre-stored largest value(if it exist)
 *      here, a small optimization should better use: if the answer if already ZERO,
 *      we delete the section( that's why we store the sections using links)
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200003
#define QUERY 10003
using namespace std;
const int INF=0x3f3f3f3f;

struct DATA
{
    int var,p;
    bool operator<(const DATA &t)const
    {
        return var<t.var || (var==t.var && p<t.p);
    }
}data[MAXN];

struct SECTION
{
    int s,e,p;
    SECTION *pre,*next;
    bool operator<(const SECTION &t)const
    {
        return s<t.s || (s==t.s && e<t.e);
    }
}sec[MAXN],head;
int n,q,key[MAXN],curVar[MAXN];

void read()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&data[i].var);
        data[i].p=i;
    }
    sort(data,data+n);
    
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        scanf("%d%d",&sec[i].s,&sec[i].e);
        sec[i].p=i;
        curVar[i]=key[i]=INF;
    }
    sort(sec+1,sec+q+1);
    for(int i=1;i<=q;++i)
    {
        sec[i].pre=&sec[i-1];
        sec[i].next=&sec[i+1];
    }
    sec[q].next=NULL;
    head.next=&sec[1];
}

void del(SECTION *cur)
{
    cur->pre->next=cur->next;
    if(cur->next)
        cur->next->pre=cur->pre;
}

bool ChkMin(int &key,const int &tmp)
{
    if(key>tmp)
        key=tmp;
    return !key;
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
        read();

        for(SECTION *cur=head.next;cur;cur=cur->next)
        {
            if(cur->e - cur->s>10000)
            {
                key[ cur->p ]=0;
                del(cur);
            }
        }

        for(int i=1;i<=n;++i)
        {
            SECTION *cur=head.next;
            int p=data[i].p;

            while(cur && cur->s>p)
                cur=cur->next;
            while(cur && cur->s<=p)
            {
                if(cur->e>=p)
                {
                    if(curVar[ cur->p ]==INF)
                        curVar[cur->p]=data[i].var;
                    else
                    {
                        if(ChkMin(key[ cur->p ], data[i].var-curVar[cur->p]))
                            del(cur);
                        curVar[cur->p]=data[i].var;
                    }
                }
                cur=cur->next;
            }
        }

        for(int i=1;i<=q;++i)
            printf("%d\n",key[i]);
    }

    return 0;
}

