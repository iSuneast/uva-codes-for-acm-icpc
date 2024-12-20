/*
515 - King

graph theory
spfa
第一次写差分约束...
果然很杯具啊...

在poj那边wa了有20多次...
竟然是小bug...
彻底无语了...
果然发现说模板很重要啊...

本题刚开始时一直不懂怎么回事...
看了别人的解题报告才明白说是差分约束...

给定一个序列s[u]+s[u+1]+...+s[u+v]
满足> || < w
则令s[u]+s[u+1]+...+s[u+v]=g[u+v]-g[u-1]
问题就转化为g[u+v]-g[u-1]>w (<w)
则再划一下公式变为
>w	:	g[u+v]-g[u-1]>w
		即	g[u-1]-g[u+v]<-w
		即	g[u-1]-g[u+v]<=-w-1
<w	:	g[u+v]-g[u-1]<w
		即	g[u+v]-g[u-1]<=w-1
建图,判一下是否存在负环就可以了..
*/

#include<iostream>
#include<queue>
#include<vector>
#define MAXN 110
using namespace std;
typedef pair<int,int> pii;

int dis[MAXN],cnt[MAXN],n,m;
vector<pii> g[MAXN];
bool inq[MAXN];

bool spfa()
{
	memset(dis,0,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	for(int i=0;i<=n;++i)
		q.push(i);

	while(!q.empty())
	{
		int u=q.front(),sz=g[u].size();	q.pop();
		inq[u]=false;
		for(int i=0;i<sz;++i)
		{
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[v]>dis[u]+w)			//!!!!!!wa了20次...
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					q.push(v);
					if(++cnt[v]>n)
						return true;
					inq[v]=true;
				}
			}
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d",&m);
		for(int i=0;i<=n;++i)
			g[i].clear();

		int u,v,w;
		char buf[3];
		while(m--)
		{
			scanf("%d%d%s%d",&u,&v,buf,&w);
			if(buf[0]=='g')
				g[u+v].push_back(make_pair(u-1,-w-1));
			else
				g[u-1].push_back(make_pair(u+v,w-1));
		}

		if(spfa())
			puts("successful conspiracy");
		else
			puts("lamentable kingdom");
	}

	return 0;
}
