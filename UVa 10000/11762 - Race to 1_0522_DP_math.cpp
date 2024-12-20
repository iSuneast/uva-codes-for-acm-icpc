/*
11762 - Race to 1

math...
DP...
概率论的DP题...
令table[i]为第i个素数
prime[i]为i的素因子个数,则每次选到正确的素因子的概率是1/prime[i]
p为<=i的素数个数
则key[i]=(key[i]+p)/prime[i]
对于i的所有table[j]做一次背包即可求出所有解
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

int prime[MAXN],table[MAXN];
double key[MAXN];

void init()
{
	int cnt=0;
	for(int i=2;i<MAXN;++i)		//筛法
	{
		if(prime[i]==0)
		{
			table[cnt++]=i;
			for(int j=i;j<MAXN;j+=i)
				++prime[j];
		}
	}
	int p=0;
	for(int i=2;i<MAXN;++i)
	{
		while(p<cnt && table[p]<=i)
			++p;
		key[i]=(key[i]+p)/prime[i];
		for(int j=0;table[j]*i<MAXN;++j)	//对i的素数倍背包
			key[ table[j]*i ]+=key[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	init();
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		printf("Case %d: %.6lf\n",cas,key[n]);
	}

	return 0;
}
