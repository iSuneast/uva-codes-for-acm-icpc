/*
11875 - Brick Game

Ad hoc...
just output data[n/2] is enough...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n,key;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{ 
			if(i==n/2)
				scanf("%d",&key);
			else
				scanf("%*d");
		}
		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
