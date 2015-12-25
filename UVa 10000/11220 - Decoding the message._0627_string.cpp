/*
11220 - Decoding the message.

string...
水题...
继续水...
*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	string s;

	cin>>dataset;	getline(cin,s);	getline(cin,s);
	for(int cas=1;cas<=dataset;++cas)
	{
		cout<<"Case #"<<cas<<":"<<endl;
		while(getline(cin,s) && s!="")
		{
			stringstream sin(s);
			int p=0;
			string key="",buf;
			while(sin>>buf)
			{
				if(buf.length()>p)
					key+=buf[p++];
			}
			cout<<key<<endl;
		}
		if(cas!=dataset)
			cout<<endl;
	}

	return 0;
}
