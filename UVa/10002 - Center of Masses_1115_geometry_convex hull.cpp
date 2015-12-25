/*
10002 - Center of Masses

geometry...
convex hull...

calculate the convex hull of the polygon at first
then the center of the polygon is 
x=sum( (pnt[i].x+pnt[i+1].x)*cross(pnt[i],pnt[i+1]) ) / (6*area)
y=sum( (pnt[i].y+pnt[i+1].y)*cross(pnt[i],pnt[i+1]) ) / (6*area)
*/

#include<iostream>
#include<algorithm>
#define MAXN 103
using namespace std;
const double eps=1e-9;

struct POINT
{
	double x,y;
}bgn;

double cross(const POINT &a,const POINT &b,const POINT &c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double cross(POINT &a,POINT &b)
{
	return a.x*b.y-a.y*b.x;
}

double sqr(const double &t)
{
	return t*t;
}

double dis(const POINT &a,const POINT &b)
{
	return sqr(b.x-a.x)+sqr(b.y-a.y);
}

bool GrahamCmp(const POINT &a,const POINT &b)
{
	double tmp=cross(bgn,a,b);
	return tmp>eps || (fabs(tmp)<eps && dis(bgn,a)<dis(bgn,b));
}

struct CONVEX
{
	POINT pnt[MAXN],center;
	int sz;
	double area;

	void read(int &_sz)
	{
		sz=_sz;
		for(int i=0;i<sz;++i)
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
	}

	void Graham()
	{
		int p=0;
		for(int i=1;i<sz;++i)
			if(pnt[i].x<pnt[p].x || (fabs(pnt[i].x-pnt[p].x)<eps && pnt[i].y<pnt[p].y))
				p=i;
		swap(pnt[0],pnt[p]);
		bgn=pnt[0];
		sort(pnt,pnt+sz,GrahamCmp);

		p=2;
		for(int i=3;i<sz;++i)
		{
			while(p>1 && cross(pnt[p-1],pnt[p],pnt[i])<eps)
				--p;
			pnt[++p]=pnt[i];
		}

		pnt[sz=++p]=pnt[0];
	}

	void Area()
	{
		area=0;
		for(int i=1;i<sz;++i)
			area+=cross(pnt[0],pnt[i],pnt[i+1]);
		area/=2;
	}

	void Center()
	{
		Area();
		center.x=center.y=0;
		for(int i=0;i<sz;++i)
		{
			double t=cross(pnt[i],pnt[i+1]);
			center.x+=(pnt[i].x+pnt[i+1].x)*t;
			center.y+=(pnt[i].y+pnt[i+1].y)*t;
		}
		center.x/=6*area;
		center.y/=6*area;
	}
}polygon;
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n>2)
	{
		polygon.read(n);
		polygon.Graham();
		polygon.Center();

		printf("%.3lf %.3lf\n",polygon.center.x,polygon.center.y);
	}

	return 0;
}
