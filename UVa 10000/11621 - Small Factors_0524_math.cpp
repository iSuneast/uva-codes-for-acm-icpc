/*
11621 - Small Factors

math...
求最小的2^i*3^j>=m
直接暴力枚举i,j即可...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long m;
	while(scanf("%lld",&m)!=EOF && m)
	{
		long long n,t,key=((long long)1)<<62;
		for(long long i=0;i<=32;++i)
			for(long long j=0;j<=20;++j)
			{
				t=i;
				n=1;
				while(t--)
					n*=2;
				t=j;
				while(t--)
					n*=3;
				if(n>(((long long)1)<<35))
					break;
				if(n>=m)
					key=min(n,key);
			}
		printf("%lld\n",key);
	}

	return 0;
}
