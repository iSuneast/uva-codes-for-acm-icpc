/*
10173 - Smallest Bounding Rectangle

geometry...
convex hull...
Rotating Calipers...

after so many times of WA
I finally figure out that, when n<3 the answer should be "0.0000"
don't do any more calculate...

http://cgm.cs.mcgill.ca/~orm/rotcal.html

I don't think I'm strong enough to describe the algorithm
	on my own words in English,
so any problem, you can refer to the links above for more details...
*/

#include<iostream>
#include<algorithm>
#include<ctime>
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-7;

struct POINT
{
	double x,y;
}bgn;

double cross(const POINT &a,const POINT &b,const POINT &c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double product(const POINT &a,const POINT &b,const POINT &c)
{
	return (a.x-b.x)*(a.x-c.x)+(a.y-b.y)*(a.y-c.y);
}

double sqr(const double &t)
{
	return t*t;
}

double dis(const POINT &a,const POINT &b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}

bool GrahamCmp(const POINT &a,const POINT &b)
{
	double tmp=cross(bgn,a,b);
	return tmp>eps || ( fabs(tmp)<eps && dis(bgn,a)<dis(bgn,b) );
}

struct CONVEX
{
	POINT pnt[MAXN];
	int sz;

	void read(int _sz)
	{
		sz=_sz;
		for(int i=0;i<sz;++i)
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
	}

	void Graham()
	{
		if(sz<3)
			return ;
		int p=0;
		for(int i=1;i<sz;++i)
			if(pnt[i].x<pnt[p].x || (fabs(pnt[i].x-pnt[p].x)<eps && pnt[i].y<pnt[p].y))
				p=i;
		swap(pnt[0],pnt[p]);
		bgn=pnt[0];
		sort(pnt+1,pnt+sz,GrahamCmp);
		p=0;
		for(int i=0;i<sz;++i)
		{
			if(fabs(pnt[i].x-pnt[p].x)<eps
				&& fabs(pnt[i].y-pnt[p].y)<eps)
				continue;
			else
				pnt[++p]=pnt[i];
		}

		sz=p+1;

		p=2;
		for(int i=3;i<sz;++i)
		{
			while(p>1 && cross(pnt[p-1],pnt[p],pnt[i])<eps)
				--p;
			pnt[++p]=pnt[i];
		}

		pnt[sz=++p]=pnt[0];
	}

	int next(int &p)
	{
		return (p+1)%sz;
	}

	void TopMost(int &top,const int &a,const int &b)
	{
		while(cross(pnt[next(top)],pnt[a],pnt[b])>cross(pnt[top],pnt[a],pnt[b]))
			top=next(top);
	}

	void LeftRight(int &p,const int &a,const int &b)
	{
		while(product(pnt[a],pnt[next(p)],pnt[b])<product(pnt[a],pnt[p],pnt[b]))
			p=next(p);
	}

	double RotatingCalipers()
	{
		if(sz<3)
			return 0;

		double key=INF,tmp,buf;
		int top=2,l=2,r=1;
		TopMost(l,0,1);

		for(int i=0;i<sz;++i)
		{
			TopMost(top,i,i+1);
			LeftRight(l,i,i+1);
			LeftRight(r,i+1,i);

			buf=cross(pnt[top],pnt[i],pnt[i+1]);
			tmp=product(pnt[i],pnt[l],pnt[i+1])+product(pnt[i+1],pnt[r],pnt[i]);
			key=min(key,buf-tmp*buf/dis(pnt[i],pnt[i+1]));
		}
		return fabs(key);
	}
}polygon;

void RandomData()
{
	srand((unsigned)time(NULL));
	int dataset=1000;
	while(dataset--)
	{
		int n=rand()%100+1;
		cout<<n<<endl;
		while(n--)
			cout<<rand()<<" "<<rand()<<endl;
		cout<<endl;
	}
	cout<<0<<endl;	
}

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("in","w",stdout); RandomData();	return 0;
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		polygon.read(n);
		polygon.Graham();
		printf("%.4lf\n",polygon.RotatingCalipers());
	}

	return 0;
}
