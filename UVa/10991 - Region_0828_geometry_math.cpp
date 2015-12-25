/*
10991 - Region

geometry...
simple math...
we know that the three circle is tangency with each other
then we get a triangle with r1+r2,r1+r3,r2+r3 as its three edge
calc the triangle's square
also we get three sector...
the degree is th ,we know cos(th)=(a^2+b^2-c^2)/2ab
the square of the sector is pi*r^2*th/(2pi)=th*r^2/2

the final answer is clear now :)
*/

#include<iostream>
#include<cmath>
#define sqr(a) (a*a)
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	double r1,r2,r3,s1,s2;
	const double pi=acos(-1.0);
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		s1=sqrt( (r1+r2+r3)*r1*r2*r3 );

		double a=r1+r2,b=r2+r3,c=r1+r3;
		double th1=acos( (sqr(a)+sqr(b)-sqr(c))/(2.0*a*b) );
		double th2=acos( (sqr(a)+sqr(c)-sqr(b))/(2.0*a*c) );
		double th3=acos( (sqr(c)+sqr(b)-sqr(a))/(2.0*c*b) );
		
		printf("%.6lf\n",s1-th1*sqr(r2)/2.0-th2*sqr(r1)/2.0-th3*sqr(r3)/2.0);
	}

	return 0;
}
