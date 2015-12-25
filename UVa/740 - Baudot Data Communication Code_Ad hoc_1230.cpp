/*
 * 740 - Baudot Data Communication Code
 *
 * Ad hoc...
 * a simple problem...
 * no trick...
 */

#include<cstdio>
#define MAXN 100
using namespace std;

char h[2][MAXN],buf[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    gets(h[0]);
    gets(h[1]);
    
    while(gets(buf))
    {
        int pase=0;
        for(int i=0;buf[i];i+=5)
        {
            int t=0;
            for(int j=i;j<i+5;++j)
            {
                t=t*2+buf[j]-'0';
            }
            if(t==31)
                pase=1;
            else if(t==27)
                pase=0;
            else
                putchar(h[pase][t]);
        }
        putchar(10);
    }

    return 0;
}

