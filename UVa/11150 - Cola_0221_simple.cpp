/*
11150 - Cola
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,ans;
	while(cin>>n)
	{
		ans=n;
		while(n!=2 && n!=1)
		{
			ans+=n/3;
			n=n/3+n%3;
		}
		if(n==2)
			ans++;
		cout<<ans<<endl;
	}

return 0;
}
