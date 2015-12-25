/*
 * 10484 - Divisibility of Factors
 * 
 * number theory...
 * prime...
 * factorization the N! into prime base
 * 		N! = p1^n1 * p2^n2 *... * pi*ni
 * and so do abs(d) = p1^n1' * p2^n2' *... * pi*ni'
 * if for some i ni'>ni then the answer is 0
 * else the answer is PI( ni+1 ) 
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 101
using namespace std;

int prime[MAXN],tot,f[MAXN];

void init()
{
	for(int i=2;i<MAXN;++i)
	{
		bool fade=false;
		for(int j=2;j<i;++j)
		{
			if(i%j==0)
			{
				fade=true;
				break;
			}
		}
		if(!fade)
			prime[tot++]=i;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    init();
    for(int n,d; scanf("%d%d",&n,&d)!=EOF && (n||d); )
    {
    	memset(f,0,sizeof(f));
    	int var=abs(d);
    	for(int i=2;i<=n;++i)
    	{
    		int t=i;
    		for(int j=0;j<tot && t>1;++j)
    		{
    			while(t%prime[j]==0)
    			{
    				t/=prime[j];
    				++f[j];
    			}
    		}
    	}
    	
    	long long key=1;
    	bool fade=false;
    	for(int j=0;j<tot && !fade;++j)
    	{
    		while(var%prime[j]==0)
    		{
    			var/=prime[j];
    			--f[j];
    			if(f[j]<0)
				{
    				fade=true;
    				break;
				}
    		}
    	}
    	
    	if(var!=1)
    		fade=true;
    	
    	if(!fade)
    	{
    		for(int j=0;j<tot;++j)
    		{
    			if(f[j])
    				key*=(f[j]+1);
    		}
    	}
    	else
    		key=0;
		printf("%lld\n",key);
    }

    return 0;
}

