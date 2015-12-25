/*
10491 - Cows and Cars

math...
概率论...
有两种情况
	@先选的是cow,		p0=ncows/(ncows+ncars)
	 然后改变主意选car,	p1=ncar/(ncars+ncows-nshow-1)
	 这种情况选到car的p_1=p0*p1
	@先选的是car				p2=ncars/(ncows+ncars)
	 改变主意,但是还是选car		p3=(ncars-1)/(ncars+ncows-nshow-1)
	 这种情况选到car的p_2=p2*p3
 于是最终解为p_1+p_2
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
