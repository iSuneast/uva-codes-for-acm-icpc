/*
11032 - Function Overloading

dp...
这种题暴力显然是不对的...
解与解之间有着很明显的O(1)的映射关系
只要算出所有可能的解即可

初始化key[]数组为-1
	令t=i+sod(i)
	key[t]=i
然后对dp[]有key[i]==-1时,++cnt
	dp[i]=cnt
最后O(1)的询问即可
*/

#include<iostream>
#define MAXN 10000000
using namespace std;

int key[MAXN+3],dp[MAXN+3];

int sod(int var)
{
	int key=0;
	while(var)
	{
		key+=var%10;
		var/=10;
	}
	return key;
}

void init()
{
	memset(key,-1,sizeof(key));
	for(int i=1;i<=MAXN;++i)
	{
		int t=i+sod(i);
		if(key[t]==-1 && t<=MAXN)
			key[t]=i;
	}
	int cnt=0;
	for(int i=1;i<=MAXN;++i)
		if(key[i]==-1)
			dp[i]=++cnt;
		else
			dp[i]=cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset,a,b;
	char buf[30];
	scanf("%d",&dataset);

	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&a);
		gets(buf);
		if(sscanf(buf,"%d",&b)==1)
		{
			if(a>b)
				swap(a,b);
			printf("Case %d: %d\n",cas,dp[b]-dp[a-1]);
		}
		else
			printf("Case %d: %d\n",cas,key[a]);
	}

	return 0;
}
