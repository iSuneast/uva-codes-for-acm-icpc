/*
 * 704 - Colour Hash
 *
 * search...
 * my first time of DOUBLE_BFS
 * no so hard...
 * but really spend me a lot of time~
 * Happy coding...
 * : )
 */

#include<cstdio>
#include<cstring>
#include<vector>
#define MAX_STATE 21
#define HASH_SIZE 4628849
using namespace std;

const char final_state[]={0,3,4,3,0,5,6,5,0,1,2,1,0,7,8,7,0,9,10,9,0};

struct SUB
{
    char v[MAX_STATE];

    SUB left_clock()
    {
        SUB key=*this;
        for(int i=0;i<2;++i)
            key.v[i]=v[i+10];
        for(int i=2;i<12;++i)
            key.v[i]=v[i-2];
        return key;
    }

    SUB right_clock()
    {
        SUB key=*this;
        for(int i=9;i<19;++i)
            key.v[i]=v[i+2];
        for(int i=19;i<21;++i)
            key.v[i]=v[i-10];
        return key;
    }

    SUB left_counter_clock()
    {
        SUB key=*this;
        for(int i=0;i<10;++i)
            key.v[i]=v[i+2];
        for(int i=10;i<12;++i)
            key.v[i]=v[i-10];
        return key;
    }

    SUB right_counter_clock()
    {
        SUB key=*this;
        for(int i=11;i<21;++i)
            key.v[i]=v[i-2];
        for(int i=9;i<11;++i)
            key.v[i]=v[i+10];
        return key;
    }
}sub;

struct STATE
{
    struct SUB s;
    char dep,pase;
    int h,fa;
    bool flag;
    
    void read()
    {
        for(int i=0;i<MAX_STATE;++i)
        {
            scanf("%d",&h);
            s.v[i]=h;
        }
        for(int i=0;i<3;++i)
            scanf("%*d");
    }

    bool operator==(const STATE &t)const
    {
        if(h!=t.h)
            return false;
        for(int i=0;i<MAX_STATE;++i)
            if(s.v[i]!=t.s.v[i])
                return false;
        return true;
    }

    int hash()
    {
        int key=0;
        for(int i=0;i<MAX_STATE;++i)
        {
            key=key*11+s.v[i];
            key=key%HASH_SIZE;
        }
        return key;
    }    
}final,bgn,data[1<<18];

struct QUEUE
{
    int v[1<<17],f,r;
    void init()
    {
        f=r=0;
    }

    void push(int &t)
    {
        v[r++]=t;
    }

    bool empty()
    {
        return f>=r;
    }

    int front()
    {
        return v[f];
    }

    void pop()
    {
        ++f;
    }
    
}final_q,bgn_q;
int tot;
vector<int> vh[HASH_SIZE];

void insert(struct QUEUE &q,STATE &t)
{
    q.push(tot);
    vh[t.h].push_back(tot);
    data[tot++]=t;
}

void init()
{
    for(int i=0;i<HASH_SIZE;++i)
        vh[i].clear();
    tot=0;

    final_q.init();
    insert(final_q,final);

    bgn_q.init();
    insert(bgn_q,bgn);
}

int exist(STATE &t)
{
    for(int i=0,sz=vh[t.h].size();i<sz;++i)
    {
        int p=vh[t.h][i];
        if(t==data[p])
        {
            if(t.flag==data[p].flag)
                return -2;      //dump
            else
                return p;       //find!
        }
    }
    return -1;      //not found
}

void bgn_print(int p)
{
    if(data[p].fa==-1)
        return ;
    bgn_print(data[p].fa);
    printf("%d",data[p].pase);
}

void final_print(int p)
{
    if(data[p].fa==-1)
        return ;
    printf("%d",data[p].pase);
    final_print(data[p].fa);
}

bool process(QUEUE &q,STATE &tmp,int pase)
{
    tmp.h=tmp.hash();
    tmp.pase=pase;
    int find=exist(tmp);
    if(find==-1)
        insert(q,tmp);
    else if(find>=0)
    {
        data[tot]=tmp;
        if(tmp.flag)
        {
            bgn_print(tot);
            final_print(find);
        }
        else
        {
            bgn_print(find);
            final_print(tot);
        }
        putchar(10);
        return false;
    }
    return true;
}

bool bfs()
{
    init();

    STATE tmp;

    for(int dep=1;dep<=8;++dep)
    {
        for(; !bgn_q.empty() && data[ bgn_q.front() ].dep<dep; bgn_q.pop())
        {
            STATE &cur=data[ bgn_q.front() ];
            
            tmp.fa=bgn_q.front();
            tmp.dep=cur.dep+1;
            tmp.flag=cur.flag;

            tmp.s=cur.s.left_clock();
            if(!process(bgn_q,tmp,1))
                return true;

            tmp.s=cur.s.right_clock();
            if(!process(bgn_q,tmp,2))
                return true;

            tmp.s=cur.s.left_counter_clock();
            if(!process(bgn_q,tmp,3))
                return true;

            tmp.s=cur.s.right_counter_clock();
            if(!process(bgn_q,tmp,4))
                return true;
        }

        for(; !final_q.empty() && data[ final_q.front() ].dep<dep; final_q.pop())
        {
            STATE &cur=data[ final_q.front() ];

            tmp.fa=final_q.front();
            tmp.dep=cur.dep+1;
            tmp.flag=cur.flag;

            tmp.s=cur.s.left_clock();
            if(!process(final_q,tmp,3))
                return true;

            tmp.s=cur.s.right_clock();
            if(!process(final_q,tmp,4))
                return true;
            
            tmp.s=cur.s.left_counter_clock();
            if(!process(final_q,tmp,1))
                return true;

            tmp.s=cur.s.right_counter_clock();
            if(!process(final_q,tmp,2))
                return true;
        }
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    memcpy(sub.v,final_state,sizeof(final_state));
    
    final.s=sub;
    final.h=final.hash();
    final.dep=0;
    final.flag=false;
    final.fa=-1;

    int dataset;
    scanf("%d",&dataset);
    while(dataset--)
    {
        bgn.read();
        bgn.h=bgn.hash();
        bgn.dep=0;
        bgn.flag=true;
        bgn.fa=-1;
        
        if(bgn==final)
            puts("PUZZLE ALREADY SOLVED");
        else if(!bfs())
            puts("NO SOLUTION WAS FOUND IN 16 STEPS");
    }

    return 0;
}

