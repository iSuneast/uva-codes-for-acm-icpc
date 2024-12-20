/*
11505 - Logo

geometry...
simulation...
计算几何的题...
直接模拟即可...

要注意一点是bk时只是乌龟往后退.
他的方向没有改变..
*/

#include<iostream>
#include<cmath>
#define pi acos(-1.0)
using namespace std;

double x,y;
int degree,v,n;
char cmd[10];

void process()
{
	if(0<degree && degree<90)
	{
		x+=cos((degree+0.0)/360*2*pi)*v;
		y+=sin((degree+0.0)/360*2*pi)*v;
	}
	else if(90<degree && degree<180)
	{
		x+=cos((degree+0.0)/360*2*pi)*v;
		y+=sin((degree+0.0)/360*2*pi)*v;
	}
	else if(180<degree && degree<270)
	{
		x+=cos((degree+0.0)/360*2*pi)*v;
		y+=sin((degree+0.0)/360*2*pi)*v;
	}
	else if(270<degree && degree<360)
	{
		x+=cos((degree+0.0)/360*2*pi)*v;
		y+=sin((degree+0.0)/360*2*pi)*v;
	}
	else if(degree==0)
	{
		x+=v;
	}
	else if(degree==90)
	{
		y+=v;
	}
	else if(degree==180)
	{
		x-=v;
	}
	else if(degree==270)
	{
		y-=v;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("11505.txt","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		degree=0;
		x=0;	y=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s%d",cmd,&v);
			if(cmd[0]=='f')
			{
				process();
			}
			else if(cmd[0]=='b')
			{
				degree=(degree+180)%360;
				process();
				degree=(degree+180)%360;
			}
			else if(cmd[0]=='l')
			{
				degree=(degree+v)%360;
			}
			else if(cmd[0]=='r')
			{
				degree=(degree-v+360)%360;
			}
		}
		double t=sqrt(x*x+y*y+0.0);
		double up=ceil(t)-t,down=t-floor(t);
		if(up>down)
			printf("%.0lf\n",floor(t));
		else
			printf("%.0lf\n",ceil(t));
	}

	return 0;
}
