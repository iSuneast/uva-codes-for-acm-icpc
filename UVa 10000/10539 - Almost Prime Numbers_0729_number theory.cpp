/*
10539 - Almost Prime Numbers

number theory...
筛出素数后,正解自然就是prime^n (n>=2)
注意判断溢出...
如果prime^n/prime==prime^(n-1),则没有溢出
最后对所有的解排序后
二分查找,输出区间大小即可.
*/

#include<iostream>
#include<algorithm>
#define MAXN 1000003
using namespace std;

int prime[MAXN],tot;
const long long bound=1000000000000LL;
long long almost[MAXN/10];

void init()
{
	int i,cnt=0;
	prime[ cnt++ ]=2;
	for(i=3;i<MAXN;i+=2)
		if(prime[i]==0)
		{
			prime[ cnt++ ]=i;
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]=1;
		}

	for(i=0;i<cnt;++i)
	{
		long long n,t,k=prime[i];
		t=k;
		n=t*k;
		while(n/k==t && n<bound)
		{
			almost[tot++]=n;
			t=n;
			n=t*k;
		}
	}

	sort(almost,almost+tot);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	long long low,high;
	scanf("%d",&dataset);
	while(dataset--)
	{
		cin>>low>>high;
		int p1=lower_bound(almost,almost+tot,low)-almost;

		int p2=lower_bound(almost,almost+tot,high)-almost;
		if(almost[p2]==high)
			++p2;

		printf("%d\n",p2-p1);
	}


	return 0;
}
