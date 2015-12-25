/*
10170 - The Hotel with Infinite Rooms

math...
第一天s
第二天s+1
....
第n天s+n-1
所以总共经过了(s+s+n-1)*n/2>=d
s+n-1就是解
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
