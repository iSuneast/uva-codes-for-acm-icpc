/*
471 - Magic Numbers

brute force...
直接暴力枚举...
*/

#include<iostream>
#define MAXN 9876543210
using namespace std;

bool chk(long long var)
{
	char hash[10];
	memset(hash,0,sizeof(hash));
	while(var)
	{
		if(hash[var%10])
			return false;
		hash[var%10]=true;
		var/=10;
	}
	return true;
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
		for(long long b=1;;++b)
		{
			long long a=b*n;
			if(a>MAXN)
				break;
			else if(chk(b) && chk(a))
				printf("%lld / %lld = %lld\n",a,b,n);
		}
		if(cas!=dataset)
			putchar('\n');
	}

	return 0;
}
