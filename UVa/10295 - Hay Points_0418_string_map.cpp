/*
10295 - Hay Points

string...
直接用map搞定...
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m,i,v,key;
	map<string,int> msi;
	string s;
	cin>>n>>m;
	for(i=0;i<n;++i)
	{
		cin>>s>>v;
		msi[s]=v;
	}
	while(m--)
	{
		key=0;
		while(cin>>s && s!=".")
			if(msi.find(s)!=msi.end())
				key+=msi[s];
		cout<<key<<endl;
	}

	return 0;
}
