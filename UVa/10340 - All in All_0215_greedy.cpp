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
				si++,ti++;		//����֮ǰû�м�ti++...Ҳ����˵..ͬһ���ַ�ֻ����һ��
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
