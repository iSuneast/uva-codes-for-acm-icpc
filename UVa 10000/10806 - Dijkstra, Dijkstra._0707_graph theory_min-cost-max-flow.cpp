/*
10806 - Dijkstra, Dijkstra.

graph theory...
min-cost-max-flow...
最小费用流...
求s到t的两条边不相交的最短路...
可以加一条0到s的容量为2的边...
然后跑一次费用流就可以了...
*/

#include<iostream>
#include<queue>
#define MAXN 110
#define INF 0x3f3f3f3f
using namespace std;

int next[MAXN][MAXN],cost[MAXN][MAXN],sz[MAXN];
int n,m;
int cap[MAXN][MAXN],flow[MAXN][MAXN];

void link(int u,int v,int w)
{
	next[ u ][ sz[u]++ ]=v;
	next[ v ][ sz[v]++ ]=u;
	cost[u][v]=cost[v][u]=w;
	cap[u][v]=cap[v][u]=1;
	flow[u][v]=flow[v][u]=0;
}

bool inq[MAXN],fresh[MAXN];
int dis[MAXN],fa[MAXN];
const int s=0;

void min_cost_max_flow()
{
	queue<int> q;
	int f=0;
	while(true)
	{
		q.push(s);	inq[s]=true;
		memset(dis,0x3f,sizeof(dis));	dis[s]=0;
		memset(fresh,0,sizeof(fresh));
		while(!q.empty())
		{
			int u=q.front();	q.pop();	inq[u]=false;
			for(int i=0;i<sz[u];++i)
			{
				int v=next[u][i];
				if(cap[u][v]>flow[u][v] && dis[v]>dis[u]+cost[u][v])
				{
					dis[v]=dis[u]+cost[u][v];
					fa[v]=u;
					fresh[v]=true;
					if(!inq[v])
						q.push(v);
					inq[v]=true;
				}
				if(flow[v][u]>0 && dis[v]>dis[u]-cost[v][u])
				{
					dis[v]=dis[u]-cost[v][u];
					fa[v]=u;
					fresh[v]=false;
					if(!inq[v])
						q.push(v);
					inq[v]=true;
				}
			}
		}

		if(dis[n]==INF)
		{
			if(f==2)
			{
				int key=0;
				for(int u=s;u<=n;++u)
					for(int i=0;i<sz[u];++i)
					{
						int v=next[u][i];
						key+=flow[u][v]*cost[u][v];
					}
					printf("%d\n",key);
			}
			else
				puts("Back to jail");
			return ;
		}

		int cur=INF;
		for(int u=n;u!=s;u=fa[u])
			cur=min(cur,fresh[u]?cap[ fa[u] ][u]-flow[ fa[u] ][u]:flow[u][ fa[u] ]);

		for(int u=n;u!=s;u=fa[u])
			fresh[u]?flow[ fa[u] ][u]+=cur:flow[u][fa[u]]-=cur;

		f+=cur;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while( scanf("%d",&n)!=EOF && n )
	{
		scanf("%d",&m);
		memset(sz,0,sizeof(sz));
		next[s][ sz[s]++ ]=1;
		cap[s][1]=cap[1][s]=2;
		flow[s][1]=flow[1][s]=0;
		int u,v,w;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			link(u,v,w);
		}
		min_cost_max_flow();
	}

	return 0;
}
