/*
11062 - Andy's Second Dictionary

string...
Ad hoc..
just a simple sort problem...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<set>
#define MAXN 503
using namespace std;

string dic[MAXN],buf,pre;
int n;
set<string> s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	pre="";
	while(getline(cin,buf))
	{
		buf=pre+buf;
		pre="";

		int l=buf.length();
		if(!l)
			continue;

		for(int i=0;i<l;++i)
		{
			if(isalpha(buf[i]))
				buf[i]=tolower(buf[i]);
			else if(buf[i]!='-')
					buf[i]=' ';
		}
		if(buf[l-1]=='-')
			buf[l-1]='$';

		stringstream sin(buf);
		while(sin>>dic[n])
		{
			if(dic[n][ dic[n].length()-1 ]=='$')
				pre=dic[n].substr(0,dic[n].length()-1);
			else if(s.find(dic[n])==s.end())
				s.insert(dic[n++]);
		}
	}

	sort(dic,dic+n);
	for(int i=0;i<n;++i)
		cout<<dic[i]<<endl;

	return 0;
}
