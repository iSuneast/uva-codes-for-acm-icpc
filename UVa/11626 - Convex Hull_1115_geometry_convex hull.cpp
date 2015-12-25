/*
11626 - Convex Hull

geometry...
convex hull...

this problem is just want U to output the points on the convex hull
be care of the points three in the same line with the Begin
the GrahamCmp function should modify a lot to suit for the situation

	if(fabs(cross(bgn,a,b))<eps)
	{
		if(a.y<=bgn.y)
			return dis(bgn,a)<dis(bgn,b);
		else
			return dis(bgn,a)>dis(bgn,b);
	}

no more trick...
o(n_n)o~
*/

#include<iostream>
#include<algorithm>
#define MAXN 100003
using namespace std;
const double eps=1e-9;

struct POINT
{
	double x,y;
}bgn;

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
	if(tmp>eps)
		return true;
	if(fabs(tmp)<eps)
	{
		if(a.y<=bgn.y)
			return dis(bgn,a)<dis(bgn,b);
		else
			return dis(bgn,a)>dis(bgn,b);
	}
	return false;
}

struct CONVEX
{
	POINT pnt[MAXN];
	int sz;

	void read(int _sz)
	{
		sz=0;
		char op[3];
		while(_sz--)
		{
			scanf("%lf%lf%s",&pnt[sz].x,&pnt[sz].y,op);
			if(op[0]=='Y')
				++sz;
		}
	}

	void Graham()
	{
		int p=0;
		for(int i=1;i<sz;++i)
			if(pnt[i].x<pnt[p].x || (fabs(pnt[i].x-pnt[p].x)<eps && pnt[i].y<pnt[p].y))
				p=i;
		swap(pnt[0],pnt[p]);
		bgn=pnt[0];
		sort(pnt+1,pnt+sz,GrahamCmp);
		printf("%d\n",sz);
		for(int i=0;i<sz;++i)
			printf("%.0lf %.0lf\n",pnt[i].x,pnt[i].y);
	}
}polygon;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		polygon.read(n);
		polygon.Graham();
	}

	return 0;
}

/*	------ input
2
12
0 0 Y
2 0 Y
1 0 Y
3 0 Y
3 3 Y
1 3 Y
2 3 Y
3 1 Y
3 2 Y
0 1 Y
0 2 Y
0 3 Y
8
0 -2 Y
1 -1 Y
2 0 Y
1 1 Y
0 2 Y
-1 1 Y
-2 0 Y
-1 -1 Y
	------ output
12
0 0
1 0
2 0
3 0
3 1
3 2
3 3
2 3
1 3
0 3
0 2
0 1
8
-2 0
-1 -1
0 -2
1 -1
2 0
1 1
0 2
-1 1
*/
