/*
 * 11903 - e-Friends
 * 
 * mask dp...
 * dp[ whoIsHere ][ Collision ][ State ]
 * if v is next to whoIsHere
 *     dp[ whoIsHere ][ Collision+bad(whoIsHere,v) ][ State-(1<<v) ]
 *     
 * just a simple dfs will do...
 * 
 * for large r and k, if k==0, collision can be n-1 (at most n-1)
 * else the answer is dp[ min(r/k, n-1) ][ everyCanBeHere ][ ALL_MAN ]
 * 
 * happy coding... and keep ac...
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INSIDE(u,s) ((1<<(u))&(s))
#define MERGE(v,s) ((1<<(v))|(s))
#define ALL(n) ((1<<(n))-1)
#define MAXN 13
using namespace std;

int dp[MAXN][MAXN][1<<MAXN], key[MAXN], n, k, q;
int bad[MAXN][MAXN];

int dfs(int col, int state,int fa)
{
	if(col<0)
		return 0;
	if(dp[col][fa][state]!=-1)
		return dp[col][fa][state];

	if(!state)
		return dp[col][fa][state]=1;
	
	dp[col][fa][state]=0;
	for(int u=0;u<n;++u)
	{
		if(INSIDE(u,state))
			dp[col][fa][state]+=dfs(col-bad[fa][u], state-(1<<u), u);
	}
	
	return dp[col][fa][state];
}

void DynamicP()
{	
	memset(dp,-1,sizeof(dp));
	
	for(int col=0;col<n;++col)
	{
		key[col]=dfs(col, ALL(n), n);
	}
}

void read()
{
	scanf("%d%d%d",&n,&k,&q);
	
	int ti, u;
	memset(bad,0,sizeof(bad));
	for(int i=0;i<n;++i)
	{
		scanf("%d",&ti);
		while(ti--)
		{
			scanf("%d",&u);	--u;
			bad[u][i]=1;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset, r;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
    	read();
    	DynamicP();
    	
    	printf("Case %d:\n",cas);
    	while(q--)
    	{
    		scanf("%d",&r);
    		int col=n-1;
    		if(k)
    			col=min(n-1, r/k);
    		printf("%d\n",key[col]);
    	}
    }

    return 0;
}

