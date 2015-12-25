/*
10522 - Height to Area

geometry...
S=AC*Hb/2=AB*Hc/2=BC*Ha/2
AC=2S/Hb
AB=2S/Hc
BC=2S/Ha
then just use Heron's format to calc the area
*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int invalid;
	double a[3];
	scanf("%d",&invalid);
	while(invalid)
	{
		scanf("%lf%lf%lf",&a[0],&a[1],&a[2]);
		a[0]=1/a[0];	a[1]=1/a[1];	a[2]=1/a[2];
		sort(a,a+3);
		if(a[0]+a[1]<=a[2])
		{
			puts("These are invalid inputs!");
			--invalid;
		}
		else
		{
			double x=a[0]+a[1]+a[2];
			printf("%.3lf\n",sqrt( 1/( x*(x-2*a[0])*(x-2*a[1])*(x-2*a[2]) ) ));
		}
	}

	return 0;
}
