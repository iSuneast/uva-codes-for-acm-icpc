/*
967 - Circular

number theory...
prefix sum...
树状数组+素数筛法的应用...

主意一下特殊的输出格式要求
*/

#include<iostream>
#define MAXN 1000000
#define lowbit(n) (n&(-n))
using namespace std;

bool prime[MAXN];
int bit[MAXN],power[]={1,10,100,1000,10000,100000};

void modify(int n)
{
	while(n<MAXN)
	{
		++bit[n];
		n+=lowbit(n);
	}
}

void insert(int n)
{
	int t=n,l=0,len;
	while(t)
	{
		++l;
		t/=10;
	}
	t=n;	len=l;
	while(l--)
	{
		t=t/10+t%10*power[len-1];
		if(!prime[t])
			return ;
	}
	modify(n);
}

void sieve()
{
	memset(prime,true,sizeof(prime));
	memset(bit,0,sizeof(bit));

	for(int i=2;i<MAXN;++i)
		if(prime[i])
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]=false;
	for(int i=2;i<MAXN;++i)
		if(prime[i])
			insert(i);
}

int sum(int n)
{
	int key=0;
	while(n)
	{
		key+=bit[n];
		n-=lowbit(n);
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	sieve();
	int s,e;
	while(scanf("%d%d",&s,&e)!=EOF && s!=-1)
	{
		int key=sum(e)-sum(s-1);
		if(!key)
			puts("No Circular Primes.");
		else if(key==1)		//题目要认真看啊...
			printf("%d Circular Prime.\n",key);
		else
			printf("%d Circular Primes.\n",key);
	}

	return 0;
}
