/*
11727 - Cost Cutting

Ad hoc..
那个...
原来题目可以水成这样...

求三个数的中位数即可...
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,a[3];
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("Case %d: %d\n",cas,a[1]);
	}

	return 0;
}
