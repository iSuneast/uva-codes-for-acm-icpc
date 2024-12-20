/*
11456 - Trainsorting

dp...
o(n^2)的lis和lds
类似于在双端队列里面插入元素
每次都尽量多地往队列里面加入元素
*/

#include<iostream>
#define MAXN 2010
using namespace std;

int var[MAXN],dp[2][MAXN],n;

int lis()
{
	int key=0;
	for(int i=0;i<n;++i)
	{
		dp[0][i]=dp[1][i]=1;
		for(int j=0;j<i;++j)
		{
			if(var[i]>var[j])	//lds
				dp[0][i]=max(dp[0][i],dp[0][j]+1);
			if(var[i]<var[j])	//lis
				dp[1][i]=max(dp[1][i],dp[1][j]+1);
		}
		key=max(key,dp[0][i]+dp[1][i]-1);
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=n-1;i>=0;--i)
			scanf("%d",var+i);
		printf("%d\n",lis());
	}

	return 0;
}
