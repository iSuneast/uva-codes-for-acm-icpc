/*
11226 - Reaching the fix-point.

number theory...
直接打表即可
达标的时候要注意记忆化搜索...
*/

#include<iostream>
#define MAXN 500000
using namespace std;

int prime[MAXN+3],lsopf[MAXN+3];

int calc(int n)
{
	if(lsopf[n])
		return lsopf[n];
	else if(prime[n]==n)
		return 1;
	else
		return calc(prime[n])+1;
}

void init()
{
	memset(prime,0,sizeof(prime));
	for(int i=2;i<=MAXN;++i)
	{
		if(prime[i]==0)
		{
			prime[i]=i;
			for(int j=i+i;j<=MAXN;j+=i)
			{
				int t=j,cnt=0;
				while(t%i==0)
					t/=i,++cnt;
				prime[j]+=cnt*i;
			}
		}
		lsopf[i]=calc(i);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int a,b,key=0;
		scanf("%d%d",&a,&b);
		if(a>b)
			swap(a,b);
		for(int i=a;i<=b;++i)
			if(lsopf[i]>lsopf[key])
				key=i;
		printf("Case #%d:\n%d\n",cas,lsopf[key]);
	}

	return 0;
}
