/*
10533 - Digit Primes

number theory...
�ȴ����ֱ�����...
��Ȼ������Ŀ�Ĺ�ģ...TLE�Ŀ��ܴܺ�...

����м�����Ҫע��...
��������[s->e],
prime[s]��¼����s֮ǰ(����s)�ķ������������ָ���...
���ʱ��,��Ӧ��ҲҪ�����Ͻ�..
����ȷ�Ľڵĸ���Ϊprime[e+1]-prime[s]...
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

int prime[MAXN];

int chk(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	if(prime[s]>=0)
		return 1;
	return 0;
}

void init()
{
	int i,j,more;
	prime[0]=prime[1]=-1;
	for(i=2;i<MAXN;++i)
		if(!prime[i])
		{
			prime[i]=chk(i);
			for(j=i+i;j<MAXN;j+=i)
				prime[j]=-1;
		}
	for(i=j=0;i<MAXN;++i)
	{
		more=0;
		if(prime[i]==1)
			more=1;
		prime[i]=j;
		j+=more;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	int dataset,s,e;
	cin>>dataset;
	while(dataset--)
	{
		cin>>s>>e;
		cout<<prime[e+1]-prime[s]<<endl;
	}

	return 0;
}
