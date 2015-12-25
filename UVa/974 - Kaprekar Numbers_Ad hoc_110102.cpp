/*
 * 974 - Kaprekar Numbers
 * 
 * Ad hoc...
 * a simple problem...
 * just pre-calculate the kaprekar numbers and then print out..
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 40001
using namespace std;

int inf,sup,kaprekar[MAXN],sz;
char buf[30],c;

bool iskaprekar(int v)
{
	int t=v*v;
	sprintf(buf,"%d",t);
	int l=strlen(buf),a,b;
	for(int p=1;p<l;++p)
	{
		c=buf[p];	buf[p]=0;
		sscanf(buf,"%d",&a);
		buf[p]=c;
		sscanf(buf+p,"%d",&b);
		if(a+b==v && a && b)
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    sz=0;
    for(int i=2;i<MAXN;++i)
    {
    	if(iskaprekar(i))
    		kaprekar[sz++]=i;
    }
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	printf("case #%d\n",cas);
    	scanf("%d%d",&inf,&sup);
    	int l=lower_bound(kaprekar,kaprekar+sz,inf)-kaprekar;
    	int r=upper_bound(kaprekar,kaprekar+sz,sup)-kaprekar;
    	
    	if(l>=r)
    		puts("no kaprekar numbers");
    	else for(int i=l;i<r;++i)
    		printf("%d\n",kaprekar[i]);
    	
    	if(cas!=dataset)
    		putchar(10);
    }

    return 0;
}

