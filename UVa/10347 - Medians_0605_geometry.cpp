/*
10347 - Medians

geometry...
又是用ws的方法过的...

已知三角形的中心到各个顶点的距离...
求原三角形的面积...
易知,这三条边构成的三角形的面积和原三角形的面积一定是线性相关..
所以用sample的数据解一下方程就可以了...
= =
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
		if(a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a)
			puts("-1.000");
		else
		{
			double t=(a+b+c)/2;
			double s=sqrt(t*(t-a)*(t-b)*(t-c));
			printf("%.3lf\n",s*4.0/3.0);
		}

	return 0;
}
