/*
 * 10419 - Sum-up the Primes
 * 
 * search...
 * generate the prime table., sort these numbers lexicographically
 * then just complete search these numbers is OK
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 300
using namespace std;

int prime[MAXN],tot, key[14], t;
bool got;

int cmp(const int &a,const int &b)
{
	char sa[5], sb[5];
	sprintf(sa,"%d",a);
	sprintf(sb,"%d",b);
	return strcmp(sa,sb)<0;
}

void init()
{
	prime[tot++]=2;
	for(int i=3;i<MAXN;i+=2)
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
	
	sort(prime,prime+tot,cmp);
}

void dfs(int n,int p,int dep)
{
	if(got)
		return ;
	
	if(dep==t)
	{
		if(!n)
		{
			for(int i=0;i+1<t;++i)
				printf("%d+",key[i]);
			printf("%d\n",key[t-1]);
			got=true;
		}
		return ;
	}
	
	for(int i=p;i<tot;++i)
	{
		if(n<prime[i])
			continue;
		
		key[dep]=prime[i];
		if(prime[i]==2 || (dep && key[dep]==key[dep-1]))
			dfs(n-prime[i], i+1, dep+1);
		else
			dfs(n-prime[i], i, dep+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    init();
    for(int cas=1, n; scanf("%d%d",&n,&t)!=EOF && (n||t); ++cas)
    {
    	printf("CASE %d:\n",cas);
    	got=false;
    	dfs(n,0,0);
    	if(!got)
    		puts("No Solution.");
    }

    return 0;
}

