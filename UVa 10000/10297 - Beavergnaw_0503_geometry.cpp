/*
10297 - Beavergnaw

geometry...
竟然把公式推错了...
BS...
圆柱的体积=底面积*高...
*/

#include<iostream>
#include<cmath>
#define pi acos(-1.0)
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif 

	double d,v;
	while(scanf("%lf %lf",&d,&v)!=EOF && (d||v))
		printf("%.3lf\n",pow(d*d*d-6.0*v/pi,1.0/3.0));

	return 0;
}
