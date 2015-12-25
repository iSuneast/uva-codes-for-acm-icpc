/*
 * 11170 - Cos(NA)
 * 
 * math...
 * dp...
 * 
 * we can generate the format using below method:
 * 
 * cos(a+b) = cos(a)*cos(b) - sin(a)*sin(b)
 * cos(a-b) = cos(a)*cos(b) + sin(a)*sin(b)
 * cos(a+b) + cos(a-b) = 2cos(a)*cos(b)
 * if a = N-1, b = 1
 * cos(N) + cos(N-2) = 2cos(N-1)*cos(1)
 * so, cos(N) = 2cos(N-1)*cos(1) - cos(N-2)
 */

#include<cstdio>
#include<cstring>
#define MAXN 50

struct COS_NA
{
	long long exp[MAXN];
}key[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    memset(key,0,sizeof(key));
    key[1].exp[1]=1;
    key[2].exp[0]=-1;	key[2].exp[2]=2;
    for(int i=3;i<MAXN;++i)
    {
    	for(int j=1;j<MAXN;++j)
    	{
    		key[i].exp[j]=2*key[i-1].exp[j-1]-key[i-2].exp[j];
    	}
    	key[i].exp[0]=-key[i-2].exp[0];
    }
    
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
    	bool first=true;
    	for(int i=MAXN-1;i>=0;--i)
    	{
    		if(!key[n].exp[i])
    			continue;
    		
    		if(!i)
    		{
    			if(key[n].exp[i]>0)
    				putchar('+');
    			printf("%lld",key[n].exp[i]);
    		}
    		else
    		{
    			if(!first)
    			{
        			if(key[n].exp[i]>0)
        			{
        				putchar('+');
        				if(key[n].exp[i]>1)
        	    			printf("%lld",key[n].exp[i]);
        			}
        			else
        			{
        				if(key[n].exp[i]<-1)
        	    			printf("%lld",key[n].exp[i]);
        				else
            				putchar('-');        					
        			}
    			}
    			else if(key[n].exp[i]>1)
	    			printf("%lld",key[n].exp[i]);
    		}
    		
    		if(i==1)
    			printf("Cos(A)");
    		else if(i>0)
    			printf("Cos^%d(A)",i);
    		
    		first=false;
    	}
    	putchar(10);
    }

    return 0;
}

