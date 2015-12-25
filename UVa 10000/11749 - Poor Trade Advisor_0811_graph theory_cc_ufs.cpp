/*
11749 - Poor Trade Advisor

graph theory...
union find set...
����ͨ��֧...
ֱ���ò��鼯���Ϳ�����...

�������б�,�����,ȡ���ߵ�ȨֵΪ��׼,
�ϲ�����������Ȩ�����Ķ���
ͳ��,ͬһ����ͨ��֧���������...
������ļ���...

�þ�����,Ϊʲôһֱwa...
ͻȻ�뵽˵,���һ��ʼ��ʼ���ı�Ȩ����-INT_MAX...
����m==0�Ļ�...�͹���...
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
