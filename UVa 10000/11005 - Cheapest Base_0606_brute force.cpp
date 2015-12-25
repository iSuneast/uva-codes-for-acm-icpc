/*
11005 - Cheapest Base

brute force...
枚举所有的进制,取最小值即可...
*/

#include<iostream>
#define MAXN 40
#define INF 0x7f7f7f7f
using namespace std;

int cost[MAXN],n,hash[128];
char str[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void chk(int base,int var)
{
	int &cur=cost[base]=0;
	while(var)
	{
		int t=var%base;
		var/=base;
		if(t>=10)
			cur+=hash[t-10+'A'];
		else
			cur+=hash[t+'0'];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		for(int i=0;i<36;++i)
			scanf("%d",&hash[ str[i] ]);
		int q,var;
		scanf("%d",&q);
		printf("Case %d:\n",cas);
		while(q--)
		{
			scanf("%d",&var);
			int key=INF;
			for(int i=2;i<=36;++i)
			{
				chk(i,var);
				key=min(key,cost[i]);
			}
			printf("Cheapest base(s) for number %d:",var);
			for(int i=2;i<=36;++i)
				if(cost[i]==key)
					printf(" %d",i);
			putchar('\n');
		}
		if(cas!=dataset)
			putchar('\n');
	}

	return 0;
}
