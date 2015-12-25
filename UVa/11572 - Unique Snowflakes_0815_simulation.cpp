/*
11572 - Unique Snowflakes

simulation...
模拟一个队列即可...
用map记录每个元素的映射
看映射是否存在,存在的话,则
删除所有在映射前出现的元素...
统计队列里面元素的个数,最多的就是答案了...
*/

#include<iostream>
#include<map>
#define MAXN 1000003
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

int var[MAXN],n,pos[MAXN];
bool flag[MAXN];
map<int,int> mii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		memset(flag,0,sizeof(flag));
		mii.clear();

		int tot=0,front=0,_max=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
			if(mii.find(var[i])==mii.end())
				pos[i]=tot,mii[ var[i] ]=tot++;
			else
				pos[i]=mii[ var[i] ];

			if(flag[ pos[i] ])
			{
				do
					flag[ pos[front] ]=false;
				while(pos[front++]!=pos[i]);
			}
			_max=max(_max,i-front+1);
			flag[ pos[i] ]=true;
		}

		printf("%d\n",_max);
	}

	return 0;
}
