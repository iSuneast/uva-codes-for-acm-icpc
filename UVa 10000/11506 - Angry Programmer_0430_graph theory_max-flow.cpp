/*
11506 - Angry Programmer

max-flow...
建图过程要注意...
经典的拆点算法...
最小割其实就是最大流...
*/

#include<iostream>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 0x7f7f7f7f
#define MAXN 110
using namespace std;

int m,w,start,end;
int cap[MAXN][MAXN],flow[MAXN][MAXN],fa[MAXN],remflow[MAXN];

int edmonds_karp()
{
	queue<int> q;
	int u,v,key=0;
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
		if(!remflow[end])
			return key;
		for(u=end;u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=remflow[end];
			flow[u][fa[u]]-=remflow[end];
		}
		key+=remflow[end];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&m,&w)!=EOF && (m||w))
	{
		int i,p,p2,weight;
		start=2;
		end=(m<<1)-1;
		memset(cap,-1,sizeof(cap));
		for(i=0;i<m-2;++i)
		{
			scanf("%d%d",&p,&weight);
			cap[(p<<1)-1][p<<1]=weight;
		}
		for(i=0;i<w;++i)
		{
			scanf("%d%d%d",&p,&p2,&weight);
			cap[p<<1][(p2<<1)-1]=cap[p2<<1][(p<<1)-1]=weight;
		}
		printf("%d\n",edmonds_karp());
	}

	return 0;
}
