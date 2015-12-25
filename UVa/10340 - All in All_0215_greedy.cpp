/*
10340 - All in All
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	string s,t;
	while(cin>>s>>t)
	{
		string::iterator si=s.begin(),ti=t.begin();
		while(si!=s.end() && ti!=t.end())
		{
			while(ti!=t.end() && (*ti!=*si))
				ti++;
			if(*ti == *si)
				si++,ti++;		//这里之前没有加ti++...也就是说..同一个字符只能算一遍
			else
				break;
		}
		if(si!=s.end())
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}

return 0;
}
