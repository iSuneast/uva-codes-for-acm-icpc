/*
11764 - Jumping Mario

Ad hoc...
天哪...
UVa水题还真多啊...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		int high=0,low=0,var,pre;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var);
			if(i)
			{
				if(pre>var)
					++low;
				else if(pre<var)
					++high;
			}
			pre=var;
		}
		printf("Case %d: %d %d\n",cas,high,low);
	}

	return 0;
}
