/*
10673 - Play with Floor and Ceil
*/

#include<iostream>
#include<cmath>

using namespace std;

/*
�����gcd����չŷ������㷨...
dΪa,b�����Լ��...
x,yΪax+by=d�Ľ�.
���Է���ax+by=c���յĽ�Ӧ��Ϊx*c/d,y*c/d
*/

void gcd(int a,int b,int &d,int &x,int &y)
{
	if(!b)
	{
		d=a;
		x=1;
		y=0;
	}
	else
	{
		gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int p,q,x,k,d,cas;
	cin>>cas;
	while(cas--)
	{
		cin>>x>>k;
		gcd(floor(((double)x)/k),ceil(((double)x)/k),d,p,q);
		cout<<p*x/d<<' '<<q*x/d<<endl;
	}

return 0;
}
