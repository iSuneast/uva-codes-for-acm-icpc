/*
11044 - Searching for Nessy
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		n=(int)ceil((n-2.0)/3.0);
		m=(int)ceil((m-2.0)/3.0);
		cout<<n*m<<endl;
	}

return 0;
}