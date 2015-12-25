/*
568 - Just the Facts
*/

#include<iostream>

using namespace std;

long n,pri[10008],i;

int calc()
{
	for(;i<=n;i++)
	{
		pri[i]=pri[i-1]*i;
		while(!(pri[i]%10))
			pri[i]/=10;
		pri[i]%=100000;
	}
	return pri[n]%10;
}

int main()
{
	pri[1]=1,i=2;
	while(cin>>n)
		printf("%5d -> %d\n",n,calc());

return 0;
}
