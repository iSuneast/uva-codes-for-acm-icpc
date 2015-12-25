/*
11536 - Smallest Sub-Array

Ad hoc...
按题意初始化x[]值
a=0,b=1
从头开始扫描...
先扩展b,直到包含必须的所有元素
扩展a,直到有一个元素没有被包含
此时,可以得知[a-1,b]区间包含所有元素,
算出所有解,取最小即可...
*/

#include<iostream>
#define MAXN 1000003
#define INF 0x3f3f3f3f
using namespace std;

int var[MAXN],n,m,k;
int flag[1003];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	var[1]=1,var[2]=2,var[3]=3;
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=4;i<=n;++i)
			var[i]=(var[i-1]+var[i-2]+var[i-3])%m+1;

		memset(flag,0,sizeof(flag));
		int a=0,b=1,cnt=0,key=INF;
		while(a<b)
		{
			while(b<=n && cnt<k)
			{
				if(var[b]<=k)
				{
					if(!flag[ var[b] ])
						++cnt;
					++flag[ var[b] ];
				}
				++b;
			}
			if(cnt!=k)
				break;
			while(a<n && a<b && cnt==k)
			{
				++a;
				if(var[a]<=k)
				{
					--flag[ var[a] ];
					if(!flag[ var[a] ])
					{
						--cnt;
						key=min(key,b-a);
						break;
					}
				}
			}
		}

		if(key==INF)
			printf("Case %d: sequence nai\n",cas);
		else
			printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
