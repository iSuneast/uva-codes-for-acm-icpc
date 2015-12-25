/*
10387 - Billiard

geometry...
无语...
我之前本来还打算模拟一下的= =

由贪心策略可知
分别碰墙n,m次后停止即可
然后可以发现,水平方向和竖直方向的运动是独立的
所以水平方向的移动就是a*m,竖直b*n
运动速度sqrt(a*m^2+b*n^2)/s
角度显然就是atan2(b*n,a*m)
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int a,b,s;
	double m,n;
	const double pi=acos(-1.0);

	while(scanf("%d%d%d%lf%lf",&a,&b,&s,&m,&n)!=EOF && (a||b||s||m||n))
	{
		double l=sqrt(a*a*m*m+b*b*n*n);
		double angle=atan2(b*n,a*m)*180.0/pi;
		if(angle<0)
			angle=-angle;
		if(angle>90.0)
			angle=180.0-angle;
		printf("%.2lf %.2lf\n",angle,l/s);
	}

	return 0;
}
