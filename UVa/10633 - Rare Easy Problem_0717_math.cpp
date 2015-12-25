/*
10633 - Rare Easy Problem

math...
正如题目所说...
任意n>=10可以表示为n=10*a+b
m=n/10=a
n-m=9*a+b
算出a,b代回去即可...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long n;
	while(cin>>n && n)
	{
		if(n==9)
		{
			cout<<10<<endl;
			continue;
		}
		long long a=n/9;
		long long b=n%9;
		if(b==0)
			cout<<10*a-1<<" "<<10*a<<endl;
		else
			cout<<10*a+b<<endl;
	}

	return 0;
}
