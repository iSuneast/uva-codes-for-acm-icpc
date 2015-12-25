/*
10509 - R U Kidding Mr. Feynman?

math...
�����ҵ�ȷ�����...
��Ŀ������û��Ҫ����ô����...

(a+dx)^3=a^3 + 3*a^2*dx + 3*a*dx^2 + dx^3
		=a^3 + 3*a^2*dx
		=n
a=(int)pow(n,1/3)...ע�⸡�����
dx=(n-a^3)/(3*a^2)
���Ľ�Ϊa+dx
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
