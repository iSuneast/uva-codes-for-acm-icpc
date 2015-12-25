/*
11254 - Consecutive Integers

number theory...
	(a+b)*(b-a+1)/2=n
->  (a+b)*(b-a+1)=2n
so, for i=sqrt(2n)->1
if we can find i, which 2n%i==0
then set j=2n/i
we will got following format
	a+b=j
	b-a+1=i	(because i<=j && b-a+1<a+b)
so b=(i+j-1)/2, a=j-b
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	long long n,var,a,b,i,j;
	while(scanf("%lld",&n)!=EOF && n!=-1)
	{
		var=n<<1;
		for(i=sqrt(static_cast<double>(var));i;--i)
		{
			if(var%i)
				continue;
			j=var/i;
			b=(i+j-1)/2;
			a=j-b;

			if((a+b)*(b-a+1)==var)
			{
				printf("%lld = %lld + ... + %lld\n",n,a,b);
				break;
			}
		}

		if(!i)
			printf("%lld = %lld + ... + %lld\n",n,n,n);
	}

	return 0;
}
