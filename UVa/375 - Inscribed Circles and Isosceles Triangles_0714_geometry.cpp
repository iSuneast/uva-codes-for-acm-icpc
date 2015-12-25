/*
375 - Inscribed Circles and Isosceles Triangles

geometry...
���㼸�εľ��ȿ�������...

ֻҪ������Ŀ����˼ģ��Ϳ�����...
*/

#include<iostream>
#include<cmath>
#define pi (acos(-1.0))
#define eps 1e-6
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		double b,h;
		scanf("%lf%lf",&b,&h);
		double key=0.0;
		while(true)
		{
			double k=b/sqrt(4.0*h*h+b*b);
			double r=k*h/(1+k);
			if(r<eps)
				break;
			key+=2.0*pi*r;
			double t=h;
			h-=2.0*r;
			b*=h/t;
		}
		printf("%13.6lf\n",key);
		if(dataset)
			putchar('\n');
	}

	return 0;
}

