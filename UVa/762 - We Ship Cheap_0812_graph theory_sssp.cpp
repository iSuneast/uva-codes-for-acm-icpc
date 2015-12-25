/*
762 - We Ship Cheap

graph theory...
sssp...
建好图..求一次sssp即可...
要判断目标点是否在之前出现的路径中
不在的话,无解
*/

#include<iostream>
#include<string>
#include<queue>
#include<map>
#define MAXN 1000
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];

map<string,int> msi;
int n,node,tot,src,snk;
char a[7],b[7],dic[MAXN][7];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=node=0;
	msi.clear();
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void d_link(int u,int v)
{
	link(u,v);
	link(v,u);
}

void input()
{
	int u,v;
	graph_init();
	for(int i=0;i<n;++i)
	{
		scanf("%s%s",a,b);
		if(msi.find(a)==msi.end())
		{
			strcpy(dic[node],a);
			msi[a]=node++;
		}
		if(msi.find(b)==msi.end())
		{
			strcpy(dic[node],b);
			msi[b]=node++;
		}

		u=msi[a],v=msi[b];
		d_link(u,v);			
	}
	src=snk=-1;
	scanf("%s%s",a,b);
	if(msi.find(a)!=msi.end())
		src=msi[a];
	if(msi.find(b)!=msi.end())
		snk=msi[b];
}

int dis[MAXN],fa[MAXN];
bool inq[MAXN];

void spfa()
{
#define PUSH(s)	{if(!inq[s]) q.push(s);	inq[s]=true;}
#define POP()	{inq[q.front()]=false;	q.pop(); }

	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	PUSH(src);	dis[src]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			if(dis[cur->v]>dis[u]+1)
			{
				dis[cur->v]=dis[u]+1;
				fa[cur->v]=u;
				PUSH(cur->v);
			}
		}
	}
}

void dfs(int u)
{
	if(u==src)
		return ;
	dfs(fa[u]);
	printf("%s %s\n",dic[ fa[u] ],dic[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	bool first=true;
	while(scanf("%d",&n)!=EOF)
	{
		if(!first)
			putchar(10);
		first=false;

		input();
		if(src==-1 || snk==-1)
		{
			puts("No route");
			continue;
		}

		spfa();

		if(dis[snk]==INF)
			puts("No route");
		else
			dfs(snk);
	}

	return 0;
}
