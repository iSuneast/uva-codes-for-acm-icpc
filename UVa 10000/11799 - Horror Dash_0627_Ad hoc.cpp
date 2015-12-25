/*
11799 - Horror Dash

Ad hoc...
水题...
最大的那个就是答案了...
*/

#include<iostream>
#define INF 0x7f7f7f7f
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int n,t,key=-INF;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&t);
			key=max(key,t);
		}
		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
