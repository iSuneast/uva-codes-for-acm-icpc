/*
10738 - Riemann vs Mertens

number theory...
thieves...
其实就是筛法的增强版..
i是素数
如果能被i*i筛掉,则标记mu[]=0
否则++素因子个数
最后统计一下素因子个数为奇数或偶数即可...
*/

#include<iostream>
#define MAXN 1000003
using namespace std;

int mu[MAXN],MU[MAXN],n;
int prime[MAXN];

void init()
{
	memset(mu,0x3f,sizeof(mu));
	mu[1]=1;	MU[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		if(prime[i]==0)
		{
			mu[i]=-1;
			int t=i*i;
			if(t/i==i)
				for(int j=t;j<MAXN;j+=t)
					prime[j]=-1;
			for(int j=i+i;j<MAXN;j+=i)
				if(prime[j]!=-1)
					prime[j]++;
		}
		else if(prime[i]==-1)
			mu[i]=0;
		else if(prime[i]&1)
			mu[i]=-1;
		else
			mu[i]=1;

		MU[i]=MU[i-1]+mu[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(scanf("%d",&n)!=EOF && n)
		printf("%8d%8d%8d\n",n,mu[n],MU[n]);

	return 0;
}
