/*
11369 - Shopaholic

greedy...
买二送一...
当然送的东西越贵越好 = =
对所有物品降序排列
取第3*k个物品累加就是答案了...
*/

#include<iostream>
#include<algorithm>
#define MAXN 20010 
using namespace std;

int var[MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);
		sort(var,var+n);

		int p=n-3,key=0;
		while(p>=0)
			key+=var[p],p-=3;

		printf("%d\n",key);
	}

	return 0;
}
