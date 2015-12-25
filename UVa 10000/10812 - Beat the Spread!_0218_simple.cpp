/*
10812 - Beat the Spread!
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,s,d;
	cin>>cas;
	while(cas--)
	{
		cin>>s>>d;
		if(s<d || (s+d)%2)
			cout<<"impossible"<<endl;
		else
			cout<<(s+d)/2<<' '<<(s-d)/2<<endl;;
	}

return 0;
}
