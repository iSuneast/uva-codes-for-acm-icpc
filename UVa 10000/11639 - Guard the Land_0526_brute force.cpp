/*
11639 - Guard the Land

brute force...
算一下复杂度发现没什么问题...
于是就直接暴力了...= =
*/

#include<iostream>
#define MAXN 110
using namespace std;

struct point
{
	int x,y;
}pnt[4];

void format(point &a,point &b)
{
	if(a.x>b.x)
		swap(a.x,b.x);
	if(a.y>b.y)
		swap(a.y,b.y);
}

char g[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		for(int i=0;i<4;++i)
			scanf("%d%d",&pnt[i].x,&pnt[i].y);
		format(pnt[0],pnt[1]);
		format(pnt[2],pnt[3]);
		int s=100*100,s1=0,s2=0;
		memset(g,0,sizeof(g));
		for(int i=pnt[0].x;i<pnt[1].x;++i)
			for(int j=pnt[0].y;j<pnt[1].y;++j)
				++g[i][j],--s,++s1;
		for(int i=pnt[2].x;i<pnt[3].x;++i)
			for(int j=pnt[2].y;j<pnt[3].y;++j)
				if(!g[i][j])
					--s,++s1;
				else
					++s2,--s1;

		printf("Night %d: %d %d %d\n",cas,s2,s1,s);
	}

	return 0;
}
