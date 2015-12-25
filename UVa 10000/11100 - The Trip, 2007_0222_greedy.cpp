/*
11100 - The Trip, 2007
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i,j,k,t,flag=0;
	int num[10010];
	while(cin>>n && n)
	{
		if(flag)
			cout<<endl;
		flag=1;
		for(i=0;i<n;i++)
			cin>>num[i];
		sort(num,num+n);
		t=k=1;
		for(i=1;i<n;i++)
			if(num[i]==num[i-1])
				t++;
			else if(t>k)
				k=t,t=1;
			else
				t=1;
		if(t>k)
			k=t;
		cout<<k<<endl;
		for(i=0;i<k;i++)
		{
			cout<<num[i];
			for(j=i+k;j<n;j+=k)
				cout<<' '<<num[j];
			cout<<endl;
		}
	}

return 0;
}
