/*
10980 - Lowest Price in Town

dp...
knapsack...
use dp[] array to store the minimum answer
initial dp[i]=i*single price
then just knapsack until MAXN
(I'm not sure about the exact value of MAXN, but 200 will do)
*/

#include<iostream>
#define MAXN 203
using namespace std;

double s,p,dp[MAXN];
int m,n,k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%lf%d",&s,&m)!=EOF)
	{
		for(int i=0;i<MAXN;++i)
			dp[i]=i*s;

		for(int i=0;i<m;++i)
		{
			scanf("%d%lf",&n,&p);
			for(int j=n;j<MAXN;++j)
				dp[j]=min(dp[j],dp[j-n]+p);
		}

		for(int j=MAXN-2;j;--j)
			dp[j]=min(dp[j],dp[j+1]);

		printf("Case %d:\n",cas++);
		do{
			scanf("%d",&k);
			printf("Buy %d for $%.2lf\n",k,dp[k]);
		}while(getchar()==' ');
	}

	return 0;
}
