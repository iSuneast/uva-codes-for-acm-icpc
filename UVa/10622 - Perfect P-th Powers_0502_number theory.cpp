/*
10622 - Perfect P-th Powers

number theory...
晕...
竟然卡精度...
在-2^32这边出问题了...
直接定义成long long就不会有问题额...

题目看似很复杂其实只要有一定的数论基础做出来还是很容易的..
先塞出素数...
到sqrt(2^31)为止就OK了...
然后就是对n分解素因子...
取素因子的gcd即可...
此外要注意一下n为负数的情况...
只需用一个flag标记...
算出解后特判即可...
负数的ans必须为奇数...
其实只需一直/2直到ans为奇数...
*/

#include<iostream>
#define MAXN 46350
using namespace std;

long long prime[MAXN],cnt;

long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}

void init()
{
	prime[cnt++]=2;
	for(long long i=3;i<MAXN;i+=2)
		if(prime[i]==0)
		{
			prime[cnt++]=i;
			for(long long j=i+i;j<MAXN;j+=i)
				prime[j]=-1;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	long long n;
	while(cin>>n && n)
	{
		long long flag=1,key=0,t;
		if(n<0)
			flag=-1,n=-n;
		for(long long i=0;i<cnt && n!=1;++i)
			if(n%prime[i]==0)
			{
				t=0;
				while(n%prime[i]==0)
				{
					++t;
					n/=prime[i];
				}
				if(!key)
					key=t;
				else
					key=gcd(key,t);
			}
		if(n==1)
		{
			if(flag==-1)
				while(key%2==0)
					key=key>>1;
			cout<<key<<endl;
		}
		else
			puts("1");
	}

	return 0;
}
