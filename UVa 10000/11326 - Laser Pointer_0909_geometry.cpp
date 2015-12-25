/*
11326 - Laser Pointer

geometry...
try to expand the laster's path
so a=l/cos(th), reflex=l*tan(th)/w
@ if the light reflex odd time, b=sqrt(l^2 + (w-l*tan(th)%w)^2)
@ else b=sqrt(l^2 + (l*tan(th)%w)^2)
*/

#include<iostream>
#include<cmath>
using namespace std;
const double eps=1e-9;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	const double pi=acos(-1.0);
	double l,w,th;
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%lf%lf%lf",&l,&w,&th);
		th=th/180.0*pi;

		double a=l/cos(th),b,w2=l*tan(th);
		int k=static_cast<int>(floor(w2/w+eps));

		if(k&1)
			b=(k+1)*w-w2;
		else
			b=w2-k*w;

		b=sqrt(l*l+b*b);

		printf("%.3lf\n",a/b);
	}

	return 0;
}
