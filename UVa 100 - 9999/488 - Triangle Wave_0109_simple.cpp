/*
488 - Triangle Wave

simple
*/

#include<iostream>

using namespace std;
int t,h,f,i,j,k;

void wave()
{
	for(i=1;i<=h;i++)
	{
		for(j=0;j<i;j++)
			cout<<i;
		cout<<endl;
	}
	for(i=h-1;i>0;i--)
	{
		for(j=0;j<i;j++)
			cout<<i;
		cout<<endl;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	
	cin>>t;
	while(t--)
	{
		cin>>h>>f;
		for(k=0;k<f;k++)
		{
			wave();
			if(t==0&&k==f-1)
				break;
			cout<<endl;
		}
	}

return 0;
}