/*
681 - Convex Hull Finding

convex hull...
just a straight forward convex hull problem...
graham scan will do...
*/

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 520
using namespace std;
const double eps=1e-9;

struct POINT
{
	double x,y;
}pnt[MAXN],key;
int n;

double cross(const POINT &a,const POINT &b,const POINT &c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

double dist(const POINT &a,const POINT &b)
{
	return pow(a.x-b.x,2)+pow(a.y-b.y,2);
}

int cmp(const POINT &a,const POINT &b)
{
	double t=cross(key,a,b);
	return t>0 || (fabs(t)<eps && dist(key,a)<dist(key,b));
}

struct CONVEX_HULL
{
	void read()
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
		}
		--n;
	}

	void process()
	{
		int p=0;
		for(int i=1;i<n;++i)
		{
			if(pnt[i].x<pnt[p].x || ( pnt[i].x==pnt[p].x && pnt[i].y<pnt[p].y ))
				p=i;
		}
		swap(pnt[0],pnt[p]);
		key=pnt[0];

		sort(pnt+1,pnt+n,cmp);

		int sz=2;
		for(int i=2;i<n;++i)
		{
			while(cross( pnt[sz-2],pnt[sz-1],pnt[i] )<=0)
				--sz;
			pnt[sz++]=pnt[i];
		}

		printf("%d\n",sz+1);
		p=0;
		for(int i=1;i<n;++i)
		{
			if(pnt[i].y<pnt[p].y || ( pnt[i].y==pnt[p].y && pnt[i].x<pnt[p].x ))
				p=i;
		}

		for(int i=0;i<sz;++i)
		{
			printf("%.0lf %.0lf\n",pnt[(i+p)%sz].x,pnt[(i+p)%sz].y);
		}
		printf("%.0lf %.0lf\n",pnt[p].x,pnt[p].y);
	}
}final;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);
	printf("%d\n",dataset);

	while(dataset--)
	{
		final.read();
		final.process();
		if(dataset)
		{
			scanf("%*d");
			puts("-1");
		}
	}

	return 0;
}
