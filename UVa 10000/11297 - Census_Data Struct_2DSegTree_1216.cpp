/*
 * 11297 - Census
 *
 * Data Struct...
 * 2D-SegTree
 *
 * a simple "<=" bug, spend me a lot of time to figure it out...
 */

#include<cstdio>
#include<iostream>
#define MAXN 503
#define SZ 1024
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;

int var[MAXN][MAXN],n,m;
char s[3];

void chk(pii &cur,pii t)
{
    cur.first=max(cur.first,t.first);
    cur.second=min(cur.second,t.second);
}

struct SegTree2D
{
    struct SegTree
    {
        int s,e,Max,Min;
        SegTree *l,*r;
        struct TreeNode
        {
            int s,e,Max,Min;
        }st[SZ];
        
        void build(int p,int x,int y)
        {
            st[p].s=x;  st[p].e=y;
            if(x+1==y)
            {
                if(!l)
                    st[p].Min=st[p].Max=var[x][s];
                else
                {
                    st[p].Max=max(l->st[p].Max,r->st[p].Max);
                    st[p].Min=min(l->st[p].Min,r->st[p].Min);
                }
                return ;
            }
            
            int ls=p<<1,rs=(p<<1)+1;
            build(ls,x,(x+y)>>1);
            build(rs,(x+y)>>1,y);
            st[p].Max=max(st[ls].Max,st[rs].Max);
            st[p].Min=min(st[ls].Min,st[rs].Min);
        }

        pii query(int p,int sy,int ey)
        {
            if(sy<=st[p].s && st[p].e<=ey)
                return make_pair(st[p].Max,st[p].Min);

            pii ans=make_pair(-INF,INF);
            int my=(st[p].s+st[p].e)>>1;
            if(sy<my)
                chk(ans,query(p<<1,sy,ey));
            if(my<ey)
                chk(ans,query((p<<1)+1,sy,ey));

            return ans;
        }

        void modify(int p,int y,int v)
        {
            if(st[p].s+1==st[p].e)
            {
                if(!l)
                    st[p].Max=st[p].Min=v;
                else
                {
                    st[p].Max=max(l->st[p].Max,r->st[p].Max);
                    st[p].Min=min(l->st[p].Min,r->st[p].Min);
                }
                return ;
            }

            int my=(st[p].s+st[p].e)>>1;
            int ls=p<<1,rs=(p<<1)+1;
            if(y<my)
                modify(ls,y,v);
            else
                modify(rs,y,v);
            
            st[p].Max=max(st[ls].Max,st[rs].Max);
            st[p].Min=min(st[ls].Min,st[rs].Min);
        }
    }CoX[SZ];

    void build(int p,int x,int y)
    {
        CoX[p].s=x; CoX[p].e=y;
        
        if(x+1==y)
        {
            CoX[p].l=CoX[p].r=NULL;
            CoX[p].build(1,1,n+1);
            return ;
        }
        
        int ls=(p<<1),rs=(p<<1)+1;
        build(ls,x,(x+y)>>1);
        build(rs,(x+y)>>1,y);
        CoX[p].l=&CoX[ls];  CoX[p].r=&CoX[rs];
        CoX[p].build(1,1,n+1);
    }

    pii query(int p,int &sx,int &sy,int &ex,int &ey)
    {
        if(sx<=CoX[p].s && CoX[p].e<=ex)
            return CoX[p].query(1,sy,ey);
        
        pii ans=make_pair(-INF,INF);
        int mx=(CoX[p].s+CoX[p].e)>>1;
        if(sx<mx)
            chk(ans,query(p<<1,sx,sy,ex,ey));
        if(mx<ex)
            chk(ans,query((p<<1)+1,sx,sy,ex,ey));
        
        return ans;
    }

    void modify(int p,int &x,int &y,int &v)
    {
        if(CoX[p].s+1==CoX[p].e)
            return CoX[p].modify(1,y,v);

        int mx=(CoX[p].s+CoX[p].e)>>1;
        modify((p<<1)+(x>=mx),x,y,v);
        CoX[p].modify(1,y,v);
    }
}key;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            scanf("%d",&var[i][j]);
    }
    key.build(1,1,m+1);

    int sx,sy,ex,ey,v,q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",s);
        if(s[0]=='q')
        {
            scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
            if(sx>ex)
                swap(sx,ex);
            if(sy>ey)
                swap(sy,ey);

            ++ex;   ++ey;
            pii ans=key.query(1,sx,sy,ex,ey);
            printf("%d %d\n",ans.first,ans.second);
        }
        else
        {
            scanf("%d%d%d",&sy,&sx,&v);
            key.modify(1,sx,sy,v);
        }
    }

    return 0;
}

