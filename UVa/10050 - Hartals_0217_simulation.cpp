/*
10050 - Hartals
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int dataset,n,p,i,j,day[4000],ans;
	cin>>dataset;
	while(dataset--)
	{
		memset(day,0,sizeof(day));
		cin>>n>>p;
		while(p--)
		{
			cin>>i;
			j=i;ans=0;
			while(j<=n)
			{
				day[j]=1;
				j+=i;
			}
		}
		for(i=1;i<=n;i++)
			if(i%7!=6 && i%7!=0)
				ans+=day[i];
		cout<<ans<<endl;
	}

return 0;
}
