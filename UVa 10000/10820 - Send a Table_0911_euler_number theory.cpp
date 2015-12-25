/*
10820 - Send a Table

number theory...
euler function...
just the prefix sum of euler function
*/

#include<iostream>
#define MAXN 50001
using namespace std;

int phi[MAXN],key[MAXN];
bool flag[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(flag,0,sizeof(flag));
	for(int i=1;i<MAXN;++i)
		phi[i]=i;
	key[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		if(!flag[i])
			for(int j=i;j<MAXN;j+=i)
			{
				flag[j]=true;
				phi[j]=phi[j]/i*(i-1);
			}
			key[i]=key[i-1]+2*phi[i];
	}

	int n;
	while(scanf("%d",&n)!=EOF && n)
		printf("%d\n",key[n]);

	return 0;
}
