/*
343 - What Base Is This?

Ad hoc...
进制转换问题...
想想也对...
最小的进制应该是2...
我真的不知道1进制除了表示0,还能表示什么...
*/

#include<iostream>
#include<string>
using namespace std;

string n1,n2;

int hash(char c)
{
	if(isdigit(c))
		return c-'0';
	return c-'A'+10;
}

int convert(string s,int base)
{
	int l=s.length(),key=0;
	for(int i=0;i<l;++i)
		key=key*base+hash(s[i]);
	return key;
}

int minbase(string s)
{
	int l=s.length(),base=0;
	for(int i=0;i<l;++i)
		base=base>hash(s[i])?base:hash(s[i]);
	return base?base+1:2;
}

void process()
{
	int base1,base2;
	for(base1=minbase(n1);base1<=36;++base1)
		for(base2=minbase(n2);base2<=36;++base2)
			if(convert(n1,base1)==convert(n2,base2))
			{
				cout<<n1<<" (base "<<base1<<") = "<<n2<<" (base "<<base2<<")"<<endl;
				return ;
			}
	cout<<n1<<" is not equal to "<<n2<<" in any base 2..36"<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n1>>n2)
		process();

	return 0;
}
