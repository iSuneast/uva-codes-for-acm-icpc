/*
272 - TEX Quotes
..
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int flag=1,i;
	while(getline(cin,str))
	{
		for(i=0;i<str.length();i++)
			if(str[i]=='"')
			{
				if(flag)
					cout<<"``",flag=!flag;
				else
					cout<<"''",flag=!flag;
			}
			else
				cout<<str[i];
		cout<<endl;
	}

return 0;
}
