/*
11012 - Cosmic Cabbages

math...
1) Get the 8 corners of the bounding box of the points{(+-)INF,(+-)INF,(+-)INF}
2) For each corner, get the nearest point to it (in tie, choose any).
3) For each of these 8 points, compute its distance from all other points.
*/

#include<iostream>
#define MAXN 100003
using namespace std;
const int INF=0x1f1f1f1f;

const int corner[8][3]={
	{INF,INF,INF},{INF,INF,-INF},
	{INF,-INF,INF},{-INF,INF,INF},
	{INF,-INF,-INF},{-INF,-INF,INF},
	{-INF,INF,-INF},{-INF,-INF,-INF},
};

int n,pos[8],d[8],cube[MAXN][3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		int dis,key=0;
		memset(d,0x7f,sizeof(d));
		for(int i=0;i<n;++i)
		{
			for(int k=0;k<3;++k)
			{
				scanf("%d",&cube[i][k]);
			}

			for(int j=0;j<8;++j)
			{
				dis=0;
				for(int k=0;k<3;++k)
					dis+=abs(cube[i][k]-corner[j][k]);
				if(dis<d[j])
				{
					d[j]=dis;
					pos[j]=i;
				}
			}
		}

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<8;++j)
			{
				dis=0;
				for(int k=0;k<3;++k)
				{
					dis+=abs(cube[i][k]-cube[ pos[j] ][k]);
				}
				key=max(dis,key);
			}
		}

		printf("Case #%d: %d\n",cas,key);
	}

	return 0;
}
