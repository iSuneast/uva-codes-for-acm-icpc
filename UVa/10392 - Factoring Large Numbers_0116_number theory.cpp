/*
10392 - Factoring Large Numbers
*/

#include<iostream>

using namespace std;

int pri[1000010],i,j;

void init()
{
	memset(pri,1,sizeof(pri));
	for(i=2;i<1008;i++)
		for(j=i;i*j<1000010;j++)
			pri[i*j]=0;
	for(j=i=0;i<1000001;i++)
		if(pri[i])
			pri[j++]=i;
}

int main()
{
	long long n;
	init();
	while(cin>>n&&n>=0)
	{
		if(n==0)
			continue;
		i=2;
		while(n-1&&i<j)
			if(!(n%pri[i]))
				cout<<"    "<<pri[i]<<endl,n/=pri[i];
			else
				i++;
		if(n-1)
				cout<<"    "<<n<<endl;
		cout<<endl;
	}

return 0;
}