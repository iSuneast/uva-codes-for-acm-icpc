/*
11650 - Mirror Clock

Ad hoc...
求镜面对称的时钟
可知时钟正反的数字和一定是12h或24h
讨论一下即可.
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
		int h,m;
		scanf("%d:%d",&h,&m);
		if(!m)
			h=12-h;
		else
		{
			m=60-m;
			h=(11-h+12)%12;
		}
		if(!h)
			h=12;
		printf("%02d:%02d\n",h,m);
	}

	return 0;
}
