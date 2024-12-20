/*
11343 - Isolated Segments

geometry...
ACM生涯的第一道模板题...
WA了好多次...
依旧是低级错误...
*/

#include<iostream>
#include<cmath>
#define MAXN 110
#define EPS 1e-9
using namespace std;

struct TPoint { double x, y; };

int m;
bool flag[MAXN];
TPoint pnt[2][MAXN];

double cross(const TPoint & a, const TPoint & b, const TPoint & c)
{ return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

int sign(double d)
{
	if(fabs(d) < EPS) return 0;
	return (d > 0) ? 1 : -1;
}

int xycmp(double p, double mint, double maxt)
{ return sign(p - mint) * sign(p - maxt); }

int betweenCmp(TPoint & c, TPoint & a, TPoint & b)
{
	if(fabs(a.x - b.x) > fabs(a.y - b.y))
		return xycmp(c.x, min(a.x, b.x), max(a.x, b.x));
	return xycmp(c.y, min(a.y, b.y), max(a.y, b.y));
}

int seg_inter(TPoint & a, TPoint & b, TPoint & c, TPoint & d)
{
	double s1, s2, s3, s4;
	int d1, d2, d3, d4;
	d1 = sign(s1 = cross(a, b, c));
	d2 = sign(s2 = cross(a, b, d));
	d3 = sign(s3 = cross(c, d, a));
	d4 = sign(s4 = cross(c, d, b));
	if((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
		return true;
	if((d1 == 0 && betweenCmp(c, a, b) <= 0) ||
		(d2 == 0 && betweenCmp(d, a, b) <= 0) ||
		(d3 == 0 && betweenCmp(a, c, d) <= 0) ||
		(d4 == 0 && betweenCmp(b, c, d) <= 0))
		return true;
	return false;
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
		scanf("%d",&m);
		memset(flag,0,sizeof(flag));
		for(int i=0;i<m;++i)
		{
			scanf("%lf%lf%lf%lf",&pnt[0][i].x,&pnt[0][i].y,&pnt[1][i].x,&pnt[1][i].y);
			for(int j=0;j<i;++j)
			{
				if(seg_inter(pnt[0][i],pnt[1][i],pnt[0][j],pnt[1][j]))
					flag[i]=flag[j]=true;	//找到了不能break,要继续找.
			}
		}
		int key=0;
		for(int i=0;i<m;++i)
		{
			if(!flag[i])
				++key;
		}
		printf("%d\n",key);
	}

	return 0;
}
