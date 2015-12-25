/*
 * 10236 - The Fibonacci Primes
 *
 * number theory...
 * 关于理论部分,可以参考具体数学里面的fib数列的知识
 * fib   0 1 1 2 3 5 8 13 21 34 55 89
 * 自然数 0 1 2 3 4 5 6  7  8  9 10 11
 * fib素数为	2	3  	5	13	89
 * 自然素数	3	4(*)	5	7	11
 *
 * knuth关于该结论有个证明公式,用到了euler定理
 * GCD( Fib(n), Fib(m)) = Fib( GCD(n,m) )
 * 也就是说,如果Fib(n),Fib(m)互素,则Fib( GCD(n,m) ) = 1
 * 由上表可知,GCD(n,m)为 1或者2
 * 即,GCD(n,m) = 1/2
 * 则,满足条件的自然数里面除了原来的素数外,多了自然数4
 *
 * 接下去就简单了,第n个fib素数,就是第n个自然素数对应的fib素数,
 * 简而言之,答案就是Fib[ Prime[n] ]
 *
 * 至于怎么算出解,有各种方法.
 *
 * p.s我是水过去的 = =,所以我就说不怎么处理了 ....
 *
 * Happy coding~
 */

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#define MAXN 250000
#define SZ 22050
#define BOUND 501
#define MOD (1e30)
using namespace std;
typedef long double LD;

bool fade[MAXN];
int prime[SZ], tot;
LD ans[SZ];

void sieve()
{
	tot=0;
	prime[++tot]=2;
	for(int i=3;i<BOUND;i+=2)
	{
		if(!fade[i])
			for(int j=i+i;j<MAXN;j+=i)
				fade[j]=true;
	}

	for(int i=3;i<MAXN;i+=2)
	{
		if(!fade[i])
			prime[++tot]=i;
	}

	prime[1]=3;
	prime[2]=4;
}

LD format(LD t)
{
	while(t>=1e9)
		t/=10;
	return floor(t);
}

void make()
{
	LD a=0,b=1,c;
	for(int dep=2,p=1; p<SZ && dep<MAXN; ++dep)
	{
		while(a>=MOD)
		{
			a/=10;
			b/=10;
		}

		c=a+b;

		if(prime[p]==dep)
			ans[p++]=format(c);

		a=b;
		b=c;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	sieve();
	make();
	for(int n; scanf("%d",&n)!=EOF; )
	{
		cout<<setprecision(9)<<ans[n]<<endl;
	}

	return 0;
}
