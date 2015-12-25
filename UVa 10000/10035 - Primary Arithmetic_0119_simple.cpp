/*
10035 - Primary Arithmetic
...
竟然WA了两次....
而且还是传说中的简单题...
*/

#include<iostream>

using namespace std;

int main()
{
	long a,b,ans,t;
	while(cin>>a>>b&&(a||b))
	{
		ans=t=0;
		while(a||b)
		{
			t+=a%10+b%10;
			if(t/=10)
				ans++;
			a/=10;
			b/=10;
		}
		if(ans==1)
			cout<<"1 carry operation."<<endl;
		else if(ans)
			cout<<ans<<" carry operations."<<endl;
		else
			cout<<"No carry operation."<<endl;
	}

return 0;
}