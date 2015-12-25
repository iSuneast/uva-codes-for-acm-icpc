/*
 * 10742 - The New Rule in Euphomia
 * 
 * number theory...
 * sieve the prime till 10^6
 * we find that the problem is just about to find how many prime pairs (p1, p2)
 * N < p1 + p2, p1!=p2
 * so just enum p1, and b-search in the prime array to calculate how many p2 is ok
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 1000001
#define BOUND 1001
#define SZ 78500
using namespace std;

bool fade[MAXN];
int prime[SZ],tot;

void init()
{
	memset(fade,0,sizeof(fade));
	for(int i=3;i<BOUND;i+=2)
	{
		if(fade[i])
			continue;
		for(int j=i+i;j<MAXN;j+=i)
			fade[j]=true;
	}
	
	tot=0;
	prime[tot++]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		if(!fade[i])
			prime[tot++]=i;
	}
}

long long dp(int n)
{
	long long key=0;
	for(int i=1; i<tot && n>=prime[i]+2; ++i)
	{
		int p=lower_bound(prime, prime+tot, n-prime[i])-prime;
		if(prime[p]!=n-prime[i])
			--p;
		key+=min(p+1, i);
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    for(int cas=1,n; scanf("%d",&n)!=EOF && n; ++cas)
    {
    	printf("Case %d: %lld\n",cas,dp(n));
    }    
    
    return 0;
}

