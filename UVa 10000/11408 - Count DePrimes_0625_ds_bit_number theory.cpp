/*
11408 - Count DePrimes

data struct..
bit
树状数组...
塞出符合条件的素数...
插入树状数组...
然后对区间求和即可...
*/

#include<iostream>
#define MAXN 5000001
#define lowbit(x) (x&(-x))
using namespace std;

int prime[MAXN],bit[MAXN];

void modify(int n)
{
	while(n<MAXN)
	{
		bit[n]++;
		n+=lowbit(n);
	}
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

	for(int i=2;i<MAXN;++i)
	{
		if(prime[i]==0)
		{
			modify(i);
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]+=i;
		}
		else if(prime[ prime[i] ]==0)
			modify(i);
	}

	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && a)
		printf("%d\n",sum(b)-sum(a-1));

	return 0;
}
