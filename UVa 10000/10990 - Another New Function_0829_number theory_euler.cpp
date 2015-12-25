/*
10990 - Another New Function

number theory...
sieve...
O(NlogN) time to calc the euler function...
almost the same as the prime sieve...
*/

#include<iostream>
#define MAXN 2000001
using namespace std;

int phi[MAXN],depth[MAXN],sodf[MAXN];
bool sieved[MAXN];

bool prime(int var)
{
	if(var==2)
		return true;
	return var%2 && !sieved[var];
}

void init()
{
	sieved[0]=sieved[1]=true;
	for(int i=3;i<MAXN;i+=2)
	{
		if(!sieved[i])
			for(int j=i+i;j<MAXN;j+=i)
				sieved[j]=true;
	}

	for(int i=2;i<MAXN;++i)
	{
		phi[i]=i;
		sodf[i]=0;
	}
	
	for(int i=2;i<MAXN;++i)
	{
		if(prime(i))
			for(int j=i;j<MAXN;j+=i)
				phi[j]=phi[j]/i*(i-1);
		depth[i]=depth[ phi[i] ]+1;
		sodf[i]=sodf[i-1]+depth[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	int dataset,m,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",sodf[n]-sodf[m-1]);
	}

	return 0;
}
