/*
11354 - Bond

graph theory...
mst...
rmq...
好感动...
卡了几个月的题...
做出来了...

求一下图的mst
然后在mst里面找点对间的最大边权
由于询问很多
所以必须用rmq
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAXEDGE 100010
#define MAXN 50010
#define MAXDEP 16
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int,int> pii;

struct EDGE
{
	int u,v,w;
	bool operator<(const EDGE &t)const
	{
		return w<t.w;
	}
}edge[MAXEDGE];

int n,m,q;
int fa[MAXN];
vector<pii> vp[MAXN];

int find(int p)
{
	return fa[p]==p?p:fa[p]=find(fa[p]);
}

void kruskal()
{
	for(int i=0;i<n;++i)
	{
		fa[i]=i;
		vp[i].clear();
	}

	for(int i=0;i<m;++i)
	{
		int u=find( edge[i].u );
		int v=find( edge[i].v );
		if(u!=v)
		{
			fa[u]=v;
			vp[ edge[i].u ].push_back( make_pair(edge[i].v,edge[i].w) );
			vp[ edge[i].v ].push_back( make_pair(edge[i].u,edge[i].w) );
		}
	}
}

int dep[MAXN],dis[MAXN][MAXDEP];
bool vis[MAXN];

void bfs()
{
	memset(vis,false,sizeof(vis));
	memset(fa,-1,sizeof(fa));
	queue<int> q;

	q.push(0);
	vis[0]=true;
	dep[0]=0;
	dis[0][0]=0;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		int sz=vp[u].size();
		for(int i=0;i<sz;++i)
		{
			int v=vp[u][i].first;
			if(!vis[v])
			{
				vis[v]=true;
				dep[v]=dep[u]+1;
				dis[v][0]=vp[u][i].second;
				q.push(v);
				fa[v]=u;
			}
		}
	}
}

int ancestor[MAXN][MAXDEP];

void lca()
{
	kruskal();
	bfs();

	for(int i=0;i<n;++i)
	{
		ancestor[i][0]=fa[i];
		for(int j=1;(1<<j)<n;++j)
			ancestor[i][j]=-1;
	}
	for(int j=1;(1<<j)<n;++j)
		for(int i=0;i<n;++i)
			if(ancestor[i][j-1]!=-1)
			{
				ancestor[i][j]=ancestor[ ancestor[i][j-1] ][j-1];
				dis[i][j]=max(dis[i][j-1],dis[ ancestor[i][j-1] ][j-1]);
			}
}

int rmq(int p,int q)
{
	if(dep[p]<dep[q])
		swap(p,q);
	int log;
	for(log=1;(1<<log)<=dep[p];++log)
		;
	--log;

	int key=0;

	for(int i=log;i>=0;--i)
		if(dep[p]-(1<<i)>=dep[q])
		{
			key=max(key,dis[p][i]);
			p=ancestor[p][i];
		}
	if(p==q)
		return key;

	for(int i=log;i>=0;--i)
		if(ancestor[p][i]!=-1 && ancestor[p][i]!=ancestor[q][i])
		{
			key=max(key,dis[p][i]);
			key=max(key,dis[q][i]);
			p=ancestor[p][i],q=ancestor[q][i];
		}
	key=max(key,dis[p][0]);
	key=max(key,dis[q][0]);
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	bool first=true;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!first)
			putchar('\n');
		first=false;

		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
			--edge[i].u;	--edge[i].v;
		}
		sort(edge,edge+m);

		lca();

		scanf("%d",&q);
		int u,v;
		while(q--)
		{
			scanf("%d%d",&u,&v);
			--u;	--v;
			printf("%d\n",rmq(u,v));
		}
	}

	return 0;
}
