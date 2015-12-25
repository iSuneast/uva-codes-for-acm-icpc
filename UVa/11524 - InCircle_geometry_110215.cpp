/*
 * 11524 - InCircle
 *
 * geometry...
 * �����İ뾶����ʵ�ģ��߳�ֻ�Ǳ�������
 * ��֪  m1=n3, n1=m2, n2=m3
 * ���Ǽٶ�m1, n1������ȷ���ȣ����ͨ���򵥵ı�����������е������߶��������ȷ����
 * �� M1=k*m1Ϊ��ʵ���ȣ���
 *    A=M1+N1=k*(m1+n1) = k*a
 *    B=M2+N2=k*(m2+n2) = k*b
 *    C=M3+N3=k*(m3+n3) = k*c
 * ����abc�����s = r*(a+b+c)/2 = ���׹�ʽ(a,b,c)
 *    ����ͨ�����׹�ʽ���r
 * ����ABC����Ϊ��������������R = k*r
 *   ���S = R*(A+B+C)/2 = k*r * k*(a+b+c) = k^2 * s
 * ���ԣ�S = k^2 * s = s* R^2 / r^2
 *
 * happy coding~
 */

#include<iostream>
#include<cmath>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	double r , len[3];
	pair<double,double> pnt[3];

	scanf("%d", &dataset);
	while(dataset--) {
		scanf("%lf", &r);
		for(int i=0; i<3; ++i) {
			scanf("%lf %lf", &pnt[i].first, &pnt[i].second);
		}

		pnt[1].second = pnt[0].second * pnt[1].second/pnt[1].first;
		pnt[1].first = pnt[0].second;

		pnt[2].first = pnt[0].first * pnt[2].first/pnt[2].second;
		pnt[2].second = pnt[0].first;

		double s=0;
		for(int i=0; i<3; ++i) {
			len[i] = pnt[i].first + pnt[i].second;
			s += len[i];
		}
		double p = s/2.0;
		double key = sqrt( p*(p-len[0])*(p-len[1])*(p-len[2]) );

		double _r = key * 2.0 /s;
		key = key * pow(r,2.0) / pow(_r, 2.0);
		printf("%.4lf\n", key);
	}

	return 0;
}
