/*
 * 637 - Booklet Printing
 *
 * Ad hoc...
 * quite a simple...
 * just simulate as the problem description...
 */

#include<cstdio>

int n;

void output(int p)
{
    if(p>n)
        printf(" Blank");
    else
        printf(" %d",p);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d",&n)!=EOF && n)
    {
        printf("Printing order for %d pages:\n",n);
        for(int b=1,e=(n+3)/4*4,s=1;b<e;++s,++b,--e)
        {
            printf("Sheet %d, front:",s);
            output(e--);
            putchar(',');
            output(b++);
            putchar(10);
            
            if(e>n && b>n)
                continue;

            printf("Sheet %d, back :",s);
            output(b);
            putchar(',');
            output(e);
            putchar(10);
        }
    }

    return 0;
}

