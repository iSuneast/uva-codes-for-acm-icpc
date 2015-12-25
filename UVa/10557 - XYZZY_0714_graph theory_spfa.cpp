/*
10557 - XYZZY

graph theory...
拆点法...
把点拆成两个(一个入点,一个出点),点权就变成了边权

对边权取反,spfa判负权回路
如果一个点在负权回路上,则dfs这个点,看能否到达终点,可以的话就"win"
	不可以的话,就直接把从这个点出发的边全部删除,反正是无用点,继续松弛会导致死循环
如果spfa没有得到解,最后只需要判断一下终点的时候被松弛过,被松弛过则"win"


由于有能量限制,所以不是所有的dis[v]>dis[u]+g[u][v]都可以松弛的
还要判断松弛后的能量是否可行,不可行就不要松弛了...
*/

#include<iostream>
#include<queue>
#define PUSH(n) {q.push(n);inq[n]=true;}
#define POP() {inq[ q.front() ]=false;	q.pop();}
#define BOUND 100
#define MAXN 210
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

int next[MAXN][MAXN],g[MAXN][MAXN],sz[MAXN];
int n;

void link(int u,int v,int w)
{
	next[ u ][ sz[u]++ ]=v;
	g[u][v]=-w;		//取反
}

bool flag[MAXN];

void dfs(int u)
{
	flag[u]=true;
	for(int i=0;i<sz[u];++i)
	{
		int v=next[u][i];
		if(!flag[v])
			dfs(v);
	}
}

bool chk(int u)
{
	memset(flag,0,sizeof(flag));
	dfs(u);
	return flag[n];
}

int relax[MAXN],dis[MAXN];
bool inq[MAXN];

bool spfa()
{
	memset(inq,0,sizeof(inq));
	memset(relax,0,sizeof(relax));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	PUSH(1);	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		for(int i=0;i<sz[u];++i)
		{
			int v=next[u][i];
			if(dis[v]>dis[u]+g[u][v] && dis[u]+g[u][v]<BOUND)
			{
				dis[v]=dis[u]+g[u][v];
				if(++relax[v]>=n)
				{
					if(chk(v))
						return true;
					sz[v]=0;
				}
				if(!inq[v])
					q.push(v);
				inq[v]=true;
			}
		}
	}
	return dis[n]!=INF;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		int u,v,w,t;
		memset(sz,0,sizeof(sz));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&w);
			link(i,i+n,w);
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&u);
				link(i+n,u,0);
			}
		}

		if( spfa() )
			puts("winnable");
		else
			puts("hopeless");
	}

	return 0;
}
