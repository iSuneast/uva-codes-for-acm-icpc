/*
10533 - Digit Primes

number theory...
先打表在直接输出...
不然按照题目的规模...TLE的可能很大...

打表有几点需要注意...
对于区间[s->e],
prime[s]记录的是s之前(不含s)的符合条件的数字个数...
输出时侯,相应的也要增大上界..
即正确的节的个数为prime[e+1]-prime[s]...
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
