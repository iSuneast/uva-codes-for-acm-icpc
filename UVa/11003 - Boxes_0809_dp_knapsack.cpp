/*
11003 - Boxes

dp...
knapsack...
���ڶ���Ҫ�������϶ѵ�...
���Զ������ݵ�ʱ��ֱ�ӴӺ���ǰ��,�Ϳ��԰ѵ��Ʊ��������...

dp[i][j]��ʾ��i����Ʒ��j����Ʒʱ,j����Ʒ����С����
��dp[i][j]=min(*,dp[i-1][j])
	��i����Ʒ���ٿ��Գ��ܵ�i-1����Ʒ���Գ��ܵ�����
dp[i-1][j-1]<=dp[i].load --- (ǰ[i-1][j-1]��Ʒ������û�г�����i����Ʒ�ĳ���)
	dp[i][j]=min(*,dp[i-1][j-1]+data[i].w)

���dp[n][i]����б��������ֵ,������i���ǵĴ���...
*/

#include<iostream>
#define MAXN 1003
#define INF 0x3f3f3f3f
using namespace std;

struct TURTLE
{
	int w,load;
}data[MAXN];
int dp[MAXN][MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=n;i;--i)
			scanf("%d%d",&data[i].w,&data[i].load);

		int key=0;
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<=n;++i)
			dp[i][0]=0;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=i;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
				if(dp[i-1][j-1]<=data[i].load)
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]+data[i].w);
			}

		for(int i=1;i<=n;++i)
			if(dp[n][i]!=INF)
				key=i;

		printf("%d\n",key);
	}
	return 0;
}
