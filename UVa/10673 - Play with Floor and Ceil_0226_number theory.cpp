/*
10673 - Play with Floor and Ceil
*/

#include<iostream>
#include<cmath>

using namespace std;

/*
下面的gcd是扩展欧几里得算法...
d为a,b的最大公约数...
x,y为ax+by=d的解.
所以方程ax+by=c最终的解应该为x*c/d,y*c/d
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
