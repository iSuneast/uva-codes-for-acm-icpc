/*
10286 - Trouble with a Pentagon

geometry...
考虑两种情况
	@正方形顶点可以到达底边
	@正方形左右顶点到达五边形的相邻边
第二种是正确的解为l*sin(108)/sin(63)
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#define pi (2*acos(0.0))
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long double l;
	while(cin>>l)
		cout<<showpoint<<fixed<<setprecision(10)
			<<l*sin(108.0/180.0*pi)/sin(63.0/180.0*pi)<<endl;


	return 0;
}
