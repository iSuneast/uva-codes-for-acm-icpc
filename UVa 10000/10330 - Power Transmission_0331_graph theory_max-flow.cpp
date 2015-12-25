/*
10330 - Power Transmission

max-flow...
daxia说：把带权的点变成一条边，巧妙地转化了问题。。。
*/

#include<iostream>
#include<queue>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 210
#define INF 2e9
using namespace std;

int cap[MAXN][MAXN],flow[MAXN][MAXN],remflow[MAXN],fa[MAXN],
	start,end;

int edmonds_karp()
{
	int key=0;
	queue<int> q;
	int u,v;
	memset(flow,0,sizeof(flow));
	while(true)
	{
		memset(remflow,0,sizeof(remflow));
		remflow[start]=INF;
		q.push(start);
		while(!q.empty())
		{
			u=q.front();	q.pop();
			for(v=start;v<=end;++v)
				if(!remflow[v] && cap[u][v]>flow[u][v])
				{
					fa[v]=u;
					q.push(v);
					remflow[v]=min(remflow[u],cap[u][v]-flow[u][v]);
				}
		}
		if(remflow[end]==0)
			return key;
		for(u=fa[end];u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=remflow[end];
			flow[u][fa[u]]-=remflow[end];
		}
		key+=remflow[end];
	}
	return key;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,m;
	while(cin>>n)
	{
		start=0;
		end=(n<<1)+1;
		int i,s,b,d,t,w,maxflow;
		memset(cap,0,sizeof(cap));
		for(i=1;i<=n;++i)
		{
			scanf("%d",&maxflow);
			cap[(i<<1)-1][i<<1]=maxflow;
		}
		cin>>m;
		for(i=0;i<m;++i)
		{
			scanf("%d %d %d",&s,&t,&w);
			cap[s<<1][(t<<1)-1]=w;
		}
		scanf("%d %d",&b,&d);
		for(i=0;i<b;++i)
		{
			scanf("%d",&w);
			cap[start][(w<<1)-1]=INF;
		}
		for(i=0;i<d;++i)
		{
			scanf("%d",&w);
			cap[w<<1][end]=INF;
		}
		cout<<edmonds_karp()<<endl;
	}

	return 0;
}
/*
直接更新带权的点的流量值。。。WA。。。don't know why。。。

#include<iostream>
#include<queue>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 110
#define INF 2e9
using namespace std;

int cap[MAXN][MAXN],flow[MAXN][MAXN],maxflow[MAXN],remflow[MAXN],fa[MAXN],
	key,start,end;

void edmonds_karp()
{
	key=0;
	queue<int> q;
	int u,v;
	memset(flow,0,sizeof(flow));
	while(true)
	{
		memset(remflow,0,sizeof(remflow));
		remflow[start]=INF;
		q.push(start);
		while(!q.empty())
		{
			u=q.front();	q.pop();
			for(v=start;v<=end;++v)
				if(maxflow[v] && !remflow[v] && cap[u][v]>flow[u][v])
				{
					fa[v]=u;
					q.push(v);
					remflow[v]=min(remflow[u],cap[u][v]-flow[u][v]);
					remflow[v]=min(remflow[v],maxflow[v]);
				}
		}
		if(remflow[end]==0)
			return ;
		for(u=fa[end];u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=remflow[end];
			flow[u][fa[u]]-=remflow[end];
			maxflow[u]-=remflow[end];
		}
		key+=remflow[end];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,m;
	while(cin>>n)
	{
		start=0;
		end=n+1;
		int i,s,b,d,t,w;
		memset(maxflow,0,sizeof(maxflow));
		for(i=1;i<=n;++i)
			scanf("%d",maxflow+i);
		maxflow[start]=maxflow[end]=INF;
		cin>>m;
		memset(cap,0,sizeof(cap));
		for(i=0;i<m;++i)
		{
			scanf("%d %d %d",&s,&t,&w);
			cap[s][t]=w;
		}
		cin>>b>>d;
		for(i=0;i<b;++i)
		{
			cin>>w;
			cap[start][w]=INF;
		}
		for(i=0;i<d;++i)
		{
			cin>>w;
			cap[w][end]=INF;
		}
		edmonds_karp();
		cout<<key<<endl;
	}

	return 0;
}
*/
