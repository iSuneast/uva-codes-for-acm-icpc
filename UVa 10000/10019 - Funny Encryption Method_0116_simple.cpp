/*
10019 - Funny Encryption Method
*/

#include<iostream>

using namespace std;

int num(int t)
{
	int res=0;
	while(t)
	{
		if(t%2)
			res++,t=(t-1)/2;
		else
			t/=2;
	}
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	int cas,n,b1,b2;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		b1=num(n);
		b2=0;
		while(n)
			b2+=num(n%10),n/=10;
		cout<<b1<<' '<<b2<<endl;
	}

return 0;
}