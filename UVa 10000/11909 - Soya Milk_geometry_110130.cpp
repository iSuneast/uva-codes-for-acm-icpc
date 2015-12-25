/*
11909 - Soya Milk

geometry...
有两种情况,用手画画就知道了
分开讨论即可~

happy coding~
*/

#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	double l,w,h,arc;
	const double pi=acos(-1.0);
	while(scanf("%lf%lf%lf%lf",&l,&w,&h,&arc)!=EOF)
	{
		double tot=l*w*h;
		double _arc=atan(h/l)/pi*180;
		double ans=0;

		if(_arc>arc)
			ans = tot - l*tan(arc/180*pi) * l * w /2.0;
		else
			ans = h/( tan(arc/180*pi) ) * h * w /2.0;

		printf("%.3lf mL\n",ans);
	}

	return 0;
}
