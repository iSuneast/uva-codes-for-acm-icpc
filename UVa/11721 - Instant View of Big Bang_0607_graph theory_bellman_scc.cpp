/*
11721 - Instant View of Big Bang

bellman-ford...
scc...
好复杂,好麻烦的题目啊...

先求scc
然后对每个scc过一次bellman.有负环则打个标记
由负环的结点向外(用求scc时的反图)dfs.
将所有dfs到的结点全部打上标记...
依次输出标记过的结点即可...
*/

#include<iostream>
#include<queue>
#define MAXN 1010
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int,int> pii;

int node,edge,sz[MAXN],sz2[MAXN];
pii next[MAXN][MAXN],back[MAXN][MAXN];
bool inq[MAXN];
int dis[MAXN],fa[MAXN],cnt[MAXN];
int topo[MAXN<<1],tot,cc,flag[MAXN],scc[MAXN];

void dfs(pii g[MAXN][MAXN],int sz[MAXN],int cur)
{
	flag[cur]=cc;
	for(int i=0;i<sz[cur];++i)
	{
		int v=g[cur][i].first;
		if(!flag[v])
			dfs(g,sz,v);
	}
	topo[--tot]=cur;
}

bool bellman(int cc,int start)
{
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(start);
	inq[start]=true;
	dis[start]=0;
	bool bk=false;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		inq[u]=false;
		for(int i=0;i<sz[u];++i)
		{
			int v=next[u][i].first,w=next[u][i].second;
			if(flag[v]==cc && dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				++cnt[v];
				if(!inq[v])
					q.push(v);
				inq[v]=true;
			}
			if(cnt[v]>=node)
				return true;
		}
	}
	return false;
}

void dfs(int cur)
{
	flag[cur]=-1;
	for(int i=0;i<sz2[cur];++i)
	{
		int v=back[cur][i].first;
		if(flag[v]>0)
			dfs(v);
	}
}

bool SCC()
{
	tot=node;
	cc=1;
	memset(flag,0,sizeof(flag));
	for(int i=0;i<node;++i)
		if(!flag[i])
			dfs(next,sz,i);

	memset(flag,0,sizeof(flag));
	tot=node*2;
	for(int i=0;i<node;++i)
		if(!flag[ topo[i] ])
		{
			dfs(back,sz2,topo[i]);
			++cc;
		}

	int cur=1;
	bool done=false;
	memset(dis,0x7f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<node;++i)
	{
		if(flag[ topo[i] ]==cur)
		{
			if(bellman(cur,topo[i]))
			{
				while(i<node && flag[ topo[i] ]==cur)
					flag[ topo[i] ]=-1,++i;
				done=true;
				--i;
			}
			++cur;
		}
	}

	if(done)
		for(int i=0;i<node;++i)
			if(flag[i]==-1)
				dfs(i);

	return done;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d",&node,&edge);
		int x,y,t;
		memset(sz,0,sizeof(sz));
		memset(sz2,0,sizeof(sz2));
		for(int i=0;i<edge;++i)
		{
			scanf("%d%d%d",&x,&y,&t);
			next[x][sz[x]++]=make_pair(y,t);
			back[y][sz2[y]++]=make_pair(x,t);
		}

		if(!SCC())
			printf("Case %d: impossible\n",cas);
		else
		{
			printf("Case %d:",cas);
			for(int i=0;i<node;++i)
				if(flag[i]<0)
					printf(" %d",i);
			putchar('\n');
		}
	}

	return 0;
}
