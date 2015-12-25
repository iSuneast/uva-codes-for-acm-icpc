/*
11137 - Ingenuous Cubrency

DP...
coin change...
经典问题...
换钱方法数...

一直觉的这个问题和背包很像...
*/

#include<iostream>
#define MAXN 10010
using namespace std;

long long dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int w;
	dp[0]=1;
	for(int i=1;i<=21;++i)
	{
		w=i*i*i;
		for(int j=w;j<MAXN;++j)
			dp[j]+=dp[j-w];
	}
	while(cin>>w)
		cout<<dp[w]<<endl;

	return 0;
}
