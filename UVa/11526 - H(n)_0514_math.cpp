/*
11526 - H(n)

math...
数学题,推公式...
@ n<=0的话,解为0
@ n比较小的话,直接暴力枚举
@ n比较大的话,枚举到sqrt(n)为止,然后找规律
	n=15   /1 /2 /3 /4 /5 /6 /7 /8  ......
	key+=  15  7  5  3  3  2  2  1  1...
规律还是很明显的
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long dataset;
	scanf("%lld",&dataset);
	while(dataset--)
	{
		long long key=0,i,j,cur,n;
		scanf("%lld",&n);
		if(n<=0)
			key=0;
		else if(n<=1000)
		{
			for(i=1;i<=n;++i)
				key+=n/i;
		}
		else
		{
			for(i=1;i*i<=n;++i)
				key+=n/i;
			for(j=--i;j>1;--j)
			{
				cur=n/j;
				key+=(cur-i)*j;
				i=cur;
			}
			key+=n-n/2;
		}
		printf("%lld\n",key);
	}

	return 0;
}
