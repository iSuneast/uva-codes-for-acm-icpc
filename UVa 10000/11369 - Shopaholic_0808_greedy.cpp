/*
11369 - Shopaholic

greedy...
�����һ...
��Ȼ�͵Ķ���Խ��Խ�� = =
��������Ʒ��������
ȡ��3*k����Ʒ�ۼӾ��Ǵ���...
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
