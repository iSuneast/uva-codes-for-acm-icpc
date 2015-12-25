/*
378 - Intersecting Lines

Geometry...
额,做完一遍果然收获又是很大...
考虑问题就是要全面一点才行...
*/

#include<iostream>
#include<cmath>
#define eps 1e-9
using namespace std;

struct point
{
	double x1,x2,y1,y2;
}pnt[2];

void judge()
{
	double dx1=pnt[0].x1-pnt[0].x2;
	double dy1=pnt[0].y1-pnt[0].y2;
	double dx2=pnt[1].x1-pnt[1].x2;
	double dy2=pnt[1].y1-pnt[1].y2;
	if(dx2*dy1==dx1*dy2)
	{
		dx1=pnt[0].x1-pnt[1].x2;
		dy1=pnt[0].y1-pnt[1].y2;
		dx2=pnt[1].x1-pnt[0].x2;
		dy2=pnt[1].y1-pnt[0].y2;
		if(dx2*dy1==dx1*dy2)
			cout<<"LINE"<<endl;
		else
			cout<<"NONE"<<endl;
		return ;
	}
	printf("POINT ");
	if(fabs(dx1)<eps)
	{
		double k2=dy2/dx2;
		double b2=-k2*pnt[1].x1+pnt[1].y1;
		printf("%.2lf %.2lf\n",pnt[0].x1,k2*pnt[0].x1+b2);
	}
	else if(fabs(dx2)<eps)
	{
		double k1=dy1/dx1;
		double b1=-k1*pnt[0].x1+pnt[0].y1;
		printf("%.2lf %.2lf\n",pnt[1].x1,k1*pnt[1].x1+b1);
	}
	else
	{
		double k1=dy1/dx1;
		double b1=-k1*pnt[0].x1+pnt[0].y1;
		double k2=dy2/dx2;
		double b2=-k2*pnt[1].x1+pnt[1].y1;
		double x=(b2-b1)/(k1-k2);
		printf("%.2lf %.2lf\n",x,k1*x+b1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while(dataset--)
	{
		for(int i=0;i<2;++i)
			cin>>pnt[i].x1>>pnt[i].y1>>pnt[i].x2>>pnt[i].y2;
		judge();
	}
	cout<<"END OF OUTPUT"<<endl;

	return 0;
}
