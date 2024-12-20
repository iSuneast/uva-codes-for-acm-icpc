/*
11718 - Fantasy of a Summation

math...
我就觉得说我的公式推得没错...
f(k)=n^(k-1)+(n-1)*f(k-1)
则 f(k)=k*n^(k-1)
最终ans=sum*f(k)%MOD
*/

#include<iostream>
using namespace std;

long long pow_mod(long long n,long long k,long long mod)
{
	if(k==0)
		return 1;
	long long key=pow_mod(n,k/2,mod);
	key=key*key%mod;
	if(k&1)
		key=key*n%mod;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		long long n,k,m,var,s=0;
		scanf("%lld%lld%lld",&n,&k,&m);
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&var);
			s+=var;
		}
		s%=m;
		printf("Case %d: %lld\n",cas,s*k%m*pow_mod(n,k-1,m)%m);
	}

	return 0;
}
