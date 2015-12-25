/*
10589 - Area

geometry...
simple math problem...
check the point is inside all the four circle is enough
*/

#include<iostream>
using namespace std;

bool inside(double x,double y,double a,double b,double r)
{
	double dx=x-a,dy=y-b;
	return dx*dx+dy*dy<=r*r;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	double x,y,a;
	while(scanf("%d%lf",&n,&a)!=EOF && n)
	{
		double m=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&x,&y);
			if( inside(x,y,0,0,a) && 
				inside(x,y,0,a,a) &&
				inside(x,y,a,a,a) &&
				inside(x,y,a,0,a) )
				m+=1;
		}

		printf("%.5lf\n",m*a*a/n);
	}

	return 0;
}
