/*
11054 - Wine trading in Gergovia
*/

#include<iostream>

using namespace std;

long long work,a[100010];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,n,ps,pb;
	while(cin>>n && n)
	{
		ps=pb=work=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		while(ps!=n && pb!=n)
		{
			while(ps!=n && a[ps]>=0)
				ps++;
			while(pb!=n && a[pb]<=0)
				pb++;
			if(-a[ps]>a[pb])
				work+=a[pb]*abs(pb-ps),
				a[ps]+=a[pb],a[pb]=0;
			else
				work-=a[ps]*abs(pb-ps),
				a[pb]+=a[ps],a[ps]=0;
		}
		cout<<work<<endl;
	}
	

return 0;
}
