/*
10104 - Euclid Problem

��,���ǲ�����ȫ.��Ϊ��WA��...
û�뵽...
���Եó�һ�����۾���
��չŷ����ö���ó��Ľ�abs(x)+abs(y)����С��.
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
