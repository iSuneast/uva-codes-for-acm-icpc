/*
 * 10287 - Gifts in a Hexagonal Box
 *
 * math...
 * ���ƹ�ʽ�ͺ�
 * r1 = X*sqrt(3)/2
 * r2 = x/( 1 + sqrt(3)*2/3 )
 * r3 = r1/2
 * r4 ��Ƚϲ��ù۲�, ��֪,�����ĸ�Բ�ĺ�,�õ�һ������,�߳�2r
 *  �������ζԽ���,���ӳ�����ཻ
 *  ��ʱ,�������α��ֳ��ĸ�ֱ��������
 *  б��, �����α߳� c = 2r
 *  �϶̵ĶԽ��߳� a = sqrt(3)*X - 2r
 *  �ϳ��ĶԽ��߳� b = 2*X - 2r/( sqrt(3)/2 )
 *  �� (a/2)^2 + (b/2)^2 = c^2
 *  �ⷽ��, �ɵ�
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
