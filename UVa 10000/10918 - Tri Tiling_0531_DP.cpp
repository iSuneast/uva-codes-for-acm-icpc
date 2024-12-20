/*
10918 - Tri Tiling

DP...

********   AA*******   AA******   A*******
******** = BB******* + B******* + A*******
********   CC*******   B*******   BB******
f(n)   =  f(n-2)   +  g(n-1)  +  g(n-1)

********   A********   AA*******
******** = A******** + BB*******
 *******    ********    CC******
g(n)   =   f(n-1)  +   g(n-2)

a[n] = 3*a[n-2] + 2*a[n-4] + 2*a[n-6] + ... + 2*a[0]
*/

#include<iostream>
#define MAXN 30
using namespace std;

int dp[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=2;i<=MAXN;i+=2)
		for(int j=0;j<i;j+=2)
			if(j==i-2)
				dp[i]+=3*dp[j];
			else
				dp[i]+=2*dp[j];

	int n;
	while(scanf("%d",&n)!=EOF && n>=0)
		printf("%d\n",dp[n]);

	return 0;
}
