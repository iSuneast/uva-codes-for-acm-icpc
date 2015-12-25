/*
11233 - Deli Deli
*/

#include<iostream>
#include<set>
#include<string>
#include<map>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int l,n;
	set<char> s;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
	while(cin>>l>>n)
	{
		int i,j;
		map<string,string> m;
		string buf1,buf2;
		for(i=0;i<l;i++)
		{
			cin>>buf1>>buf2;
			m[buf1]=buf2;
		}
		for(i=0;i<n;i++)
		{
			cin>>buf1;
			if(m.find(buf1)!=m.end())
				cout<<m[buf1]<<endl;
			else
			{
				int l=buf1.length();
				if(buf1[l-1]=='y')
				{
					if(l>1 && s.find(buf1[l-2])==s.end())
						cout<<buf1.substr(0,l-1)<<"ies"<<endl;
					else
						cout<<buf1<<"s"<<endl;
				}
				else if(buf1[l-1]=='o' || buf1[l-1]=='s' || buf1[l-1]=='x' 
						|| (buf1[l-1]=='h' && (buf1[l-2]=='c' || buf1[l-2]=='s')))
						cout<<buf1<<"es"<<endl;
				else
					cout<<buf1<<"s"<<endl;
			}
		}
	}


return 0;
}
