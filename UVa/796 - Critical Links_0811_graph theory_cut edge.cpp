/*
796 - Critical Links

graph theory...
bridges...
求割边...
对任意一点开始dfs...
标记数组:
low[u] --- u可以到达的处fa结点以外的离树根最近的顶点
dep[u] --- u的深度

如果u->v 且low[v]>dep[u],则u->v为割边
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define MAXN 203
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];
int n,tot;

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void input()
{
	graph_init();

	int u,v,t;
	char op[10];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&u);
		scanf("%s",op);
		sscanf(op,"(%d)",&t);
		while(t--)
		{
			scanf("%d",&v);
			link(u,v);
		}
	}
}

int low[MAXN],dep[MAXN];
vector< pair<int,int> > vpii;
bool flag[MAXN];

void dfs(int u,int fa,int depth)
{
	flag[u]=true;
	low[u]=dep[u]=depth;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
	{
		int v=cur->v;
		if(flag[v])
			low[u]=(v!=fa && low[u]>dep[v])?dep[v]:low[u];
		else
		{
			dfs(v,u,depth+1);
			low[u]=(low[u]<low[v])?low[u]:low[v];
			if(low[v]>dep[u])
			{
				if(u>v)
					vpii.push_back( make_pair(v,u) );
				else
					vpii.push_back( make_pair(u,v) );
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		input();

		memset(flag,0,sizeof(flag));
		vpii.clear();
		for(int i=0;i<n;++i)
			if(!flag[i])
				dfs(i,i,0);

		int sz=vpii.size();
		sort(vpii.begin(),vpii.end());
		int p=0;
		for(int i=0;i<sz;++i)
			if(vpii[i]!=vpii[p])
				vpii[++p]=vpii[i];
		sz=min(sz,p+1);

		printf("%d critical links\n",sz);
		for(int i=0;i<sz;++i)
			printf("%d - %d\n",vpii[i].first,vpii[i].second);
		putchar(10);
	}

	return 0;
}
