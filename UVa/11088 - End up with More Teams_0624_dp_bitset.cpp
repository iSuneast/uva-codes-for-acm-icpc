/*
11088 - End up with More Teams

dp...
bitset...
状态dp...
共2^15种状态
每次取三个"1"出来
求最大即可
*/

#include<iostream>
#define inside(i,j) ((1<<i)&j)
#define MAXN 16
#define TEAM 20
using namespace std;

int acm[MAXN],state[1<<MAXN];
int n;

int dp(int cur)
{
	if(state[cur]==-1)
	{
		state[cur]=0;
		for(int i=0;i<n;++i)
		{
			if(inside(i,cur))
				for(int j=i+1;j<n;++j)
					if(inside(j,cur))
						for(int k=j+1;k<n;++k)
							if(inside(k,cur))
							{
								if(acm[i]+acm[j]+acm[k]>=TEAM)
								{
									int ans=dp(cur-(1<<i)-(1<<j)-(1<<k));
									state[cur]=max(state[cur],ans+1);
								}
							}
		}
	}
	return state[cur];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&acm[i]);
		memset(state,-1,sizeof(state));
		printf("Case %d: %d\n",cas++,dp((1<<n)-1));
	}

	return 0;
}
