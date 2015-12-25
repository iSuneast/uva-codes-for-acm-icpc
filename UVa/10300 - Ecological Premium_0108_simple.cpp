/*
10300 - Ecological Premium
*/

#include<iostream>

using namespace std;

int main()
{
	int n,f,a,b,c,res,i;
	cin>>n;
	while(n--)
	{
		res=0;
		cin>>f;
		for(i=0;i<f;i++)
		{
			cin>>a>>b>>c;
			res+=a*c;
		}
		cout<<res<<endl;
	}

return 0;
}