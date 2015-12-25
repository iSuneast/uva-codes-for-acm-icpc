/*
10451 - Ancient Village Sports

math...
�ƹ�ʽ...
�뾶R=sqrt(2.0*area/n/sin(2*pi/n))
	r=R*cos(pi/n)
���spectator=pi*R*R-area
	official=area-pi*r*r
*/

#include<iostream>
#include<cmath>
#define pi (2*acos(0.0))
#define eps 1e-9
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double n,area;
	int cas=1;
	while(scanf("%lf",&n)!=EOF && n>=3.0)
	{
		scanf("%lf",&area);
		double r=sqrt(2.0*area/n/sin(2*pi/n));
		double spectator=pi*r*r-area;
		r*=cos(pi/n);
		double official=area-pi*r*r;
		printf("Case %d: %.5lf %.5lf\n",cas++,spectator,official);
	}

	return 0;
}
