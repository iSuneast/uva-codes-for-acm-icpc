/*
 * 11148 - Moliu Fractions
 * 
 * Ad hoc...
 * a simple problem with a lot of tricks...
 * such as "Hello314, are you ready 4the world final in the year2011"
 * 
 * so remove the useless chars and then product all remain numbers...
 * 
 * happy coding ...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 10003
using namespace std;

char s[MAXN];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d%*c",&dataset);
    while(dataset--)
    {
    	gets(s);
    	for(int i=0;s[i];++i)
    	{
    		if(!isdigit(s[i]) && s[i]!='/' && s[i]!='-')
    			s[i]=' ';
    	}
    	int a=1,b=1,t1,t2,t3;
    	for(char *token=strtok(s," "); token; token=strtok(NULL," "))
    	{
    		if(!isdigit(token[0]))
    			continue;
    		bool bk=false;
    		for(int i=0;token[i] && !bk;++i)
    		{
    			if(token[i]=='-')
    			{
    				sscanf(token,"%d%*c%d%*c%d",&t3,&t1,&t2);
    				t1+=t3*t2;
    				bk=true;
    			}
    		}
    		for(int i=0;token[i] && !bk;++i)
    		{
    			if(token[i]=='/')
    			{
    				sscanf(token,"%d%*c%d",&t1,&t2);
    				bk=true;
    			}
    		}
    		if(!bk)
    		{
    			t2=1;
				sscanf(token,"%d",&t1);
    		}
    		
    		a*=t1;
    		b*=t2;
    		
        	t3=gcd(a,b);
        	a/=t3;
        	b/=t3;
    	}

    	t3=a/b;
    	a%=b;
    	if(!a)
    		printf("%d\n",t3);
    	else if(t3)
    		printf("%d-%d/%d\n",t3,a,b);
    	else
    		printf("%d/%d\n",a,b);
    }

    return 0;
}

