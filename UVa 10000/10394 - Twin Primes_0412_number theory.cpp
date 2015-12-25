/*
10394 - Twin Primes

number theory...
«ø±©¡¶À„∑®...
2.3sAC...
*/

#include<iostream>
#define MAXN 20000000
using namespace std;

int pos[100000],prime[MAXN];

void init()
{
	int i,j,p=1;
	prime[1]=-1;
	for(i=3;i<MAXN;i+=2)
		if(prime[i]==0)
		{
			if(prime[i-2]==0)
				pos[p++]=i-2;
			for(j=i+i;j<MAXN;j+=i)
				prime[j]=-1;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	int n;
	while(cin>>n)
		cout<<"("<<pos[n]<<", "<<pos[n]+2<<")"<<endl;

	return 0;
}
