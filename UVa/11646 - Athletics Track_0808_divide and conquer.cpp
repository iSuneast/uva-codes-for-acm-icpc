/*
11646 - Athletics Track

divide and conquer...
二分k,即l=a*k,w=b*k..
则r=sqrt((a*k)^2+(b*k)^2)/2
arc=acos(1-(b*k)^2/(2*r^2))
perimeter=2*(arc*r+a*k)...

算周长的时候记得不要把b*k也算进去了...
*/

#include<iostream>
#include<cmath>
#define INF 0x3f3f3f3f
#define eps 1e-13
using namespace std;

double a,b;
const double PERI=400.0;

double b_located()
{
	double begin=0,end=INF,mid;
	double t=b*b/2.0,d=sqrt(a*a+b*b)/2.0;

	while(fabs(begin-end)>eps)
	{
		mid=(begin+end)/2.0;
		double r=d*mid;
		double arc=acos(1-t*mid/r*mid/r);
		double peri=(arc*r+a*mid)*2.0;

		if(peri<PERI)
			begin=mid+eps;
		else
			end=mid;
	}

	return begin;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%lf%*s%lf",&a,&b)!=EOF)
	{
		double k=b_located();
		printf("Case %d: %.10lf %.10lf\n",cas++,a*k,b*k);
	}

	return 0;
}
