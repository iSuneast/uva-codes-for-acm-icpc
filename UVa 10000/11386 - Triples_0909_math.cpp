/*
11386 - Triples

math...
use long long to handle the answer
remove duplicates and count its frequent
bsearch the value we can got use O(n^2) scan
so total time complex is O(N^2logN) 
*/

#include<iostream>
#include<algorithm>
#define MAXN 5003
using namespace std;

int n,var[MAXN];
long long freq[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
		}
		sort(var,var+n);
		int p=0;
		memset(freq,0,sizeof(freq));
		for(int i=0;i<n;++i)
		{
			if(var[i]!=var[p])
				var[++p]=var[i];
			++freq[p];
		}
		n=p+1;

		long long key=0;
		for(int i=0;i<n;++i)
		{
			for(int j=i;j<n;++j)
			{
				int t=var[i]+var[j];
				int p=lower_bound(var,var+n,t)-var;
				if(var[p]==t)
				{
					if(i==j)
						key+=freq[i]*(freq[i]-1)/2*freq[p];
					else
						key+=freq[i]*freq[j]*freq[p];
				}
			}
		}

		printf("%lld\n",key);
	}

	return 0;
}
