/*
10921 - Find the Telephone
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	string num;
	map<char,int> m;
	m['A']=2;
	m['B']=2;
	m['C']=2;

	m['D']=3;
	m['E']=3;
	m['F']=3;

	m['G']=4;
	m['H']=4;
	m['I']=4;

	m['J']=5;
	m['K']=5;
	m['L']=5;

	m['M']=6;
	m['N']=6;
	m['O']=6;

	m['P']=7;
	m['Q']=7;
	m['R']=7;
	m['S']=7;

	m['T']=8;
	m['U']=8;
	m['V']=8;

	m['W']=9;
	m['X']=9;
	m['Y']=9;
	m['Z']=9;
	while(getline(cin,num))
	{
		string::iterator sit=num.begin();
		while(sit!=num.end())
		{
			if(isalpha(*sit))
				cout<<m[*sit++];
			else
				cout<<*sit++;
		}
		cout<<endl;
	}

return 0;
}
