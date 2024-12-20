/*
10910 - Marks Distribution

DP...
简单的组合DP...
拆成一段,有一种表示方式
拆成n段,有sum(dp[n-1][var])种
	其中var->[0,n]
*/

#include<iostream>
#define MAXN 70
using namespace std;

int dp[MAXN+3][MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	for(int seg=1;seg<=MAXN;++seg)
		for(int n=0;n<=MAXN;++n)
			if(seg==1)
				dp[seg][n]=1;
			else for(int var=0;var<=n;++var)
				dp[seg][n]+=dp[seg-1][var];

	int n,t,p,dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&n,&t,&p);
		printf("%d\n",dp[n][t-n*p]);
	}

	return 0;
}
