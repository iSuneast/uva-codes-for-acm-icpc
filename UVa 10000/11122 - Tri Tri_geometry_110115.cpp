/*
 * 11122 - Tri Tri
 * 
 * geometry...
 * a problem with so many trickys...
 * I make a complex code to get ac...
 * 
 * happy coding...
 */

#include<cstdio>
#include<iostream>
#include<cmath>
#define MAXN 4
using namespace std;
const double eps=1e-9;

struct TRI
{
	struct POINT
	{
		double x,y;
		
		bool operator!=(const POINT &t)const
		{
			return x!=t.x || y!=t.y;
		}
	}p[MAXN];
	
	double cross(const POINT &a,const POINT &b,const POINT &c)
	{
		return (c.y-a.y)*(b.x-a.x) - (c.x-a.x)*(b.y-a.y);
	}
	
	bool dif(const double &a,const double &b)
	{
		return fabs(a)>eps && fabs(b)>eps && a*b<0;
	}
	
	bool intersect(const POINT &sa,const POINT &sb,const POINT &ea,const POINT &eb)
	{
		return  max(sa.x,sb.x)>min(ea.x, eb.x) && 
				max(sa.y,sb.y)>min(ea.y, eb.y) && 
				min(sa.x,sb.x)<max(ea.x, eb.x) && 
				min(sa.y,sb.y)<max(ea.y, eb.y) && 
				dif( cross(sa,ea,eb), cross(sb,ea,eb)) &&
				dif( cross(ea,sa,sb), cross(eb,sa,sb));
	}
	
	bool inside(const TRI &t)
	{
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
				if(intersect(p[i], p[(i+1)%3], t.p[j], t.p[(j+1)%3]))
					return true;
		}
		
		double s=fabs( cross(t.p[0], t.p[1], t.p[2]) );
		for(int i=0;i<MAXN;++i)
		{
			double s1=fabs( cross(p[i], t.p[0], t.p[1]) );
			double s2=fabs( cross(p[i], t.p[1], t.p[2]) );
			double s3=fabs( cross(p[i], t.p[2], t.p[0]) );
			if(s1>eps && s2>eps && s3>eps && fabs(s1+s2+s3-s)<eps)
				return true;
		}
		
		for(int i=0;i<MAXN;++i)
		{
			for(int j=0;j<MAXN;++j)
			{
				double s=fabs( cross(p[i], t.p[j], t.p[(j+1)%3]) );
				if(s<eps && p[i]!=t.p[j] && p[i]!=t.p[(j+1)%3])
				{
					if(p[i].x<=max(t.p[j].x, t.p[(j+1)%3].x) && p[i].x>=min(t.p[j].x, t.p[(j+1)%3].x) &&
					   p[i].y<=max(t.p[j].y, t.p[(j+1)%3].y) && p[i].y>=min(t.p[j].y, t.p[(j+1)%3].y) )
					if( dif(cross(p[(i+1)%3], t.p[j], t.p[(j+1)%3]) , cross(p[(i+2)%3], t.p[j], t.p[(j+1)%3]) ) )
						return true;
				}
			}
		}
		
		return false;
	}
	
	void read()
	{
		for(int i=0;i<3;++i)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		p[3].x=( (p[0].x+p[1].x)/2.0+p[2].x ) /2.0;
		p[3].y=( (p[0].y+p[1].y)/2.0+p[2].y ) /2.0;
	}
}a,b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	a.read();
    	b.read();
    	printf("pair %d: %s\n", cas, ( a.inside(b)||b.inside(a) )?"yes":"no");
    }

    return 0;
}

