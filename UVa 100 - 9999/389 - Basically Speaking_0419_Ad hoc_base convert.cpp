/*
389 - Basically Speaking

Ad hoc...
base convert...
POJ的数据确实很弱的说...
竟然在那边水过了...
在UVa果然WA...
"0"没有考虑到...
*/

#include<iostream>
#include<string>
using namespace std;

string var;
int base1,base2;

int hash(char c)
{
	if(isdigit(c))
		return c-'0';
	return c-'A'+10;
}

char convert(int n)
{
	if(n<10)
		return '0'+n;
	return n-10+'A';
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>var>>base1>>base2)
	{
		int i,l=var.length(),n=0;
		for(i=0;i<l;++i)
			n=n*base1+hash(var[i]);
		string ans="";
		if(!n)		//特殊情况
		{
			puts("      0");
			continue;
		}
		while(n)
		{
			ans=convert(n%base2)+ans;
			n/=base2;
		}
		l=ans.length();
		if(l>7)
			cout<<"  ERROR"<<endl;
		else
		{
			for(i=0;i<7-l;++i)
				putchar(' ');
			cout<<ans<<endl;
		}
	}

	return 0;
}
