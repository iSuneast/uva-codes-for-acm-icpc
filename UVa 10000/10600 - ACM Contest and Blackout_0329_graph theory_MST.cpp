/*
10600 - ACM Contest and Blackout

MST...
Second best MST...
*/

#include<iostream>
#include<algorithm>
#define MAXN 110
#define MAXEDGE 10010
#define INF 1e9

using namespace std;

int n,m,key1,key2,fa[MAXN],mst[MAXN];

struct graph
{
	int s,e,w;
}pnt[MAXEDGE];

int cmp(const graph a,const graph b)
{
	return a.w<b.w;
}

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

void kruskal()
{
	key1=0;
	int i,j,a,b,edges=0;
	for(i=1;i<=n;++i)
		fa[i]=i;
	memset(mst,0,sizeof(mst));
	for(i=0;i<m;++i)
	{
		a=find(pnt[i].s);
		b=find(pnt[i].e);
		if(a!=b)
		{
			fa[a]=b;
			key1+=pnt[i].w;
			mst[edges++]=i;
		}
	}
	key2=INF;
	for(j=0;j<edges;++j)
	{
		int t=0;
		for(i=1;i<=n;++i)
			fa[i]=i;
		for(i=0;i<m;++i)
			if(i!=mst[j])
			{
				a=find(pnt[i].s);
				b=find(pnt[i].e);
				if(a!=b)
				{
					fa[a]=b;
					t+=pnt[i].w;
				}
			}
		a=find(n);
		for(i=1;i<n;++i)
			if(find(i)!=a)
				t=INF;
		key2=key2<t?key2:t;
	}
	if(key2==INF)
		key2=key1;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n>>m;
		for(int i=0;i<m;++i)
			scanf("%d %d %d",&pnt[i].s,&pnt[i].e,&pnt[i].w);
		sort(pnt,pnt+m,cmp);
		kruskal();
		cout<<key1<<' '<<key2<<endl;
	}

	return 0;
}