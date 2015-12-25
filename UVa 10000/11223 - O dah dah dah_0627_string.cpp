/*
11223 - O: dah dah dah!

string...
用map暴力映射...
手工打表,贴到手酸...
还好一Y,不然真的会死人的...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<map>
using namespace std;

map<string,char> msc;

void init()
{
	msc[".-"]='A';
	msc["-..."]='B';
	msc["-.-."]='C';
	msc["-.."]='D';
	msc["."]='E';
	msc["..-."]='F';
	msc["--."]='G';
	msc["...."]='H';
	msc[".."]='I';

	msc[".---"]='J';
	msc["-.-"]='K';
	msc[".-.."]='L';
	msc["--"]='M';
	msc["-."]='N';
	msc["---"]='O';
	msc[".--."]='P';
	msc["--.-"]='Q';
	msc[".-."]='R';

	msc["..."]='S';
	msc["-"]='T';
	msc["..-"]='U';
	msc["...-"]='V';
	msc[".--"]='W';
	msc["-..-"]='X';
	msc["-.--"]='Y';
	msc["--.."]='Z';
	msc["-----"]='0';

	msc[".----"]='1';
	msc["..---"]='2';
	msc["...--"]='3';
	msc["....-"]='4';
	msc["....."]='5';
	msc["-...."]='6';
	msc["--..."]='7';
	msc["---.."]='8';
	msc["----."]='9';

	msc[".-.-.-"]='.';
	msc["--..--"]=',';
	msc["..--.."]='?';
	msc[".----."]='\'';
	msc["-.-.--"]='!';
	msc["-..-."]='/';
	msc["-.--."]='(';
	msc["-.--.-"]=')';
	msc[".-..."]='&';

	msc["---..."]=':';
	msc["-.-.-."]=';';
	msc["-...-"]='=';
	msc[".-.-."]='+';
	msc["-....-"]='-';
	msc["..--.-"]='_';
	msc[".-..-."]='"';
	msc[".--.-."]='@';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	string s;
	cin>>dataset;	getline(cin,s);
	for(int cas=1;cas<=dataset;++cas)
	{
		cout<<"Message #"<<cas<<endl;

		getline(cin,s);
		string key="",buf;

		stringstream sin(s);
		while(sin>>buf)
			key+=msc[buf];

		int l=s.length(),p=0;
		for(int i=0;i<l;++i)
		{
			if(s[i]==' ')
				cout<<" ";
			else
			{
				while(i<l && s[i]!=' ')
					++i;
				cout<<key[p++];
			}
		}

		cout<<endl;
		if(cas!=dataset)
			cout<<endl;
	}

	return 0;
}
