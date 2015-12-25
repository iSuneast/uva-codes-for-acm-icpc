/*
10299 - Relatives

number theory...
欧拉公式...
强大啊...

注意一下n==1的时候解为0即可
如果经过素数筛选n>1,则此时的n为大素数
必须更新解.
*/

#include<iostream>
#define MAXN 31625
using namespace std;

int prime[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int tot=0;
	prime[tot++]=2;
	for(int i=3;i<MAXN;i+=2)
		if(prime[i]!=-1)
		{
			prime[tot++]=i;
			for(int j=i<<1;j<MAXN;j+=i)
				prime[j]=-1;
		}

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(n==1)
		{
			puts("0");
			continue;
		}

		int ans=n;
		int p=0;
		while(p<tot && n>1)
		{
			if(n%prime[p]==0)
			{
				ans=ans-ans/prime[p];
				while(n%prime[p]==0)
					n/=prime[p];
			}
			++p;
		}
		if(n>1)
			ans=ans-ans/n;

		printf("%d\n",ans);
	}

	return 0;
}
