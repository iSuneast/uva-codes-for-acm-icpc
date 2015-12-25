/*
11710 - Expensive subway

MST...
*/

#include<iostream>
#include<string>
#include<queue>
#include<map>
#define MAXN 410 
using namespace std;

int g[MAXN][MAXN],flag[MAXN],fa[MAXN],n;

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
void dfs(int p)
{
	flag[p]=1;
	for(int i=1;i<=n;i++)
		if(!flag[i] && g[p][i])
			dfs(i);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int m;
	while(cin>>n>>m && (n||m))
	{
		int i,j,a,b;
		string station;
		map<string,int> m_si;
		for(i=1;i<=n;i++)
		{
			cin>>station;
			m_si[station]=i;
			fa[i]=i;
		}
		memset(g,0,sizeof(g));
		priority_queue<graph,vector<graph>,cmp> pq;
		vector<int> vi[MAXN];
		for(i=0;i<m;i++)
		{
			cin>>station;
			pnt.s=m_si[station];
			cin>>station;
			pnt.e=m_si[station];
			g[pnt.s][pnt.e]=g[pnt.e][pnt.s]=1;
			cin>>pnt.w;
			pq.push(pnt);
		}
		memset(flag,0,sizeof(flag));
		flag[1]=1;
		dfs(1);
		bool no_ans=false;
		for(i=1;i<=n;i++)
			if(!flag[i])
			{
				no_ans=true;
				break;
			}
		cin>>station;
		if(no_ans)
		{
			cout<<"Impossible"<<endl;
			continue;
		}
		int key=0;
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
		cout<<key<<endl;
	}

return 0;
}
