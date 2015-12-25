/*
10215 - The Largest/Smallest Box ...

geometry...
计算几何的题...
果然是相当的nx...
精度问题好严重...
*/

#include<iostream>
#include<cmath>
#define eps 1e-7
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double w,l;
	while(scanf("%lf%lf",&w,&l)!=EOF)
		printf("%.3lf %.3lf %.3lf\n",
			((w+l)-sqrt(w*w-w*l+l*l))/6.0+eps,0.0,min(w,l)/2.0+eps);

	return 0;
}
