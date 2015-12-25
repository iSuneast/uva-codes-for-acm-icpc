/*
492 - Pig-Latin
*/

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	string s;
	while(getline(cin,s))
	{
		string::iterator siter=s.begin();
		while(siter!=s.end())
		{
			if(isalpha(*siter))
			{
				switch(*siter)
				{
				case 'A':case 'E':case 'I':case 'O':case 'U':
				case 'a':case 'e':case 'i':case 'o':case 'u':
					do
					cout<<*siter++;
					while(siter!=s.end() && isalpha(*siter));
					cout<<"ay";
					break;
				default:
					char t=*siter++;
					while(siter!=s.end() && isalpha(*siter))
						cout<<*siter++;
					cout<<t<<"ay";
				}
			}
			while(siter!=s.end() && !isalpha(*siter))
				cout<<*siter++;
		}
		cout<<endl;
	}

return 0;
}
