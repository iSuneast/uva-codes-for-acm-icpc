/*
11614 - Etruscan Warriors Never Play Chess

math..
求最大的k满足(k-1)*k/2<=n
解方程即可
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		long long n;
		scanf("%lld",&n);
		long long k=(-1+sqrt(1+8.0*n))/2.0;
		if(k*(k-1)/2>n)
			--k;
		printf("%lld\n",k);
	}

	return 0;
}
