/*
 * 948 - Fibonaccimal Base
 * 
 * Ad hoc...
 * fib...
 * a simple problem with no trick...
 * just simulation...
 */

#include<cstdio>
#define MAXN 38

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int fib[MAXN];
    fib[0]=1;	fib[1]=2;
    for(int i=2;i<MAXN;++i)
    {
    	fib[i]=fib[i-1]+fib[i-2];
    }
    
    int dataset,n;
    scanf("%d",&dataset);
    while(dataset--)
    {
    	scanf("%d",&n);
    	printf("%d = ",n);
    	for(int p=MAXN-1;p>=0;--p)
    	{
    		if(n<fib[p])
    			continue;
    		for(int j=p;j>=0;--j)
    		{
    			if(n>=fib[j])
    			{
    				n-=fib[j];
    				putchar('1');
    			}
    			else
    				putchar('0');
    		}
    		printf(" (fib)\n");
    	}
    }

    return 0;
}

