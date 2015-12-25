/*
 * 11402 - Ahoy, Pirates!
 *
 * SegTree...
 * no trick...
 *
 * a Segment Tree with Lazy Slack flag...
 */

#include<cstdio>
#include<cstring>
#define LS(p) (p<<1)
#define RS(p) ((p<<1)+1)
#define MID(a,b) (((a)+(b))>>1)
#define SZ (1<<21)
#define Barbary 0
#define Buccaneer 1
#define Rev 2
using namespace std;

char final[SZ],s[SZ];
struct SegTree
{
    struct TreeNode
    {
        int s,e,mu,cnt;
    }st[SZ];

    void build(int p,int s,int e)
    {
        st[p].s=s;  st[p].e=e;  st[p].mu=-1;
        if(s+1==e)
        {
            st[p].cnt=final[s]-'0';
            return ;
        }
        build(LS(p),s,MID(s,e));
        build(RS(p),MID(s,e),e);
        st[p].cnt = st[ LS(p) ].cnt + st[ RS(p) ].cnt;
    }

    void process(int p)
    {
        if(st[p].mu==-1)
            return ;
        if(st[p].mu!=Rev)
        {
            st[p].cnt=st[p].mu*(st[p].e-st[p].s);
            if(st[p].s+1!=st[p].e)
                st[LS(p)].mu=st[RS(p)].mu=st[p].mu;
        }
        else
        {
            st[p].cnt=st[p].e-st[p].s-st[p].cnt;
            if(st[p].s+1!=st[p].e)
            {
                if(st[LS(p)].mu!=2)
                    st[LS(p)].mu=1-st[LS(p)].mu;
                else if(st[LS(p)].mu==-1)
                    st[LS(p)].mu=2;
                else
                    st[LS(p)].mu=-1;

                if(st[RS(p)].mu!=2)
                    st[RS(p)].mu=1-st[RS(p)].mu;
                else if(st[RS(p)].mu==-1)
                    st[RS(p)].mu=2;
                else
                    st[RS(p)].mu=-1;
            }
        }

        st[p].mu=-1;
    }

    void modify(int p,int &s,int &e,int dif)
    {
        if(st[p].mu!=-1)
            process(p);
        if(s<=st[p].s && st[p].e<=e)
        {
            st[p].mu=dif;
            return process(p);
        }

        if(s<MID(st[p].s,st[p].e))
            modify(LS(p),s,e,dif);
        if(MID(st[p].s,st[p].e)<e)
            modify(RS(p),s,e,dif);
        process(LS(p)); process(RS(p));
        st[p].cnt = st[ LS(p) ].cnt + st[ RS(p) ].cnt;
    }

    int query(int p,int &s,int &e)
    {
        if(st[p].mu!=-1)
            process(p);

        if(s<=st[p].s && st[p].e<=e)
            return st[p].cnt;

        int key=0;
        if(s<MID(st[p].s,st[p].e))
            key+=query(LS(p),s,e);
        if(MID(st[p].s,st[p].e)<e)
            key+=query(RS(p),s,e);

        process(LS(p)); process(RS(p));
        st[p].cnt = st[ LS(p) ].cnt + st[ RS(p) ].cnt;
        return key;
    }
}key;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
        int m,t,p=0,l,q,a,b;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%s",&t,s);
            l=strlen(s);
            while(t--)
            {
                strcpy(final+p,s);
                p+=l;
            }
        }
        key.build(1,0,p);

        scanf("%d",&q);
        printf("Case %d:\n",cas);
        for(int i=1,j=0;i<=q;++i)
        {
            scanf("%s%d%d",s,&a,&b);    ++b;
            if(s[0]=='F')
                key.modify(1,a,b,Buccaneer);
            else if(s[0]=='E')
                key.modify(1,a,b,Barbary);
            else if(s[0]=='I')
                key.modify(1,a,b,Rev);
            else
                printf("Q%d: %d\n",++j,key.query(1,a,b));

        }
    }

    return 0;
}

