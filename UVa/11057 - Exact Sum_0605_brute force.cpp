/*
11057 - Exact Sum

brute force...
暴力映射...
暴力查找...
本来想加二分优化...
一看数据比较小,直接搞...
过了...
Orz...
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

int n,money;
bool hash[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		memset(hash,0,sizeof(hash));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&money);
			hash[money]=true;
		}
		scanf("%d",&money);
		int tmp=money>>1;
		while(tmp)
		{
			if(hash[tmp] && hash[money-tmp])
			{
				printf("Peter should buy books whose prices are %d and %d.\n\n",tmp,money-tmp);
				break;
			}
			--tmp;
		}
	}

	return 0;
}
