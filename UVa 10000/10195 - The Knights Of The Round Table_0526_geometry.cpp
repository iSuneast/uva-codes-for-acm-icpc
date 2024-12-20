/*
10195 - The Knights Of The Round Table

geometry...
计算几何...
很讨厌的精度问题...

求三角形面积
s=(a+b+c)*r/2=sqrt( p*(p-a)*(p-b)*(p-c) )
其中p=(a+b+c)/2
于是就可以很快地推出r的表达式了
r=sqrt( (p-a)*(p-b)*(p-c)/p )

要注意a,b,c为0的特殊情况
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		if(a==0.0 || b==0.0 || c==0.0)
		{
			printf("The radius of the round table is: 0.000\n");
			continue;
		}
		double p=(a+b+c)/2;
		double t=(p-a)*(p-b)*(p-c);
		printf("The radius of the round table is: %.3lf\n",sqrt(t/p));
	}

	return 0;
}
