/*
10387 - Billiard

geometry...
����...
��֮ǰ����������ģ��һ�µ�= =

��̰�Ĳ��Կ�֪
�ֱ���ǽn,m�κ�ֹͣ����
Ȼ����Է���,ˮƽ�������ֱ������˶��Ƕ�����
����ˮƽ������ƶ�����a*m,��ֱb*n
�˶��ٶ�sqrt(a*m^2+b*n^2)/s
�Ƕ���Ȼ����atan2(b*n,a*m)
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int a,b,s;
	double m,n;
	const double pi=acos(-1.0);

	while(scanf("%d%d%d%lf%lf",&a,&b,&s,&m,&n)!=EOF && (a||b||s||m||n))
	{
		double l=sqrt(a*a*m*m+b*b*n*n);
		double angle=atan2(b*n,a*m)*180.0/pi;
		if(angle<0)
			angle=-angle;
		if(angle>90.0)
			angle=180.0-angle;
		printf("%.2lf %.2lf\n",angle,l/s);
	}

	return 0;
}
