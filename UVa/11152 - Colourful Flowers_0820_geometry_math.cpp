/*
11152 - Colourful Flowers

geometry...
math...
���ƹ�ʽ����һ�¸�����ѧ...
���Լ��Ƴ����Ĺ�ʽ�������..

a,b,cΪ���������߳�
���������
x=(a+b+c)/2
tri=sqrt( x*(x-a)*(x-b)*(x-c) )
���������Բ�뾶
R^2=(abc)^2 / ( -a^4-b^4-c^4 + 2( (ab)^2+(ac)^2+(bc)^2  )
����������Բ�뾶
(a+b+c)*r/2=tri
r=2*tri/(a+b+c)
*/

#include<iostream>
#include<cmath>
#define sqr(a)	((a)*(a))
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	double a,b,c;
	const double pi=acos(-1.0);
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		double s_R=pi*sqr(a)*sqr(b)*sqr(c)/
			( -( pow(a,4.0)+pow(b,4.0)+pow(c,4.0) ) 
			+ 2*( sqr(a)*sqr(b)+sqr(a)*sqr(c)+sqr(b)*sqr(c) ) );

		double x=(a+b+c)/2.0,tri=sqrt(x*(x-a)*(x-b)*(x-c));

		double s_r=pi*sqr(tri/x);

		printf("%.4lf %.4lf %.4lf\n",s_R-tri,tri-s_r,s_r);
	}

	return 0;
}
