/*
10346 - Peter's Smokes
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,ans;
	while(cin>>n>>k)
	{
		ans=n;
		while(n>=k)
		{
			ans+=n/k;
			n=n/k+n%k;
		}
		cout<<ans<<endl;
	}

return 0;
}
