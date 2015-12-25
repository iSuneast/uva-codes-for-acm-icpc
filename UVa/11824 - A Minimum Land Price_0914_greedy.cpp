/*
11824 - A Minimum Land Price

greedy...
just sort according the price
and then calc the answer
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,var[43];
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n=0;
		long long key=0;
		while(scanf("%d",&var[n])!=EOF && var[n])
			++n;
		sort(var,var+n);
		for(int i=n-1;i>=0;--i)
		{
			int t=1,j=n-i;
			while(j--)
				t*=var[i];
			key+=t;
			if(key+t>2500000)
			{
				key=-1;
				break;
			}
		}

		if(key==-1)
			puts("Too expensive");
		else
			printf("%lld\n",key*2);
	}

	return 0;
}
