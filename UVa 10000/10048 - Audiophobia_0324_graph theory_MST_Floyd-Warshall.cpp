/*
10048 - Audiophobia

MST...
RMQ...?
*/

#include<iostream>
#include<queue>
#define MAXN 110
#define INF 1e8
#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)
using namespace std;

int fa[MAXN],g[MAXN][MAXN],c,s,q;

struct graph
{
	int s,e,w;
}pnt;
struct cmp
{
	bool operator()(graph a,graph b)
	{
		return a.w>b.w;
	}
};
int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}
priority_queue<graph,vector<graph>,cmp> pq;

void kruskal()
{
	int i,j,a,b;
	for(i=1;i<=c;i++)
		for(j=1;j<=c;j++)
			g[i][j]=INF;
	for(i=1;i<=c;i++)
		fa[i]=i;
	while(!pq.empty())
	{
		pnt=pq.top();	pq.pop();
		a=find(pnt.s);
		b=find(pnt.e);
		if(a!=b)
		{
			fa[a]=b;
			g[pnt.s][pnt.e]=g[pnt.e][pnt.s]=pnt.w;
		}
	}
}

void floyd_warshall()
{
	for(int k=1;k<=c;k++)
		for(int i=1;i<=c;i++)
			for(int j=1;j<=c;j++)
				g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1;
	bool first=true;
	while(cin>>c>>s>>q && (c||s||q))
	{
		if(first)
			first=false;
		else
			cout<<endl;
		int i;
		for(i=0;i<s;i++)
		{
			scanf("%d %d %d",&pnt.s,&pnt.e,&pnt.w);
			pq.push(pnt);
		}
		kruskal();
		floyd_warshall();
		cout<<"Case #"<<cas++<<endl;
		for(i=0;i<q;i++)
		{
			scanf("%d %d",&pnt.s,&pnt.e);
			if(g[pnt.s][pnt.e]==INF)
				cout<<"no path"<<endl;
			else
				cout<<g[pnt.s][pnt.e]<<endl;
		}
	}

return 0;
}
