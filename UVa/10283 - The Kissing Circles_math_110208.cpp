/*
 * 10283 - The Kissing Circles
 *
 * math...
 * 数学题,推推公式就好了
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

	const double pi = acos(-1.0);
	double R;
	int n;
	while (scanf("%lf%d", &R, &n) != EOF)
	{
		double tot = pi * pow(R, 2.0);

		if (n == 1)
		{
			printf("%.10lf %.10lf %.10lf\n", R, 0.0, 0.0);
			continue;
		}
		else if (n == 2)
		{
			double r = R / 2.0;
			double in = 0;
			double out = tot - 2.0*pi*pow(r, 2.0);
			printf("%.10lf %.10lf %.10lf\n", r, in, out);
			continue;
		}

		double arc = 2.0 * pi / n;
		double th = (pi - arc) / 2.0;
		double r = (R * sin(arc / 2.0)) / (1 + sin(arc / 2.0));

		double poly = n * pow(R - r, 2.0) * sin(arc) / 2.0;
		double more = n * th * pow(r, 2.0);
		double cir_area = n * pi * pow(r, 2.0);

		double in = poly - more;
		double out = tot - in - cir_area;

		printf("%.10lf %.10lf %.10lf\n", r, in, out);
	}

	return 0;
}
