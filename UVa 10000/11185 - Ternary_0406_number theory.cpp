/*
11185 - Ternary

simple number theory.
传说中的进制转换...
*/

#include<iostream>
#include<string>
#define MOD 3
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	long n;
	while(cin>>n && n>=0)
	{
		if(!n)
		{
			cout<<0<<endl;
			continue;
		}
		string ans="",null="";
		while(n)
		{
			ans=null+(char)(n%3+'0')+ans;
			n/=3;
		}
		cout<<ans<<endl;
	}

	return 0;
}
