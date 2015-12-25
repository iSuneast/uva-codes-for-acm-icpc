/*
326 - Extrapolation Using a Difference Table

dp...
晕,本来就是很简单的题被自己想得太复杂了...
直接递推就可以了...
不要搞什么公式...
*/

#include<iostream>
#define MAXN 13
using namespace std;

int mat[MAXN][MAXN],dp[MAXN],n,k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&mat[i][0]);
		scanf("%d",&k);

		for(int j=1;j<n;++j)
			for(int i=n-1;i>j-1;--i)
				mat[i][j]=mat[i][j-1]-mat[i-1][j-1];
		for(int i=0;i<n;++i)
			dp[i]=mat[n-1][i];

		for(int j=0;j<k;++j)
			for(int i=n-2;i>=0;--i)
				dp[i]+=dp[i+1];
		printf("Term %d of the sequence is %d\n",n+k,dp[0]);
	}

	return 0;
}
