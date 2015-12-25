/*
10566 - Crossed Ladders

divide and conquer...
二分w即可...
可以推得
1/sqrt(x^2-w^2)+1/sqrt(y^2-w^2)=1/c
二分w的初始值为min(x,y)
*/

#include<iostream>
#include<cmath>
#define eps 1e-6
using namespace std;

double x,y,c;

double dist(double a,double b)
{
	return sqrt(a*a-b*b);
}

double b_located()
{
	double begin=0,end=min(x,y),mid;
	while(fabs(begin-end)>eps)
	{
		mid=(begin+end)/2;
		double key=1.0/( 1.0/dist(x,mid) + 1.0/dist(y,mid) );
		if(key>c)
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

	while(scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
		printf("%.3lf\n",b_located());

	return 0;
}
