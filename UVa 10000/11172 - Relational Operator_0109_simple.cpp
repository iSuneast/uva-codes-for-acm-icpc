/*
11172 - Relational Operator
*/

#include<iostream>

using namespace std;

int main()
{
	long a,b,t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<b)
			cout<<'<'<<endl;
		if(a>b)
			cout<<'>'<<endl;
		if(a==b)
			cout<<'='<<endl;
	}

return 0;
}