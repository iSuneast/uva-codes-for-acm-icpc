/*
10197 - Learning Portuguese

string...
好恶心的输出啊...
竟然要用ASCII,不然就wa...
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	string a,b;
	char c=243;
	bool first=true;
	while(cin>>a>>b)
	{
		if(!first)
			cout<<endl;
		first=false;
		cout<<a<<" (to "<<b<<")"<<endl;
		int l=a.length();
		if(l==1)
		{
			cout<<"Unknown conjugation"<<endl;
			continue;
		}

		string sufix=a.substr(l-2,2),root=a.substr(0,l-2);

		if(sufix=="ar")
		{
			cout<<"eu        "<<root<<"o"<<endl;
			cout<<"tu        "<<root<<"as"<<endl;
			cout<<"ele/ela   "<<root<<"a"<<endl;
			cout<<"n"<<c<<"s       "<<root<<"amos"<<endl;
			cout<<"v"<<c<<"s       "<<root<<"ais"<<endl;
			cout<<"eles/elas "<<root<<"am"<<endl;
		}
		else if(sufix=="er")
		{
			cout<<"eu        "<<root<<"o"<<endl;
			cout<<"tu        "<<root<<"es"<<endl;
			cout<<"ele/ela   "<<root<<"e"<<endl;
			cout<<"n"<<c<<"s       "<<root<<"emos"<<endl;
			cout<<"v"<<c<<"s       "<<root<<"eis"<<endl;
			cout<<"eles/elas "<<root<<"em"<<endl;
		}
		else if(sufix=="ir")
		{
			cout<<"eu        "<<root<<"o"<<endl;
			cout<<"tu        "<<root<<"es"<<endl;
			cout<<"ele/ela   "<<root<<"e"<<endl;
			cout<<"n"<<c<<"s       "<<root<<"imos"<<endl;
			cout<<"v"<<c<<"s       "<<root<<"is"<<endl;
			cout<<"eles/elas "<<root<<"em"<<endl;
		}
		else
			cout<<"Unknown conjugation"<<endl;
	}

	return 0;
}
