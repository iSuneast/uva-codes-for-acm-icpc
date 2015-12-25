/*
10424 - Love Calculator
*/

#include<iostream>
#include<string>
using namespace std;

int hash(string s)
{
	int key=0;
	for(int i=0;i<s.length();i++)
		if(isalpha(s[i]))
			key+=tolower(s[i])-'a'+1;
	return key;
}

void calc(int &n)
{
	while(n>=10)	//n>=10 not n>10...a small bug,but really matters.
	{
		int t=n;
		n=0;
		while(t)
		{
			n+=t%10;
			t/=10;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	string name1,name2;
	while(getline(cin,name1) && getline(cin,name2))
	{
		int var1=hash(name1);
		int var2=hash(name2);
		calc(var1);
		calc(var2);
		if(var1>var2)
			swap(var1,var2);
		printf("%.2lf %%\n",var1*100.00/var2);
	}

return 0;
}
