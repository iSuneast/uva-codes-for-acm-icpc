/*
10905 - Children's Game
...
ÎÒÌ«´ÏÃ÷ÁË....
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int cmp(const string a,const string b)
{
	return a+b>b+a;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i;
	string buf[60],ans;
	while(cin>>n&&n)
	{
		ans="";
		for(i=0;i<n;i++)
			cin>>buf[i];
		sort(buf,buf+n,cmp);
		for(i=0;i<n;i++)
			ans+=buf[i];
		cout<<ans<<endl;
	}

return 0;
}
