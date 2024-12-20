/*
10948 - The primary problem

number theory...
筛出素数
枚举cur=[n/2,n]间的素数即可
令t=n-cur,二分在素数表里面查找t,找到则有解
*/

#include<iostream>
#include<algorithm>
#define MAXN 1000000
using namespace std;

int prime[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cnt=0;
	memset(prime,0,sizeof(prime));
	prime[cnt++]=2;
	for(int i=3;i<=MAXN;i+=2)
		if(prime[i]==0)
		{
			prime[cnt++]=i;
			for(int j=i+i;j<=MAXN;j+=i)
				prime[j]=1;
		}
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d:\n",n);
		int up=upper_bound(prime,prime+cnt,n)-prime-1;
		while(true)
		{
			int cur=prime[up--];
			if(cur<n/2)
			{
				puts("NO WAY!");
				break;
			}
			int t=n-cur;
			int p=lower_bound(prime,prime+cnt,t)-prime;
			if(prime[p]==t)
			{
				printf("%d+%d\n",t,cur);
				break;
			}
		}
	}

	return 0;
}
