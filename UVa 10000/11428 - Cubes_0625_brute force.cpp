/*
11428 - Cubes

brute force...
为什么可以暴力呢...

x^3-y^3<=n的最大y=x-1
则x^3-y^3=3*x^2-3*x+1<=n
解得x<=59

所以只要枚举x到59就可以了...
*/

#include<iostream>
#define BOUND 60
#define MAXN 10001
using namespace std;

pair<int,int> dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	for(int x=1;x<BOUND;++x)
		for(int y=0;y<x;++y)
		{
			int t=x*x*x-y*y*y;
			if(t<MAXN && !dp[t].first)
				dp[t]=make_pair(x,y);
		}
	int n;
	while(scanf("%d",&n)!=EOF && n)
		if(dp[n].first)
			printf("%d %d\n",dp[n].first,dp[n].second);
		else
			puts("No solution");

	return 0;
}
