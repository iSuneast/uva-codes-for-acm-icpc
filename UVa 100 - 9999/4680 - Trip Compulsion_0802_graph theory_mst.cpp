/*
4680 - Trip Compulsion

graph theory...
mst...
最小生成树...
枚举最小边即可...
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<ctime>
#define MAXN 3003
#define INF 2147483647
#define eps 1e-9
using namespace std;

struct EDGE
{
	int u,v,w;
	bool operator<(const EDGE &t)const
	{
		return w<t.w;
	}
}edge[MAXN];
int n,r,s,e,fa[MAXN],ans;

void init()
{
	for(int i=0;i<n;++i)
		fa[i]=i;
}

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

int kruskal(int p)
{
	init();
	for(int i=p;i<r;++i)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int a=find(u),b=find(v);
		if(a!=b)
			fa[a]=b;
		if(find(s)==find(e))
			return edge[i].w-edge[p].w;
	}
	return INF;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,i,j,k;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&r);
		scanf("%d%d",&s,&e);
		for(i=0;i<r;++i)
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge,edge+r);

		ans=INF;
		for(int p=0;p<r;++p)
		{
			int t=kruskal(p);
			ans=min(ans,t);
		}

		if(ans==INF)
			puts("NO PATH");
		else
			printf("%d\n",ans);
	}

	return 0;
}
