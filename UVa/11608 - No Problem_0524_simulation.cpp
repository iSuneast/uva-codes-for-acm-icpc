/*
11608 - No Problem

simulation...
直接模拟即可...
*/

#include<iostream>
#define MONTH 12
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int s,cas=1;
	while(scanf("%d",&s)!=EOF && s>=0)
	{
		int creat[MONTH],require[MONTH];
		for(int i=0;i<MONTH;++i)
			scanf("%d",creat+i);
		for(int i=0;i<MONTH;++i)
			scanf("%d",require+i);

		printf("Case %d:\n",cas++);

		for(int i=0;i<MONTH;++i)
		{
			if(s>=require[i])
			{
				s-=require[i];
				puts("No problem! :D");
			}
			else
				puts("No problem. :(");
			s+=creat[i];
		}
	}

	return 0;
}
