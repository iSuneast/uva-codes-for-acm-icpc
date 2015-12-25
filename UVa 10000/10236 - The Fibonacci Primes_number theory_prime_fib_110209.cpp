/*
 * 10236 - The Fibonacci Primes
 *
 * number theory...
 * �������۲���,���Բο�������ѧ�����fib���е�֪ʶ
 * fib   0 1 1 2 3 5 8 13 21 34 55 89
 * ��Ȼ�� 0 1 2 3 4 5 6  7  8  9 10 11
 * fib����Ϊ	2	3  	5	13	89
 * ��Ȼ����	3	4(*)	5	7	11
 *
 * knuth���ڸý����и�֤����ʽ,�õ���euler����
 * GCD( Fib(n), Fib(m)) = Fib( GCD(n,m) )
 * Ҳ����˵,���Fib(n),Fib(m)����,��Fib( GCD(n,m) ) = 1
 * ���ϱ��֪,GCD(n,m)Ϊ 1����2
 * ��,GCD(n,m) = 1/2
 * ��,������������Ȼ���������ԭ����������,������Ȼ��4
 *
 * ����ȥ�ͼ���,��n��fib����,���ǵ�n����Ȼ������Ӧ��fib����,
 * �����֮,�𰸾���Fib[ Prime[n] ]
 *
 * ������ô�����,�и��ַ���.
 *
 * p.s����ˮ��ȥ�� = =,�����Ҿ�˵����ô������ ....
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
