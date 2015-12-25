/*
445 - Marvelous Mazes

simulation
*/

#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,len,l;
	string str;
	while(getline(cin,str))
	{
		len=str.length();
		if(str=="\n")
		{
			cout<<endl;
			continue;
		}
		for(i=0;i<len;i++)
			if(isdigit(str[i]))
			{
				l=str[i]-'0';
				i++;
				while(isdigit(str[i]))
					l+=str[i]-'0',i++;
				if(str[i]=='b')
					for(j=0;j<l;j++)
						cout<<' ';
				else
					for(j=0;j<l;j++)
						cout<<str[i];
			}
			else if(str[i]=='!')
					cout<<endl;
			else
				cout<<str[i];
		cout<<endl;
	}

return 0;
}