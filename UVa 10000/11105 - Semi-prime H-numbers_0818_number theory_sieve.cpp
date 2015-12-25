/*
11105 - Semi-prime H-numbers

number theory...
sieve...
模拟素数筛法求出所有H-number
然后用H-number求出H-semi-primes
统计输出即可...
*/

#include<iostream>
#define MAXN 1000002
#define H 250001
using namespace std;

int sum[H],key[H],tot;
bool flag[H];

void init()
{
	for(int i=0;i<H;++i)
		key[i]=4*i+1;
	for(int i=1;i<H;++i)
	{
		if(!flag[i])
			key[tot++]=key[i];
		for(int j=i;j<H;++j)
		{
			int m=key[j]*key[i];
			if(m/key[j]==key[i] && m<MAXN)
				flag[m/4]=true;
			else
				break;
		}
	}

	memset(flag,0,sizeof(flag));
	for(int i=0;i<tot;++i)
	{
		for(int j=i;j<tot;++j)
		{
			int m=key[j]*key[i];
			if(m/key[j]==key[i] && m<MAXN)
				flag[m/4]=true;
			else
				break;
		}
	}

	sum[0]=0;
	for(int i=1;i<H;++i)
	{
		sum[i]=sum[i-1];
		if(flag[i])
			++sum[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	int n;
	while(scanf("%d",&n)!=EOF && n)
		printf("%d %d\n",n,sum[(n+1)/4]);

	return 0;
}
