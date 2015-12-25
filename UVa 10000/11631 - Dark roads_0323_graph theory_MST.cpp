/*
11631 - Dark roads

MST...
*/

#include<iostream>
#include<queue>
#define MAXN 200010
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
		return a.w>b.w;
	}
};
int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}
int main()
{
//	freopen("in.txt","r",stdin);

	int m,n;
	while(cin>>n>>m && (n||m))
	{
		int i,a,b,key=0;
		priority_queue<graph,vector<graph>,cmp> pq;
		for(i=0;i<m;i++)
		{
			cin>>pnt.s>>pnt.e>>pnt.w;
			key+=pnt.w;
			pq.push(pnt);
		}
		for(i=0;i<n;i++)
			fa[i]=i;
		while(!pq.empty())
		{
			pnt=pq.top();	pq.pop();
			a=find(pnt.s);
			b=find(pnt.e);
			if(a!=b)
			{
				key-=pnt.w;
				fa[a]=b;
			}
		}
		cout<<key<<endl;
	}

return 0;
}
