/*
10474 - Where is the Marble?
*/

#include<iostream>
#include<algorithm>

using namespace std;

int mar[10000];

int cmp(const int a,const int b)
{
	return a<b;
}

int main()
{
	int n,q,i,t,j,flag,cas=1;
	while(cin>>n>>q&&(q||n))
	{
		for(i=0;i<n;i++)
			cin>>mar[i];
		cout<<"CASE# "<<cas<<":"<<endl;
		cas++;
		sort(mar,mar+n,cmp);
		for(i=0;i<q;i++)
		{
			flag=1;
			cin>>t;
			for(j=0;j<n;j++)
				if(mar[j]==t)
				{
					cout<<t<<" found at "<<j+1<<endl;
					flag=0;
					break;
				}
			if(flag)
				cout<<t<<" not found"<<endl;
		}
	}

return 0;
}
