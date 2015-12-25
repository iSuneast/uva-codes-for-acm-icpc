/*
 * 737 - Gleaming the Cubes
 *
 * Ad hoc...
 * the problem is about to find the volumn by all the cubes...
 * it's quite simple...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct CUBE
{
    int x,y,z,d,tx,ty,tz;
    void read()
    {
        scanf("%d%d%d%d",&x,&y,&z,&d);
        tx=x+d; ty=y+d; tz=z+d;
    }
}key,cur;

bool insert(int &ps,int &pe,int ts,int te)
{
    if(pe<=ts || te<=ps)
        return false;
    ps=max(ps,ts);
    pe=min(pe,te);
    return true;
}

bool fade;
void process(CUBE &a,CUBE &b)
{
    if(!insert(a.x,a.tx,b.x,b.tx))
        fade=true;
    if(!insert(a.y,a.ty,b.y,b.ty))
        fade=true;
    if(!insert(a.z,a.tz,b.z,b.tz))
        fade=true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        key.read();
        fade=false;
        while(--n)
        {
            cur.read();
            if(!fade)
                process(key,cur);
        }

        int ans=(key.tx-key.x)*(key.ty-key.y)*(key.tz-key.z);
        if(fade)
            ans=0;
        printf("%d\n",ans);
    }

    return 0;
}

