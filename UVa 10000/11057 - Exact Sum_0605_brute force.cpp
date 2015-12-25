/*
11057 - Exact Sum

brute force...
����ӳ��...
��������...
������Ӷ����Ż�...
һ�����ݱȽ�С,ֱ�Ӹ�...
����...
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
