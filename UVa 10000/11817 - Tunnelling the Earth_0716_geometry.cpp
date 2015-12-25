/*
11817 - Tunnelling the Earth

geometry...
计算几何...
直接转化为三维空间直角坐标兮来解答即可...
*/

#include<iostream>
#include<cmath>
#define r 6371009.0
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

struct POINT
{
	double x,y,z;
}a,b;

const double pi=acos(-1.0);

POINT transform(double la,double lo)
{
	la*=pi/180.0;
	lo*=pi/180.0;
	POINT key;
	key.x=r*cos(la)*cos(lo);
	key.y=r*cos(la)*sin(lo);
	key.z=r*sin(la);
	return key;
}

double dist(double x,double y,double z)
{
	return sqrt(x*x+y*y+z*z);
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
		double la,lo;
		scanf("%lf%lf",&la,&lo);
		a=transform(la,lo);
		scanf("%lf%lf",&la,&lo);
		b=transform(la,lo);

		double dis=dist(a.x-b.x,a.y-b.y,a.z-b.z);
		double rad=acos( 1-dis*dis/r/r/2.0 );
		double d=r*rad-dis;

		if( fabs(d-floor(d))>fabs(ceil(d)-d) )
			printf("%.0lf\n",ceil(d));
		else
			printf("%.0lf\n",floor(d));
	}

	return 0;
}
