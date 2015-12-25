/*
11388 - GCD LCM

number theory
*/

#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,a,b,c;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		c=gcd(a,b);
		if(a==c)
			cout<<a<<' '<<b<<endl;
		else
			cout<<-1<<endl;
	}

return 0;
}
