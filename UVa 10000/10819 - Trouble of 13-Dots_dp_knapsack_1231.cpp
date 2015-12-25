/*
10819 - Trouble of 13-Dots

dp...
knapsack...

@ make Money = m+200, whatever the exact value of m is
@ do 0-1 knapsack
@ for (0 - > Money)
     if MoneySpend>2000 || MoneySpend <= m
		ChkMin(ans)
done !
*/

#include<iostream>
#define MAXN 10201
using namespace std;

int dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int m,n,p,f;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int t=m;
		t+=200;

		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		while(n--)
		{
			scanf("%d%d",&p,&f);
			for(int i=t;i>=p;--i)
				if(dp[i-p]!=-1)
					dp[i]=max(dp[i],dp[i-p]+f);
		}

		int key=0;
		for(int i=0;i<=t;++i)
		{
			if( 2000<i || i<=m)
				key=max(key,dp[i]);
		}

		printf("%d\n",key);
	}

	return 0;
}
