/*
591 - Box of Bricks
*/

#include<iostream>

using namespace std;

int main()
{
	int cas=1,avg,ans,i,n,h[60];
	while(cin>>n&&n)
	{
		avg=ans=0;
		for(i=0;i<n;i++)
			cin>>h[i],avg+=h[i];
		avg/=n;
		for(i=0;i<n;i++)
			ans+=abs(avg-h[i]);
		cout<<"Set #"<<cas++<<endl;
		cout<<"The minimum number of moves is "<<ans/2<<'.'<<endl<<endl;
	}

return 0;
}