/*
10286 - Trouble with a Pentagon

geometry...
�����������
	@�����ζ�����Ե���ױ�
	@���������Ҷ��㵽������ε����ڱ�
�ڶ�������ȷ�Ľ�Ϊl*sin(108)/sin(63)
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
