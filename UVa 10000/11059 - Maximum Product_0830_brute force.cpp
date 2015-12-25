/*
11059 - Maximum Product

brute force...
quite a simple problem...
just use O(n^3) brute force and long long..
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,var[20],cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		long long key=0,t;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
			for(int j=0;j<=i;++j)
			{
				t=1;
				for(int k=j;k<=i;++k)
					t*=var[k];
				key=max(t,key);
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n",cas++,key);
	}

	return 0;
}
