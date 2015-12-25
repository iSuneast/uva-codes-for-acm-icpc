/*
 * 10128 - Queue
 *
 * mask dp...
 * 其实有复杂度O(N*N)的DP解法的~
 * 要用到组合数学的知识
 *
 * 对于普通的状态DP,解法还是很显然的
 * dp[人数][当前看得见的人][状态]
 * "最高的人"可以从状态里面得到,设为H
 * 从未选中的人里面选一个,设为X
 * 如果X>H && 当前看得见的人<看得见的人
 * 		状态转移为dp[人数][当前看得见的人+1][合并的状态]
 * 如果X<H
 * 		状态转移为dp[人数][当前看得见的人][合并的状态]
 *
 * 用分治的思想,最高的人一定是N,N左边至少要有p-1个人,右边至少r-1个人
 * 可以枚举左边人数,设为i,则右边有n-i-1个人
 * 由于左边的i个人可以从n个人里面任选,方案数为C(n-1,i-1)
 * 则解为SUM( dp[i][0][0]*dp[n-i-1][0][0]*C(n-1,i-1) )
 *
 * happy coding~
 */

#include<iostream>
#define INSIDE(i,s) ((1<<(i))&s)
#define MERGE(i,s) ((1<<(i))|s)
#define ALL(n) ((1<<(n))-1)
#define MAXN 13
using namespace std;
typedef long long LL;

LL dp[MAXN][MAXN][1<<MAXN];

LL DP(int n,int p,int state)
{
	if(dp[n][p][state]!=-1)
		return dp[n][p][state];
	if(state==ALL(n))
		return dp[n][p][state]=(p==0);

	int hei=-1;
	for(int i=0;i<n;++i)
	{
		if(INSIDE(i,state))
			hei=i;
	}

	dp[n][p][state]=0;
	for(int i=0;i<n;++i)
	{
		if(!INSIDE(i,state))
		{
			if(i>hei && p>0)
				dp[n][p][state]+=DP(n,p-1,MERGE(i,state));
			else if(i<hei)
				dp[n][p][state]+=DP(n,p,MERGE(i,state));
		}
	}

	return dp[n][p][state];
}

LL C(int n,int p)
{
	LL key=1;
	for(int i=p+1;i<=n;++i)
		key*=i;
	for(int i=2;i<=n-p;++i)
		key/=i;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	int dataset,n,p,r;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&n,&p,&r);
		LL key=0;
		for(int i=p;i<=n-r+1;++i)
		{
			key+=DP(i-1,p-1,0)*DP(n-i,r-1,0)*C(n-1,i-1);
		}

		printf("%lld\n",key);
	}

	return 0;
}
