/*
10490 - Mr. Azad and his Son!!!!!

numbe theory...
完全数判定...
若k为素数,且n=2^(k-1)*(2^k-1)为素数
则n为完全数...
*/

#include<iostream>
#include<cmath>
using namespace std;

bool isprime(long long n)
{
	long long bound=sqrt(n+0.0);
	for(int i=2;i<=bound;++i)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long n;
	while(scanf("%lld",&n)!=EOF && n)
	{
		long long p=(1<<n)-1;
		if(isprime(n))
		{
			p*=1<<(n-1);
			if(isprime((1<<n)-1))
				printf("Perfect: %lld!\n",p);
			else
				puts("Given number is prime. But, NO perfect number is available.");
		}
		else
			puts("Given number is NOT prime! NO perfect number is available.");
	}

	return 0;
}
