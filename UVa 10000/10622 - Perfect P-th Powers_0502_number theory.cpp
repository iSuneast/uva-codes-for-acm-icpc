/*
10622 - Perfect P-th Powers

number theory...
��...
��Ȼ������...
��-2^32��߳�������...
ֱ�Ӷ����long long�Ͳ����������...

��Ŀ���ƺܸ�����ʵֻҪ��һ�������ۻ������������Ǻ����׵�..
����������...
��sqrt(2^31)Ϊֹ��OK��...
Ȼ����Ƕ�n�ֽ�������...
ȡ�����ӵ�gcd����...
����Ҫע��һ��nΪ���������...
ֻ����һ��flag���...
���������м���...
������ans����Ϊ����...
��ʵֻ��һֱ/2ֱ��ansΪ����...
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
