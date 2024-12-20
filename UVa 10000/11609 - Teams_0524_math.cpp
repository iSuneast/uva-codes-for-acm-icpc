/*
11609 - Teams

math...
师大校赛的类似的题...
自然数n有2^(n-1)种有序的分解方式
则解为n*2^(n-1)
*/

#include<iostream>
#define MOD 1000000007
using namespace std;

long long pow_mod(int a,int b)
{
	if(!b)
		return 1;
	long long key=pow_mod(a,b/2);
	key=key*key%MOD;
	if(b&1)
		key=key*a%MOD;
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
		long long n;
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",cas,pow_mod(2,n-1)*n%MOD);
	}

	return 0;
}
