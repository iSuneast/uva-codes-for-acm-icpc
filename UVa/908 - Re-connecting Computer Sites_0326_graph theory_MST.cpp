/*
908 - Re-connecting Computer Sites

MST...
*/

#include<iostream>
#include<queue>
#define MAXN 1000010
using namespace std;

int fa[MAXN],n,m,k;
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

int kruskal(priority_queue<graph,vector<graph>,cmp> pq)
{
	int key=0,a,b;
	for(a=1;a<=n;++a)
		fa[a]=a;
	while(!pq.empty())
	{
		pnt=pq.top();	pq.pop();
		a=find(pnt.s);
		b=find(pnt.e);
		if(a!=b)
		{
			fa[a]=b;
			key+=pnt.w;
		}
	}
	return key;
}

int main()
{
//	freopen("in.txt","r",stdin);

	bool first=true;
	while(scanf("%d",&n)!=EOF)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		int i;
		priority_queue<graph,vector<graph>,cmp> pq_n;
		for(i=1;i<n;++i)
		{
			scanf("%d %d %d",&pnt.s,&pnt.e,&pnt.w);
			pq_n.push(pnt);
		}
		scanf("%d",&k);
		priority_queue<graph,vector<graph>,cmp> pq_m;
		for(i=0;i<k;++i)
		{
			scanf("%d %d %d",&pnt.s,&pnt.e,&pnt.w);
			pq_m.push(pnt);
		}
		scanf("%d",&m);
		for(i=0;i<m;++i)
		{
			scanf("%d %d %d",&pnt.s,&pnt.e,&pnt.w);
			pq_m.push(pnt);
			pq_n.push(pnt);
		}
		cout<<kruskal(pq_n)<<endl
			<<kruskal(pq_m)<<endl;
	}

return 0;
}
