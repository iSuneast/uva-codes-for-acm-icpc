/*
11437 - Triangle Fun

geometry....
很显然,被分割后的三角形的面积与原三角形的面积呈线性相关...
所以算都不用算直接与output比较一下即可...
*/

#include<iostream>
#include<cmath>
using namespace std;

struct point
{
	double x,y;
}pnt[3];

double distant(point &a,point &b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		double len[3];
		for(int i=0;i<3;++i)
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
		len[0]=distant(pnt[0],pnt[1]);
		len[1]=distant(pnt[0],pnt[2]);
		len[2]=distant(pnt[2],pnt[1]);
		double t=(len[0]+len[1]+len[2])/2;
		double s=t*(t-len[0])*(t-len[1])*(t-len[2]);
		printf("%.0lf\n",sqrt(s)/7.0);
	}

	return 0;
}
