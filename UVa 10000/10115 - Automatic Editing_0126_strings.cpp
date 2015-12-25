/*
10115 - Automatic Editing
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,cnt,i;
	string txt,rep[20],ori[20];
	string::size_type p;

	while(cin>>n&&n)
	{
		getchar();
		cnt=0;
		while(n--)
			getline(cin,ori[cnt]),getline(cin,rep[cnt++]);
		getline(cin,txt);
		for(i=0;i<cnt;i++)
			while((p=txt.find(ori[i]))<txt.length())
				txt.replace(p,ori[i].length(),rep[i]);
		cout<<txt<<endl;
	}

return 0;
}
