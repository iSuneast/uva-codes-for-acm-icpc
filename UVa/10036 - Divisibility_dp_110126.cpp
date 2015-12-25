/*
 * 10036 - Divisibility
 *
 * dp...
 * num_i = j*k + Rem
 * we need to check SUM( +/- num_i )%k==0
 * so SUM( +/- Rem )%k==0
 * now the number is reduce to 0<=Rem_i<k
 * a dp solution will do...
 *
 * happy coding..
 */

#include<iostream>
#define MAXN 103
using namespace std;

int dp[2][MAXN],n,k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,t;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&k);
		memset(dp,-1,sizeof(dp));
		int cur=0,next=1;
		dp[cur][0]=0;

		for(int dep=0;dep<n;++dep)
		{
			scanf("%d",&t);
			for(int j=0;j<MAXN;++j)
			{
				if(dp[ cur ][ j ]==dep)
				{
					dp[ next ][ ((j+t)%k+k)%k ]=dep+1;
					dp[ next ][ ((j-t)%k+k)%k ]=dep+1;
				}
			}
			swap(cur,next);
		}

		puts(dp[cur][0]==n?"Divisible":"Not divisible");
	}

	return 0;
}
