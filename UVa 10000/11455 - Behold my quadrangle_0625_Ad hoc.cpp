/*
11455 - Behold my quadrangle

Ad hoc...
对四条边进行排序...
然后按题意判断即可...

p.s.UVa真的是个大水库啊..
*/

#include<iostream>
#include<algorithm>
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
		int var[4];
		scanf("%d%d%d%d",var,var+1,var+2,var+3);
		sort(var,var+4);

		if(var[0]==var[3])
			puts("square");
		else if(var[0]==var[1] && var[2]==var[3])
			puts("rectangle");
		else if(var[0]+var[1]+var[2]>var[3])
			puts("quadrangle");
		else
			puts("banana");
	}

	return 0;
}
