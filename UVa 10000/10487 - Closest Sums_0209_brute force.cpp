/*
10487 - Closest Sums
*/

#include<iostream>
#include<algorithm>

using namespace std;

int n,m,num[1010],sum[500600],p,t;

int locate()
{
	int i=0,t1,t2;
	while(i<p && sum[i]<t)
		i++;
	if(i==p)
		return sum[p-1];
	else if(sum[i]==t)
		return t;
	else if(!i)
		return sum[0];
	else
	{
		t1=t-sum[i-1];
		t2=sum[i]-t;
		return t1<t2?sum[i-1]:sum[i];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,cas=1,key;
	while(cin>>n&&n)
	{
		p=0;
		for(i=0;i<n;i++)
		{
			cin>>num[i];
			for(j=i;j;j--)
				sum[p++]=num[i]+num[j-1];
		}
		cin>>m;
		cout<<"Case "<<cas++<<":"<<endl;
		sort(sum,sum+p);

		while(m--)
		{
			cin>>t;
			cout<<"Closest sum to "<<t<<" is "
				<<locate()<<".\n";
		}
	}

return 0;
}
