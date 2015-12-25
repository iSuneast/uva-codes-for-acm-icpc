/*
579 - ClockHands
...
汗...
还WA了...一次...
*/

#include<iostream>

using namespace std;

int main()
{
	double h,m,ans;
	while(scanf("%lf:%lf",&h,&m)&&(h!=0||m!=0))
	{
		h=h*30+m/2;
		m*=6;
		if(h>m)
			ans=h-m;
		else
			ans=m-h;
		if(ans>180)
			printf("%.3lf\n",360-ans);
		else
			printf("%.3lf\n",ans);
	}

return 0;
}
