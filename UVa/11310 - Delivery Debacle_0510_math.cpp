/*
11310 - Delivery Debacle

math...
有公式,退一下就出来了...
key[i]=key[i-1]+4*key[i-2]+2*key[i-3]
规律还是很明显的...
*/

#include<iostream>
#define MAXN 40
using namespace std;

long long key[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	key[1]=1;
	key[2]=5;
	key[3]=11;
	for(int i=4;i<=MAXN;++i)
		key[i]=key[i-1]+4*key[i-2]+2*key[i-3];
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",key[n]);
	}

	return 0;
}
