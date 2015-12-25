/*
11428 - Cubes

brute force...
Ϊʲô���Ա�����...

x^3-y^3<=n�����y=x-1
��x^3-y^3=3*x^2-3*x+1<=n
���x<=59

����ֻҪö��x��59�Ϳ�����...
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
