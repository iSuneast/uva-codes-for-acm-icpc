/*
11364 - Parking

math...
反正一条街都是要从头到尾走一遍来回的...
而主人的力气又很大...
所以只有一次来回就OK了..
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,var,maxi,mini;
		scanf("%d",&n);
		scanf("%d",&var);
		mini=maxi=var;
		while(--n)
		{
			scanf("%d",&var);
			mini=min(var,mini);
			maxi=max(var,maxi);
		}
		printf("%d\n",(maxi-mini)<<1);
	}

	return 0;
}
