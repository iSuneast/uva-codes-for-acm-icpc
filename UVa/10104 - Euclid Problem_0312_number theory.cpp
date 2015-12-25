/*
10104 - Euclid Problem

晕,考虑不够周全.以为会WA的...
没想到...
所以得出一个结论就是
扩展欧几里得定理得出的解abs(x)+abs(y)是最小的.
*/

#include<iostream>
using namespace std;

void gcd(long long a,long long b,long long &d,long long &x,long long &y)
{
	if(!b)
	{	d=a;	x=1;	y=0;	}
	else
	{	gcd(b,a%b,d,y,x);	y-=x*(a/b);	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	long long a,b,d,x,y;
	while(cin>>a>>b)
	{
		gcd(a,b,d,x,y);
		cout<<x<<' '<<y<<' '<<d<<endl;
	}

return 0;
}
