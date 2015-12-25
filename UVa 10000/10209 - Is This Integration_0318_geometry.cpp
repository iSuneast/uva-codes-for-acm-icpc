/*
10209 - Is This Integration ?
*/

#include<iostream>
#include<cmath>
#define pi 2.0*acos(0.0)
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	double r,s1,s2,s3;
	while(cin>>r)
	{
		s3=r*r*(4-sqrt(3)-pi*2.0/3.0);
		s2=r*r*(4-pi)-s3*2.0;
		s1=r*r-s2-s3;
		printf("%.3lf %.3lf %.3lf\n",s1,s2,s3);
	}

return 0;
}
