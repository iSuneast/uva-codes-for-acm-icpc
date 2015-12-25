/*
11849 - CD

Ad hoc...
just calc the number of CD with same catalog
*/

#include<iostream>
#define MAXN 1000003
using namespace std;

int jack[MAXN],jill[MAXN],n,m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&jack[i]);
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d",&jill[i]);
		}

		int a=0,b=0,key=0;
		while(a<n && b<m)
		{
			if(jack[a]>jill[b])
				++b;
			else if(jack[a]<jill[b])
				++a;
			else
			{
				++key;
				++a;
				++b;
			}
		}

		printf("%d\n",key);
	}

	return 0;
}
