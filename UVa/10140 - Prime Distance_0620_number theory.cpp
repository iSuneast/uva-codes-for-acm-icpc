/*
10140 - Prime Distance

number theory...
区间素数筛法...
原理好像都差不多...
*/

#include<iostream>
#define MAXN 1000010
#define INF 0x7f7f7f7f
using namespace std;

int prime[MAXN],l,u;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&l,&u)!=EOF)
	{
		memset(prime,0,sizeof(prime));

		int d=u-l+1,tot=0,t;

		if(l==1)
			prime[0]=-1;
		for(unsigned int i=3;i*i<=u;i+=2)
			if(i<=l || prime[i-l]==0)
			{
				int j=l/i*i;
				if(j<l)
					j+=i;
				if(j==i)
					j+=i;
				j-=l;
				while(j<d)
				{
					prime[j]=-1;
					j+=i;
				}
			}

		if(2>=l)
			prime[tot++]=2;
		for(int i=0;i<d;++i)
			if(prime[i]==0 &&  (i+l)&1)
				prime[tot++]=i+l;

		int mini=INF,maxn=0,close,dist;

		for(int i=1;i<tot;++i)
		{
			t=prime[i]-prime[i-1];
			if(t<mini)
				mini=t,close=i;
			if(t>maxn)
				maxn=t,dist=i;
		}

		if(!maxn)
			puts("There are no adjacent primes.");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n",
			prime[close-1],prime[close],prime[dist-1],prime[dist]);
	}

	return 0;
}
