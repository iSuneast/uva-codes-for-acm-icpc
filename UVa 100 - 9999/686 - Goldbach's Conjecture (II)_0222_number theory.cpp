/*
686 - Goldbach's Conjecture (II)
*/

#include<iostream>

using namespace std;

#define MAXN 32770

int prime[MAXN];

void init()
{
	memset(prime,1,sizeof(prime));
	for(int i=2;i<MAXN;i++)
		for(int j=i;i*j<MAXN;j++)
			prime[i*j]=0;	
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	int n;
	while(cin>>n && n)
	{
		if(n==4)
		{
			cout<<1<<endl;
			continue;
		}
		int cnt=0;
		for(int i=3;i<=n/2;i+=2)
			if(prime[i] && prime[n-i])
				cnt++;
		cout<<cnt<<endl;
	}

return 0;
}
