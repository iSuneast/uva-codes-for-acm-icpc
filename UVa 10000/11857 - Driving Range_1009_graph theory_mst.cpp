/*
11857 - Driving Range

graph theory...
MST...
the maximum weight edge on the MST is the correct answer
*/

#include<iostream>
#include<algorithm>
#define MAXN 1000000
using namespace std;

struct EDGE
{
	int u,v,w;
	bool operator<(const EDGE &t)const
	{
		return w<t.w;
	}
}edge[MAXN];
int fa[MAXN],n,m;

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<n;++i)
			fa[i]=i;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		sort(edge,edge+m);
		int cnt=n-1,key=-1;
		for(int i=0;i<m && cnt>0;++i)
		{
			int u=find( edge[i].u ),v=find( edge[i].v );
			if(u!=v)
			{
				fa[u]=v;
				key=edge[i].w;
				--cnt;
			}
		}

		if(key==-1 || cnt>0)
			puts("IMPOSSIBLE");
		else
			printf("%d\n",key);
	}

	return 0;
}
