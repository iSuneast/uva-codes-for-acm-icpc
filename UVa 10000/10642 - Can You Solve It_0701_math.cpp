/*
10642 - Can You Solve It?

math...
找规律...
无语的是题目给的笛卡尔坐标是x,y颠倒的...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int x1,y1,x2,y2,dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		int z1=x1+y1+1,z2=x2+y2-1;
		printf("Case %d: %d\n",cas, (z1+z2)*(z2-z1+1)/2 + z2-z1+2+x1+y2 );
	}

	return 0;
}
