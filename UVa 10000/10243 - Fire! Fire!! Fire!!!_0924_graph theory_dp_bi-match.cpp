/*
10243 - Fire! Fire!! Fire!!!

graph theory...
vertex cover in a tree
use binary match to solve it...
be care of the test case
**********input
1
0
**********
**********output
1
**********

also dp on tree can handle it...

*/

#include<iostream>
#define MAXN 1003
#define MAXE 100003
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXE];
int edgePos,n,dp[MAXN][2];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	edgePos=0;
}

void link(int u,int v)
{
	data[edgePos].v=v;
	data[edgePos].next=edge[u];
	edge[u]=&data[edgePos++];
}

bool flag[MAXN];
int match[MAXN];

bool dfs(int u)
{
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(!flag[cur->v])
		{
			flag[cur->v]=true;
			if(match[cur->v]==-1 || dfs(match[cur->v]))
			{
				match[cur->v]=u;
				return true;
			}
		}
		return false;
}

int hungry()
{
	memset(match,-1,sizeof(match));
	int key=0;
	for(int i=1;i<=n;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	if(!key)
		key=2;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int sz,v;
	while(scanf("%d",&n)!=EOF && n)
	{
		graph_init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&sz);
			while(sz--)
			{
				scanf("%d",&v);
				link(i,v);
			}
		}

		printf("%d\n",hungry()/2);
	}

	return 0;
}

/*
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN 1003
#define MAXE 100003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXE];
int edgePos,n,dp[MAXN][2];
bool flag[MAXN];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	edgePos=0;
}

void link(int u,int v)
{
	data[edgePos].v=v;
	data[edgePos].next=edge[u];
	edge[u]=&data[edgePos++];
}

void DP(int u)
{
	flag[u]=true;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
	{
		if(flag[cur->v])
			continue;
		DP(cur->v);
		dp[u][0]+=dp[cur->v][1];
		dp[u][1]+=min( dp[cur->v][1],dp[cur->v][0] );
	}

	dp[u][1]++;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int sz,v;
	while(scanf("%d",&n)!=EOF && n)
	{
		graph_init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&sz);
			while(sz--)
			{
				scanf("%d",&v);
				link(i,v);
			}
		}

		memset(flag,0,sizeof(flag));
		memset(dp,0,sizeof(dp));
		int key=0;
		for(int i=1;i<=n;++i)
		{
			if(flag[i])
				continue;
			DP(i);
			key+=min( dp[i][0],dp[i][1] );
			if(!dp[i][0] || !dp[i][1])
				++key;
		}

		printf("%d\n",key);
	}

	return 0;
}

*/