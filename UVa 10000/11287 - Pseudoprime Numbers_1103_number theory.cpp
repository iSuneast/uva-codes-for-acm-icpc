/*
11287 - Pseudoprime Numbers

number theory...
sieve the prime to sqrt(1e9)
use PowMod to check a^p==a(mod p)
if is ok then check whether p is not a prime
if both is ok then output "yes"
else output "no"
*/

#include<iostream>
#include<cmath>
#define MAXN 31625
using namespace std;
int prime[MAXN],tot;

int PowMod(int var,int p,int mod)
{
	long long key=1,a=var;
	for(;p;p>>=1)
	{
		if(p&1)
			key=(key*a)%mod;
		a=(a*a)%mod;
	}
	return key;
}

void init()
{
	tot=0;
	memset(prime,0,sizeof(prime));
	prime[tot++]=2;

	for(int i=3;i<MAXN;i+=2)
	{
		if(prime[i])
			continue;
		prime[tot++]=i;
		for(int j=i+i;j<MAXN;j+=i)
			prime[j]=-1;
	}
}

bool isprime(int var)
{
	int end=sqrt(static_cast<double>(var));
	for(int i=0;i<tot && prime[i]<=end;++i)
		if(var%prime[i]==0)
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int p,a;
	init();
	while(scanf("%d%d",&p,&a)!=EOF && (p||a))
	{
		puts(PowMod(a,p,p)==a%p && !isprime(p)?
			"yes":"no");
	}

	return 0;
}
