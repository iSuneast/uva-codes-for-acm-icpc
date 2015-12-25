/*
743 - The MTM Machine

simulation...
backtracking...

just use a dfs function to simulate the operation...

dfs( 33289 )
	dfs(  3289 )
		dfs(   289 )
		return 89
	return 89+2+89 = 89289
return 89289+2+89289 = 89289289289
*/

#include<iostream>
#include<string>
using namespace std;

bool fade;
string str;

string dfs(string s)
{
	if(fade)
		return "";
	if(s[0]=='3')
	{
		string buf=dfs(s.substr(1,s.length()-1));
		return buf+"2"+buf;
	}
	else if(s[0]=='2')
	{
		if(s.length()>1)
			return s.substr(1,s.length()-1);
		fade=true;
		return "";
	}
	fade=true;
	return "";
}

string process()
{
	for(int i=0;i<str.length();++i)
	{
		if(str[i]=='0')
			return "NOT ACCEPTABLE";
	}
	fade=false;
	str=dfs(str);

	if(fade)
		return "NOT ACCEPTABLE";
	return str;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(cin>>str && str!="0")
	{
		cout<<process()<<endl;
	}

	return 0;
}
