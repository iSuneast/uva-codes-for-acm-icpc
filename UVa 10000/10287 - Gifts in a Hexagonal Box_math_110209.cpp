/*
 * 10287 - Gifts in a Hexagonal Box
 *
 * math...
 * 推推公式就好
 * r1 = X*sqrt(3)/2
 * r2 = x/( 1 + sqrt(3)*2/3 )
 * r3 = r1/2
 * r4 会比较不好观察, 可知,连接四个圆心后,得到一个菱形,边长2r
 *  连接菱形对角线,并延长与边相交
 *  此时,发现菱形被分成四个直角三角形
 *  斜边, 即菱形边长 c = 2r
 *  较短的对角线长 a = sqrt(3)*X - 2r
 *  较长的对角线长 b = 2*X - 2r/( sqrt(3)/2 )
 *  则 (a/2)^2 + (b/2)^2 = c^2
 *  解方程, 可得
 * r4 =  x *( 6*sqrt(7)-7*sqrt(3) ) / 10
 *
 * happy coding~
 */

#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	const double sqrt3=sqrt(3.0);
	for(double x; scanf("%lf",&x)!=EOF; )
	{
		double r1 = sqrt3*x/2.0;
		double r2 = x/(1 + sqrt3*2/3.0);
		double r3 = r1/2.0;
		double r4 = x * ( (6*sqrt(7.0)-7*sqrt3)/10.0 );
		printf("%.10lf %.10lf %.10lf %.10lf\n", r1, r2, r3, r4);
	}

	return 0;
}
