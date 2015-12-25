/*
11424 - GCD - Extreme (I)

number theory...
euler...
欧拉函数的O(NlogN)筛法...
*/

#include<iostream>
#define MAXN 200001
using namespace std;

long long phi[MAXN],sum[MAXN];
int prime[MAXN],n;

bool isprime(int n)
{
	if(n&1)
		return prime[n]!=-1;
	else if(n==2)
		return true;
	return false;
}

void init()
{
	prime[0]=prime[1]=-1;
	for(int i=3;i<MAXN;i+=2)
		if(prime[i]==0)
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]=-1;

	for(int i=2;i<MAXN;++i)
	{
		phi[i]=i;
		sum[i]=0;
	}
	sum[0]=sum[1]=0;

	for(int i=2;i<MAXN;++i)
		if(isprime(i))
			for(int j=i;j<MAXN;j+=i)
				phi[j]=phi[j]*(i-1)/i;

	for(int k=1;k<MAXN;++k)
	{
		for(int n=2*k;n<MAXN;n+=k)
			sum[n]+=k*phi[n/k];
		sum[k]+=sum[k-1];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(scanf("%d",&n)!=EOF && n)
		printf("%I64d\n",sum[n]);

	return 0;
}
