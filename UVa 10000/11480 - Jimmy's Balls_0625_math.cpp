/*
11480 - Jimmy's Balls

math...
推推公式就出来了...
a	b	c
------------
1	2	n-3
1	3	n-4
1	4	n-5
....
========
2	3	n-5
2	4	n-6
2	5	n-7
....
========
		发现规律
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		long long key=0;
		for(int i=1;i<n/3;++i)
		{
			int s=i+1,e=n-i-i-1;
			key+=(e+s)/2-s;
			if((e+s)&1)
				++key;
		}
		printf("Case %d: %lld\n",cas++,key);
	}

	return 0;
}
