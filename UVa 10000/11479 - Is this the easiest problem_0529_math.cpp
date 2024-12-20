/*
11479 - Is this the easiest problem?

math...
判断三角形是否合法...
竟然会溢出...
*/

#include<iostream>
#include<algorithm>
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
		long long edge[3];
		scanf("%lld%lld%lld",edge,edge+1,edge+2);
		sort(edge,edge+3);
		printf("Case %d: ",cas);
		if(edge[0]+edge[1]<=edge[2] || edge[0]<=0)		//加法溢出
			puts("Invalid");
		else if(edge[0]==edge[2])
			puts("Equilateral");
		else if(edge[0]==edge[1] || edge[1]==edge[2])
			puts("Isosceles");
		else
			puts("Scalene");
	}

	return 0;
}
