/*
10347 - Medians

geometry...
������ws�ķ�������...

��֪�����ε����ĵ���������ľ���...
��ԭ�����ε����...
��֪,�������߹��ɵ������ε������ԭ�����ε����һ�����������..
������sample�����ݽ�һ�·��̾Ϳ�����...
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
