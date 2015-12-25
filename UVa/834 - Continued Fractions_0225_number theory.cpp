/*
834 - Continued Fractions
*/

#include<iostream>

using namespace std;

bool first;

void gcd(int a,int b)
{
	if(!b)
		return ;
	if(first)
		first=false;
	else
		cout<<',';
	cout<<a/b;
	gcd(b,a%b);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int a,b;
	while(cin>>a>>b)
	{
		first=true;
		cout<<"["<<a/b<<';';
		gcd(b,a%b);
		cout<<']'<<endl;
	}

return 0;
}
