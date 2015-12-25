/*
10871 - Primed Subsequence

brute force...
just enum every subsequence and check whether its sum is a prime
*/

#include<iostream>
#define MAXN 10003
using namespace std;

int dataset,n,var[MAXN],sum[MAXN];

bool isprime(int key)
{
	for(int i=2;i*i<=key;++i)
		if(key%i==0)
			return false;
	return true;
}

void process()
{
	for(int l=2;l<n;++l)
	{
		for(int s=1;s+l-1<=n;++s)
		{
			if(isprime(sum[s+l-1]-sum[s-1]))
			{
				printf("Shortest primed subsequence is length %d:",l);
				for(int k=s;k<s+l;++k)
					printf(" %d",var[k]);
				putchar(10);
				return ;
			}
		}
	}
	puts("This sequence is anti-primed.");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&var[i]);
			sum[i]=sum[i-1]+var[i];
		}

		process();
	}

	return 0;
}
