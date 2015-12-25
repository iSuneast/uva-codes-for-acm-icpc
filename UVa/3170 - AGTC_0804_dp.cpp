/*
3170 - AGTC

dp...
edit step..
±‡º≠æ‡¿Î
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

int la,lb;
char a[MAXN],b[MAXN];
int dp[MAXN][MAXN];

int main()
{
	while(scanf("%d%s",&la,a)!=EOF)
	{
		scanf("%d%s",&lb,b);

		memset(dp,0,sizeof(dp));
		for(int i=0;i<=la;++i)
			dp[i][0]=i;
		for(int j=0;j<=lb;++j)
			dp[0][j]=j;

		for(int j=1;j<=lb;++j)
		{
			for(int i=1;i<=la;++i){
				dp[i][j]=dp[i-1][j-1]+(b[j-1]!=a[i-1]);
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			}
		}

		printf("%d\n",dp[la][lb]);
	}

	return 0;
}
