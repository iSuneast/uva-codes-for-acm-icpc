/*
10168 - Summation of Four Primes

number theory...
*/

#include<iostream>
#define MAXN 10000010
using namespace std;
int prime[MAXN],key[4],cnt;

bool calc(int n)
{
	if(n<8)
		return false;
	if(n==8)
	{
		cout<<"2 2 2 2"<<endl;
		return true;
	}
	key[0]=2;
	key[1]=2;
	n-=4;
	if(n%2)
		++key[1],--n;

	if(prime[n-2]==0)
	{
		cout<<key[0]<<' '<<key[1]<<' '<<2<<' '<<n-2<<endl;
		return true;
	}
	for(int i=3;i<=(n>>1);i+=2)
		if(prime[i]==0 && prime[n-i]==0)
		{
			cout<<key[0]<<' '<<key[1]<<' '<<i<<' '<<n-i<<endl;
			return true;
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	
	int i,j;
	prime[0]=prime[1]=-1;
	for(i=3;i<MAXN;i+=2)
	{
		prime[i+1]=-1;
		if(!prime[i])
			for(j=i+i;j<MAXN;j+=i)
				prime[j]=-1;
	}
	int n;
	while(cin>>n)
		if(!calc(n))
			cout<<"Impossible."<<endl;

	return 0;
}
