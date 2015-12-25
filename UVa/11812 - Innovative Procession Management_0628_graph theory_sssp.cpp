/*
11812 - Innovative Procession Management

graph theory...
sssp...
对原图取反...
然后以终点为源点求sssp...
取最小的dis为当前最短路...
若dis为INF,则退出

1.从终点开始dfs...
2.是最短路上的边则标记边,标记结点...
3.如果发现结点可以到达被标记过的结点则到达步骤2.
*/

#include<iostream>
#include<queue>
#include<algorithm>
#define MAXN 110
#define INF 0x7f7f7f7f
using namespace std;

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];

int n,m,s,src[MAXN],snk,tot;
int u,v,w;
int dis[MAXN];
bool inq[MAXN],pos[MAXN],flag[MAXN];
int cnt;

struct ANS
{
	int u,v,w;
	bool operator<(const ANS &t)const
	{
		if(u==t.u)
		{
			if(v==t.v)
				return w<t.w;
			return v<t.v;
		}
		return u<t.u;
	}
}ans[MAXN*MAXN];

void spfa(int s)
{
	memset(dis,0x7f,sizeof(dis));
	queue<int> q;
	q.push(s);	inq[s]=true;	dis[s]=0;
	while(!q.empty())
	{
		u=q.front();	q.pop();	inq[u]=false;
		EDGE *cur=edge[u];
		while(cur)
		{
			v=cur->v;	w=cur->w;
			if(v!=-1 && dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
					q.push(v);
				inq[v]=true;
			}
			cur=cur->next;
		}
	}
}

void dfs(int u)
{
	EDGE *cur=edge[u];
	while(cur)
	{
		if(dis[cur->v]!=INF && dis[cur->v]==dis[u]+cur->w)
		{
			dfs(cur->v);
			if(flag[cur->v] || pos[cur->v] && dis[cur->v]==w)
			{
				flag[u]=true;
				flag[cur->v]=true;
				ans[cnt].u=cur->v;
				ans[cnt].v=u;
				ans[cnt++].w=cur->w;
				cur->v=-1;
			}
		}
		cur=cur->next;
	}
}

void process()
{
	bool done=false;
	memset(inq,0,sizeof(inq));

	while(true)
	{
		spfa(snk);
		int key=INF;
		for(int i=0;i<s;++i)
			key=min(key,dis[ src[i] ]);
		if(key==INF)
			break;
		cout<<"The path cost is "<<key<<endl;

		cnt=0;
		w=key;
		memset(flag,0,sizeof(flag));
		dfs(snk);
		sort(ans,ans+cnt);
		for(int i=0;i<cnt;++i)
			cout<<ans[i].u<<" "<<ans[i].v<<" "<<ans[i].w<<endl;
		done=true;
	}

	if(!done)
		puts("No road to block");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>n>>m>>s;

		for(int i=1;i<=n;++i)
			edge[i]=NULL;

		memset(pos,0,sizeof(pos));
		for(int i=0;i<s;++i)
		{
			cin>>src[i];
			pos[ src[i] ]=true;
		}
		cin>>snk;

		tot=0;
		for(int i=0;i<m;++i)
		{
			cin>>data[tot].v>>u>>data[tot].w;
			data[tot].next=edge[u];
			edge[u]=&data[tot++];
		}

		cout<<"Case "<<cas<<":"<<endl;
		process();
	}

	return 0;
}
