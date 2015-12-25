/*
11089 - Fi-binary Number

number theory...
the tree is a fib tree
find out the law 
and then simulate it ...
fib tree start from 0, the total node = sum(fib[1]-fib[p+1])-1
fib tree start from 1, the total node = sum(fib[1]-fib[p])
try to find out yourself ...
it's a interesting game..
*/

#include<iostream>
#define MAXN 43
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	long long fib[MAXN],sum[MAXN];
	fib[1]=fib[2]=1;
	sum[0]=0;sum[1]=1;sum[2]=2;
	for(int i=3;i<MAXN;++i)
	{
		fib[i]=fib[i-1]+fib[i-2];
		sum[i]=fib[i]+sum[i-1];
	}

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		if(n==1)
			puts("1");
		else if(n==2)
			puts("10");
		if(n<=2)
			continue;

		int p=lower_bound(sum+1,sum+MAXN,n)-sum;
		printf("10");
		n-=2;p-=2;
		while(p)
		{
			if(p==1)
			{
				if(n==1)
					putchar('0');
				else
					putchar('1');
				break;
			}

			int tot=sum[p+1]-1+sum[p-1];

			if(n<=tot)
			{
				putchar('0');
				n-=sum[p-1]+1;
				--p;
			}
			else
			{
				printf("10");
				n-=(sum[p+1]-1)+2;
				p-=2;
			}
		}
		putchar(10);
	}

	return 0;
}
