/*
10193 - All You Need Is Love

GCD...
好水的水题啊...
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

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		char buf[32],*p;
		cin>>buf;
		p=buf;
		int a=0,b=0;
		while(*p)
			a=((*p++)-'0')+(a<<1);
		cin>>buf;
		p=buf;
		while(*p)
			b=((*p++)-'0')+(b<<1);
		if(gcd(a,b)!=1)
			cout<<"Pair #"<<cas<<": All you need is love!"<<endl;
		else
			cout<<"Pair #"<<cas<<": Love is not all you need!"<<endl;
	}

	return 0;
}
