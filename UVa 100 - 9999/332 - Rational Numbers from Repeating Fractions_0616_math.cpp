/*
332 - Rational Numbers from Repeating Fractions

math...
simulation...
注意一下n为0的情况就可以了...
不然的话会RE
*/

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,cas=1;
	string s;
	while(cin>>n && n!=-1)
	{
		cin>>s;
		int l=s.length();
		long long t,a,b=0;
		sscanf(s.substr(2,l-2).c_str(),"%lld",&a);

		if(!n)
			b=pow(10.0,l-2);
		else
		{
			if(l-2-n)
				sscanf(s.substr(2,l-2-n).c_str(),"%lld",&b);
			a-=b;
			b=pow(10.0,l-2)-pow(10.0,l-2-n);
		}

		t=gcd(a,b);
		cout<<"Case "<<cas++<<": "<<a/t<<"/"<<b/t<<endl;
	}

	return 0;
}
