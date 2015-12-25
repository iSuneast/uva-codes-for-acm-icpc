/*
10678 - The Grazing Cow

math...
其实就是求椭圆的面积...
l=2*a
c=2*d
b=sqrt(l*l-d*d)/2
s=pi*a*b...
*/

#include<iostream>
#include<cmath>
#define pi 2*acos(0.0)
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);

	while(dataset--)
	{
		double d,l;
		scanf("%lf%lf",&d,&l);
		printf("%.3lf\n",pi*sqrt(l*l-d*d)/2.0*l/2.0);
	}

	return 0;
}
