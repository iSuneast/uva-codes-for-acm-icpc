/*
10509 - R U Kidding Mr. Feynman?

math...
看来我的确想多了...
题目根本就没有要求那么复杂...

(a+dx)^3=a^3 + 3*a^2*dx + 3*a*dx^2 + dx^3
		=a^3 + 3*a^2*dx
		=n
a=(int)pow(n,1/3)...注意浮点误差
dx=(n-a^3)/(3*a^2)
最后的解为a+dx
*/

#include<iostream>
#include<cmath>
#define eps 1e-9
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double n;
	while(scanf("%lf",&n)!=EOF && fabs(n-0)>eps)
	{
		double a=floor(pow(n,1.0/3.0)+eps);

		if(fabs(a*a*a-n)<eps)
		{
			printf("%.4lf\n",a);
			continue;
		}

		printf("%.4lf\n",a+(n-a*a*a)/(3*a*a) );
	}

	return 0;
}
