/*
10842 - Traffic Flow

MST...
*/

#include<iostream>
#include<queue>
#define MAXN 110
using namespace std;

int fa[MAXN];
struct graph
{
	int s,e,w;
}pnt;
struct cmp
{
	bool operator()(graph a,graph b)
	{
		return a.w<b.w;
	}
};
int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,cas=1;
	cin>>dataset;
	while(dataset--)
	{
		int n,m,i,a,b,key=1000;
		cin>>n>>m;
		for(i=0;i<n;i++)		//之前几次RE是因为对并查集的初始化越界.
			fa[i]=i;
		priority_queue<graph,vector<graph>,cmp> pq;
		for(i=0;i<m;i++)
		{
			cin>>pnt.s>>pnt.e>>pnt.w;
			pq.push(pnt);
		}
		while(!pq.empty())
		{
			pnt=pq.top();	pq.pop();
			a=find(pnt.s);
			b=find(pnt.e);
			if(a!=b)
			{
				fa[a]=b;
				key=key<pnt.w?key:pnt.w;
			}
		}
		cout<<"Case #"<<cas++<<": "<<key<<endl;
	}

return 0;
}
