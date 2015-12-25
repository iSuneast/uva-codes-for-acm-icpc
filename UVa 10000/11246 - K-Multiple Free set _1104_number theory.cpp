/*
11246 - K-Multiple Free set 

number theory...

we have tmp = n/k numbers which can be divide by k more than once
and also, tmp2 = n/k/k numbers which can be divide by k more than twice
...

according to Inclusion-Exclusion Principle
we'll got the problem's final format...

answer = n - n/k + n/(k^2) - n/(k^3) +...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	long long n,k;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%lld%lld",&n,&k);
		long long cur=1,key=0,op=1;

		while(n/cur)
		{
			key+=op*(n/cur);
			cur*=k;
			op*=-1;
		}

		printf("%lld\n",key);
	}

	return 0;
}
