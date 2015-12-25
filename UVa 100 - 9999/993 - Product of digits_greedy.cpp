/*
993 - Product of digits
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,dataset,key[10],i;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n;
		if(n<10)
		{
			cout<<n<<endl;
			continue;
		}
		memset(key,0,sizeof(key));
		for(i=9;i>1;i--)
		{
			while(n!=1 && n%i==0)
				n/=i,key[i]++;
			if(n==1)
				break;
		}
		if(n==1)
		{
			for(i=2;i<10;i++)
				while(key[i]--)
					cout<<i;
			cout<<endl;
		}
		else
			cout<<-1<<endl;
	}

return 0;
}
