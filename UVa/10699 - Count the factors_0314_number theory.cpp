/*
10699 - Count the factors
*/

#include<iostream>
#define MAXN 1000001
using namespace std;

int prime[MAXN],cnt=0;
void init()
{
	memset(prime,1,sizeof(prime));
	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
		if(prime[i])
		{
			prime[cnt++]=i;
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]=0;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	int n,key;
	while(cin>>n && n)
	{
		cout<<n<<" : ";
		key=0;
		for(int i=0;i<cnt;i++)
		{
			if(n%prime[i]==0)
			{
				while(n%prime[i]==0)
					n/=prime[i];
				key++;
			}
		}
		cout<<key<<endl;
	}

return 0;
}
