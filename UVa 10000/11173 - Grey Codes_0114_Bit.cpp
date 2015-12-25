/*
11173 - Grey Codes
*/

#include<iostream>

using namespace std;

int main()
{
	long t,n,k,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		n=1<<n;
		ans=0;
		while(n)
		{
			if(k>=n/2)
				k=n-1-k,ans|=n>>1;
			n/=2;
		}
		cout<<ans<<endl;
	}

return 0;
}
