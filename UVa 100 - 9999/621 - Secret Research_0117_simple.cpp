/*
621 - Secret Research
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int cas,l;

	cin>>cas;getchar();

	while(cas--)
	{
		getline(cin,s);
		l=s.length();

		if((s=="1")||(s=="4")||(s=="78"))
			cout<<'+'<<endl;
		else if((s[l-1]=='5')&&(s[l-2]=='3'))
			cout<<'-'<<endl;
		else if((s[0]=='9')&&s[l-1]=='4')
			cout<<'*'<<endl;
		else
			cout<<'?'<<endl;
	}

return 0;
}