/*
610 - Street Directions

graph theory...
bridges...
其实就是求割边而已...
将一条无向边拆成两条有向弧...
从任意点开始dfs...
标记树边,如果已经标记过该树边的反向弧,则不标记该边...
如果某条边是桥则同时标记该边的正反弧...
最后只需要把标记过的边输出来即可...
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define MAXN 1003
using namespace std;

struct EDGE
{
	int v;
	bool flag;
	EDGE *next,*rev;
}*edge[MAXN],data[MAXN*MAXN];
int n,m,tot;

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

void link(EDGE *cur,int u,int v,EDGE *rev)
{
	cur->v=v;	cur->flag=false;
	cur->next=edge[u];	edge[u]=cur;	cur->rev=rev;
}

void d_link(int u,int v)
{
	link(&data[tot],u,v,&data[tot+1]);
	link(&data[tot+1],v,u,&data[tot]);
	tot+=2;
}

int dep[MAXN],low[MAXN];
bool flag[MAXN];

void dfs(int u,int fa,int depth)
{
	flag[u]=true;
	low[u]=dep[u]=depth;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
	{
		int v=cur->v;
		if(flag[v])
		{
			low[u]=(v!=fa && low[u]>dep[v])?dep[v]:low[u];
			if(!cur->rev->flag)
				cur->flag=true;
		}
		else
		{
			cur->flag=true;
			dfs(v,u,depth+1);
			low[u]=min(low[u],low[v]);
			if(low[v]>dep[u])
				cur->flag=cur->rev->flag=true;
		}
	}
}

vector< pair<int,int> > vpii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1,u,v;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		graph_init();
		while(m--)
		{
			scanf("%d%d",&u,&v);
			d_link(u,v);
		}

		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;++i)
			if(!flag[i])
				dfs(i,i,0);

		printf("%d\n\n",cas++);

		vpii.clear();
		for(int u=1;u<=n;++u)
			for(EDGE *cur=edge[u];cur;cur=cur->next)
				if(cur->flag)
					vpii.push_back( make_pair(cur->v,u) );
		sort(vpii.begin(),vpii.end());

		int sz=vpii.size(),p=0;
		for(int i=0;i<sz;++i)
			if(vpii[i]!=vpii[p])
				vpii[++p]=vpii[i];

		sz=min(sz,p+1);
		for(int i=0;i<sz;++i)
			printf("%d %d\n",vpii[i].first,vpii[i].second);

		puts("#");
	}

	return 0;
}
