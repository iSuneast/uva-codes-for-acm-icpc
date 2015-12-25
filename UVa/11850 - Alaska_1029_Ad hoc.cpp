/*
11850 - Alaska

Ad hoc...
although it's a simple problem...
but I have kept getting WA for a few times...

*
* There is a charging station in Dawson Creek,
* where she begins her journey,
* and also several charging stations along the way.
*

it means that THERE'S NO CHARGING STATION IN ALASKA

be careful about it...
*/

#include<iostream>
#include<algorithm>
#define MAXN 1422
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,d[MAXN+7];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&d[i]);
		}
		d[n++]=0;
		sort(d,d+n);

		bool ok=true;
		for(int i=1;i<n && ok;++i)
		{
			if(d[i]-d[i-1]>200)
				ok=false;
		}
		if(MAXN-d[n-1]>100)
			ok=false;

		puts(ok?"POSSIBLE":"IMPOSSIBLE");
	}

	return 0;
}
