/*
11192 - Group Reverse

Ad hoc..
ˮ�Ⱑ...
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int group;
	while(cin>>group && group)
	{
		string s;
		cin>>s;
		int l=s.length(),n=l/group;
		for(int i=0;i<l;i+=n)
			for(int j=i+n-1;j>=i;--j)
				cout<<s[j];
		cout<<endl;
	}

	return 0;
}
