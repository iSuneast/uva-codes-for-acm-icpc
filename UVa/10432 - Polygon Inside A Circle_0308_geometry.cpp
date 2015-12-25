/*
10432 - Polygon Inside A Circle
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	double r,n;		//晕,以后没事不要用long double...
	while(cin>>r>>n)
		printf("%.3lf\n",sin(acos(-1.0)*2.0/n)*r*r*n*0.5);

return 0;
}
