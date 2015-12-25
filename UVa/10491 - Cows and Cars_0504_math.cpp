/*
10491 - Cows and Cars

math...
������...
���������
	@��ѡ����cow,		p0=ncows/(ncows+ncars)
	 Ȼ��ı�����ѡcar,	p1=ncar/(ncars+ncows-nshow-1)
	 �������ѡ��car��p_1=p0*p1
	@��ѡ����car				p2=ncars/(ncows+ncars)
	 �ı�����,���ǻ���ѡcar		p3=(ncars-1)/(ncars+ncows-nshow-1)
	 �������ѡ��car��p_2=p2*p3
 �������ս�Ϊp_1+p_2
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double ncows,ncars,nshow;
	while(scanf("%lf%lf%lf",&ncows,&ncars,&nshow)!=EOF)
	{
		double b1=ncows+ncars;
		double b2=ncars+ncows-nshow-1;
		double p1=ncows*ncars/b1/b2;
		double p2=ncars*(ncars-1)/b1/b2;
		printf("%.5lf\n",p1+p2);
	}

	return 0;
}
