/*
583 - Prime Factors
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,flag;
	while(cin>>n && n)
	{
		cout<<n<<" = ";
		if(n<0)
			cout<<"-1 x ",
			n=-n;
		flag=0;
		int i=2;
		while(n%i==0)
			{
				if(flag)
					cout<<" x ";
				cout<<i;
				n/=i;
				flag=1;
			}

		for(i=3;i<=sqrt(n)+1;)
			if(n%i==0)
			{
				if(flag)
					cout<<" x ";
				cout<<i;
				n/=i;
				flag=1;
			}
			else
				i+=2;
		if(n>1)
		{
			if(flag)
				cout<<" x ";
			cout<<n;
		}
		cout<<endl;
	}

return 0;
}
