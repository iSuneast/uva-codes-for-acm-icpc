/*
11749 - Poor Trade Advisor

graph theory...
union find set...
求连通分支...
直接用并查集做就可以了...

读入所有边,排序后,取最大边的权值为基准,
合并所有由最大边权相连的顶点
统计,同一个连通分支里面结点个数...
输出最大的即可...

用矩阵存边,为什么一直wa...
突然想到说,如果一开始初始化的边权就是-INT_MAX...
而且m==0的话...就挂了...
*/

#include<iostream>
#include<algorithm>
#define MAXN 503
#define MAXE 1000010
using namespace std;

struct EDGE
{
	int u,v,w;
	bool operator<(const EDGE &t)const
	{
		return w<t.w;
	}
}edge[MAXE];

int fa[MAXN],cnt[MAXN];
int n,m,key;

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

void merge(int u,int v)
{
	int a=find(u),b=find(v);
	if(a!=b)
	{
		fa[a]=fa[b];
		cnt[b]+=cnt[a];
		cnt[a]=0;
	}
}

void rand_data()
{
	freopen("in","w",stdout);
	int dataset=100;
	while(dataset--)
	{
		int n=rand()%500+1,m=rand()*rand()%10000;
		cout<<n<<" "<<m<<endl;
		while(m--)
			cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()*rand()<<endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=1;i<=n;++i)
			fa[i]=i,cnt[i]=1;

		for(int i=0;i<m;++i)
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge,edge+m);

		for(int i=m-1;i>=0;--i)
			if(edge[i].w==edge[m-1].w)
				merge(edge[i].u,edge[i].v);
			else
				break;

		int ans=0;
		for(int i=1;i<=n;++i)
			ans=max(ans,cnt[i]);

		printf("%d\n",ans);
	}

	return 0;
}
