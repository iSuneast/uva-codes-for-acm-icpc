/*
10830 - A New Function

math...
take 10 for example
1 :			=  0
2 :			=  0
3 :			=  0
4 :	2		=  2
5 :			=  2
6 :	2 3		=  7
7 :			=  7
8 :	2 4		= 13
9 :	3		= 16
10:	2 5		= 23
=  2 * (10/2 - 2 +1 ) + ( 3 + 4 + 5 )
 + 3 * (10/3 - 3 +1 )
simple, isn't ?
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1,n;
	while(scanf("%d",&n)!=EOF && n)
	{
		int p=2;
		long long ans=0,cnt;
		for(;p*p<n;++p)
		{
			cnt=n/p;
			ans+=(p+1+cnt)*(cnt-p)/2+p*(cnt-p+1);
		}
		if(p*p==n)
			ans+=p;

		printf("Case %d: %lld\n",cas++,ans);
	}

	return 0;
}
