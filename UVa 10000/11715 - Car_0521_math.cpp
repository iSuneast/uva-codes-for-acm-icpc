/*
11715 - Car

math...
没有任何特殊情况...
直接推出公式即可...
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1,data;
	double a,b,c;
	while(scanf("%d",&data) && data)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		switch(data)
		{
		case 1:
			printf("Case %d: %.3lf %.3lf\n",cas++,(a+b)*c/2,(b-a)/c);break;
		case 2:
			printf("Case %d: %.3lf %.3lf\n",cas++,(b*b-a*a)/2/c,(b-a)/c);break;
		case 3:
			printf("Case %d: %.3lf %.3lf\n",cas++,sqrt(2*b*c+a*a),(sqrt(2*b*c+a*a)-a)/b);break;
		case 4:
			printf("Case %d: %.3lf %.3lf\n",cas++,sqrt(a*a-2*b*c),(a-sqrt(a*a-2*b*c))/b);break;
		}
	}

	return 0;
}
