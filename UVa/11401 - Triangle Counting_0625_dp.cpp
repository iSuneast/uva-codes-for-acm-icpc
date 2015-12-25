/*
11401 - Triangle Counting

dp..
汗...
为什么c++的longlong明明够用我却用java...
*/

#include<iostream>
#define MAXN 1000001
using namespace std;

long long dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	for(int i=4;i<MAXN;++i)
	{
		long long s=i-3;
		if(s%2==1)
		{
			s=(s+1)/2;
			dp[i]=dp[i-1]+s*s;
		}
		else
		{
			s/=2;
			dp[i]=dp[i-1]+s*s+s;
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF && n>=3)
		printf("%lld\n",dp[n]);

	return 0;
}
