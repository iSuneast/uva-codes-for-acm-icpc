/*
109 - SCUD Busters

geometry...
convex hull...

just calculate the country's convex hull at first
then figure out the area of the convex hull
for every point, check whether it's inside the convex hull
done...

don't care to much about the precision error if your solution is ok.
*/

#include<iostream>
#include<algorithm>
#define MAXN 105
using namespace std;
const double eps=1e-9;

struct POINT
{
	double x,y;
}node,bgn;

double sqr(const double &t)
{
	return t*t;
}

double dis(const POINT &a,const POINT &b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}

double cross(const POINT &a,const POINT &b,const POINT &c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool GrahamCmp(const POINT &a,const POINT &b)
{
	double tmp=cross(bgn,a,b);
	return tmp>0
		|| (fabs(tmp)<eps && dis(a,bgn)<dis(b,bgn));
}

void Graham(POINT pnt[MAXN],int &sz)
{
	int p=0;
	for(int i=1;i<sz;++i)
		if(pnt[i].x<pnt[p].x || (fabs(pnt[i].x-pnt[p].x)<eps && pnt[i].y<pnt[p].y) )
			p=i;

	swap(pnt[0],pnt[p]);
	bgn=pnt[0];
	sort(pnt+1,pnt+sz,GrahamCmp);
	int top=2;
	for(int i=3;i<sz;++i)
	{
		while(top>=2 && cross(pnt[top-1],pnt[top],pnt[i])<eps)
			--top;
		pnt[++top]=pnt[i];
	}
	pnt[sz=++top]=pnt[0];
}

struct CONVEX
{
	POINT pnt[MAXN];
	int sz;
	double area;
	bool beaten;

	void read(const int &_sz)
	{
		sz=_sz;
		beaten=false;
		for(int i=0;i<sz;++i)
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
	}

	void Area()
	{
		area=0;
		for(int i=2;i<sz;++i)
			area+=cross(pnt[0],pnt[i-1],pnt[i]);
		area/=2.0;
	}

	void ChkInside(POINT &t)
	{
		if(beaten)
			return ;

		double key=0,tmp;
		for(int i=1;i<=sz;++i)
		{
			tmp=cross(t,pnt[i-1],pnt[i]);
			if(tmp<eps)
				return ;
			key+=tmp;
		}

		if(fabs(key-area*2.0)<eps)
			beaten=true;
	}
}country[23];
int tot;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	tot=0;
	int sz;
	while(scanf("%d",&sz)!=EOF && sz!=-1)
	{
		country[tot].read(sz);
		Graham(country[tot].pnt,country[tot].sz);
		country[tot].Area();
		++tot;
	}

	while(scanf("%lf%lf",&node.x,&node.y)!=EOF)
	{
		for(int i=0;i<tot;++i)
			country[i].ChkInside(node);
	}

	double ans=0;
	for(int i=0;i<tot;++i)
		if(country[i].beaten)
			ans+=country[i].area;

	printf("%.2lf\n",ans);

	return 0;
}
