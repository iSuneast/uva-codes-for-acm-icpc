/*
11389 - The Bus Driver Problem

Ad hoc...
sort && greedy
*/

#include<iostream>
#include<algorithm>
#define MAXN 103
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,d,r,am[MAXN],pm[MAXN];
	while(scanf("%d%d%d",&n,&d,&r)!=EOF && (n||d||r))
	{
		for(int i=0;i<n;++i)
			scanf("%d",&am[i]);
		sort(am,am+n);
		for(int i=0;i<n;++i)
			scanf("%d",&pm[i]);
		sort(pm,pm+n);
		int key=0,t;
		for(int i=0;i<n;++i)
		{
			t=am[i]+pm[n-1-i];
			if(t>d)
				key+=(t-d)*r;
		}

		printf("%d\n",key);
	}

	return 0;
}
