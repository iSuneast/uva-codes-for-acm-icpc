/*
 * 944 - Happy Numbers
 * 
 * Ad hoc...
 * almost the same as The 3n+1 problems..
 */

#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;

int step[MAXN],q[MAXN],key[MAXN];

void process(int n)
{
	int sz=0,s;
	while(!step[n])
	{
		q[sz++]=n;
		step[n]=-1;
		
		s=0;
		while(n)
		{
			s+=(n%10)*(n%10);
			n/=10;
		}
		n=s;
	}
		
	if(step[n]>0)
	{
		q[sz]=n;
		for(int k=sz-1;k>=0;--k)
			step[ q[k] ]=step[ q[k+1] ]+1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    step[1]=1;
    key[0]=1;
    int tot=1;
    for(int i=2;i<MAXN;++i)
    {
    	if(!step[i])
        	process(i);
    	if(step[i]>0)
    		key[tot++]=i;
    }
    
    int l,h;
    bool first=true;
    while(scanf("%d%d",&l,&h)!=EOF)
    {
    	if(!first)
    		putchar(10);
    	first=false;
    	
    	l=lower_bound(key,key+tot,l)-key;
    	h=upper_bound(key,key+tot,h)-key;
    	for(;l<h;++l)
    		printf("%d %d\n",key[l], step[ key[l] ]);
    }

    return 0;
}

