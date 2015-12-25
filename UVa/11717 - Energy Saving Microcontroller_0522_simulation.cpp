/*
11717 - Energy Saving Microcontroller

simulation...
做模拟题其实是没什么技巧可言的...
保持一个清醒的头脑就是一个明智的选择...
大不了推翻重写罢.
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
	for(int cas=1;cas<=dataset;++cas)
	{
		int n,sleep,start,inactive=0,ignored=0,time;
		bool active=true;
		scanf("%d%d%d",&n,&sleep,&start);
		int cur=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&time);
			if(time<cur)
				++ignored;
			else if(time<cur+sleep)
				cur=time;
			else
			{
				++inactive;
				cur=time+start;
			}
		}
		printf("Case %d: %d %d\n",cas,inactive,ignored);
	}

	return 0;
}
