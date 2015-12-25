/*
10372 - Leaps Tall Buildings (in a single bound)

math...

try to work out the format, then just verify it...
don't worry about accurate error...

Parabola function f(x)=a*x^2+b*x+c
the point (0,0),(dis,0) is in the line,
so we got c=0,b=-dis*a
we know the highest point is (x,h)=( -b/(2a), (4ac-b^2)/(4a) )
h = (4ac-b^2)/(4a) = -b^2/(4a)

binary search "a" is a good idea.
then check whether every point (x,y) is lie in the Parabola

set g = 9.8 m/s^2
we have format list below:
@ Vx*t = dis
@ Vy*t = h
@ Vy - g*t/2 = 0

the total time we spend is t=sqrt(8.0*y/g)
also, we will easy got the final answer
th=atan( t*t*g/(2.0*d[n]) )
v=g*t/(2.0*sin(th))
*/

#include<iostream>
#include<cmath>
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

double h[MAXN],d[MAXN];
int n;
const double g=9.8;
const double pi=acos(-1.0);

bool ok(double a)
{
	double b=d[n]*(-1.0)*a;
	for(int i=1;i<n;++i)
	{
		double y=d[i]*(d[i]*a+b);
		if(y<h[i] || y<h[i+1])
			return false;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		h[0]=d[0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%lf%lf",&h[i],&d[i]);
			d[i]+=d[i-1];
		}

		double bgn=-INF,end=0,a,b;
		while(fabs(bgn-end)>=eps)
		{
			a=(bgn+end)/2.0;
			if(ok(a))
				bgn=a+eps;
			else
				end=a-eps;
		}

		a=end;
		b=d[n]*(-1.0)*a;

		double x=-b/(2.0*a);
		double y=-b*b/(4.0*a);

		double t=sqrt(8.0*y/g);
		double th=atan( t*t*g/(2.0*d[n]) );
		double v=g*t/(2.0*sin(th));

		printf("%.2lf %.2lf\n",th*180.0/pi,v);
	}

	return 0;
}
