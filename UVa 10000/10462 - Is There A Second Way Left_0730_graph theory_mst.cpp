/*
10462 - Is There A Second Way Left?

graph theory...
second best mst...
第二小生成树
枚举删除最小生成树里面的边
然后对剩余图求mst...
*/

#include<iostream>
#include<algorithm>
#define MAXN 103
#define INF 0x3f3f3f3f
using namespace std;

int n,m,fa[MAXN];
struct EDGE{
	int u,v,w;
	bool operator<(const EDGE &t)const
	{
		return w<t.w;
	}
}edge[MAXN<<1];
int flag[MAXN<<1];

void init()
{
	for(int i=1;i<=n;++i)
		fa[i]=i;
}

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

int sb_mst()
{
	int i,j,k,key=0,cnt=1;
	init();
	memset(flag,0,sizeof(flag));
	for(i=0;i<m;++i)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u!=v)
		{
			fa[u]=v;
			key+=edge[i].w;
			flag[i]=cnt++;
		}
	}

	if(cnt!=n)
		return -1;

	int sb=INF;
	for(j=1;j<n;++j)
	{
		int tw=0;cnt=1;
		init();
		for(i=0;i<m;++i)
		{
			if(flag[i]!=j)
			{
				int u=find(edge[i].u),v=find(edge[i].v);
				if(u!=v)
				{
					fa[u]=v;
					tw+=edge[i].w;
					++cnt;
				}
			}
		}

		if(cnt==n)
			sb=min(sb,tw);
	}

	return sb;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge,edge+m);

		int key=sb_mst();
		if(key==INF)
			printf("Case #%d : No second way\n",cas);
		else if(key==-1)
			printf("Case #%d : No way\n",cas);
		else
			printf("Case #%d : %d\n",cas,key);
	}

	return 0;
}
