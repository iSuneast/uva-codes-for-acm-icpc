/*
10585 - Center of symmetry

geometry...
sort the point...
scan from two bound
check if there sum is the same
be care of the duplicate point
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 10003
using namespace std;
const double eps=1e-9;

struct POINT
{
	double x,y;
	bool operator<(const POINT &t)const
	{
		if(fabs(x-t.x)<eps)
			return y<t.y;
		return x<t.x;
	}
	bool operator!=(const POINT &t)const
	{
		return fabs(x-t.x)>eps || fabs(y-t.y)>eps;
	}
}pnt[MAXN];
int n;

bool ok()
{
	int start=0,end=n-1;
	POINT mid,tmp;
	mid.x=pnt[start].x+pnt[end].x;
	mid.y=pnt[start].y+pnt[end].y;

	while(start<end)
	{
		tmp.x=pnt[start].x+pnt[end].x;
		tmp.y=pnt[start].y+pnt[end].y;

		for(start=start+1;start<end;++start)
			if(pnt[start]!=pnt[start-1])
				break;

		for(end=end-1;end>start;--end)
			if(pnt[end]!=pnt[end+1])
				break;

		if(tmp!=mid)
			return false;
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
		}
		sort(pnt,pnt+n);

		puts(ok()?"yes":"no");
	}

	return 0;
}
