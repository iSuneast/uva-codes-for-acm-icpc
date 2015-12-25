/*
355 - The Bases Are Loaded

number base conversion...
竟然被卡住了...orz...
*/

#include<iostream>
#include<string>
using namespace std;
int base1,base2,l;
string var;

int hash(char c)
{
	if(isdigit(c))
		return c-'0';
	return c-'A'+10;
}

char anti_hash(int n)
{
	if(n<10)
		return n+'0';
	return n-10+'A';
}

void convert()
{
	long long ans=0;
	string key="";
	for(int i=0;i<l;++i)
		ans=ans*base1+hash(var[i]);
	if(!ans)
	{
		cout<<var<<" base "<<base1<<" = "<<0<<" base "<<base2<<endl;
		return ;
	}
	while(ans)
	{
		key=anti_hash(ans%base2)+key;
		ans/=base2;
	}
	cout<<var<<" base "<<base1<<" = "<<key<<" base "<<base2<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>base1>>base2>>var)
	{
		l=var.length();
		bool error=false;
		for(int i=0;i<l;++i)
			if(base1<=hash(var[i]))		//带个等号...
			{
				error=true;
				break;
			}
		if(error)
			cout<<var<<" is an illegal base "<<base1<<" number"<<endl;
		else
			convert();
	}

	return 0;
}
