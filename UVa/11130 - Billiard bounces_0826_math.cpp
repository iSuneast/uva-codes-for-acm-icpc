/*
11130 - Billiard bounces

math...
calculate the total distance the ball run - dis
then calc the horizontal distance=dis*cos(A)+a/2
vertical distance=dis*sin(A)+b/2
the answer is clear now..
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	double a,b,v,A,s;
	const double pi=acos(-1.0);

	while(scanf("%lf%lf%lf%lf%lf",&a,&b,&v,&A,&s)!=EOF && (a||b||v||A||s))
	{
		double dis=v*s/2.0;
		A=A/180.0*pi;
		double horizontal=dis*cos(A)+a/2.0;
		double vertical=dis*sin(A)+b/2.0;

		printf("%d %d\n",(int)(horizontal/a),(int)(vertical/b));
	}

	return 0;
}
