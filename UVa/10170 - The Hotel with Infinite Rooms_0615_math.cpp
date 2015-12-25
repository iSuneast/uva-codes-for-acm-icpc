/*
10170 - The Hotel with Infinite Rooms

math...
��һ��s
�ڶ���s+1
....
��n��s+n-1
�����ܹ�������(s+s+n-1)*n/2>=d
s+n-1���ǽ�
n=[sqrt(4*s*s-4*s+1+8*d)-2*s+1]/2
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long s,d;
	while(cin>>s>>d)
		printf("%lld\n",s-1+(long long)ceil((sqrt(4*s*(s-1)+1.0+8*d)-2*s+1)/2.0) );

	return 0;
}
