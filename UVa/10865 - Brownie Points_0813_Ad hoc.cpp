/*
10865 - Brownie Points

Ad hoc...
判断点在那个象限...
累加即可...
*/

#include<iostream>
#define MAXN 200003
using namespace std;

struct POINT
{
	int x,y;
}pnt[MAXN];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		int Stan=0,Ollie=0,p=(n-1)>>1;
		for(int i=0;i<n;++i)
			scanf("%d%d",&pnt[i].x,&pnt[i].y);
		for(int i=0;i<n;++i)
		{
			if(pnt[i].x<pnt[p].x)
			{
				if(pnt[i].y>pnt[p].y)
					++Ollie;
				else if(pnt[i].y<pnt[p].y)
					++Stan;
			}
			else if(pnt[i].x>pnt[p].x)
			{
				if(pnt[i].y>pnt[p].y)
					++Stan;
				else if(pnt[i].y<pnt[p].y)
					++Ollie;
			}
		}

		printf("%d %d\n",Stan,Ollie);
	}

	return 0;
}
