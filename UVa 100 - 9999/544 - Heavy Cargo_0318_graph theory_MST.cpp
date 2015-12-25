/*
544 - Heavy Cargo

这题太集成了...
MST.	最大生成树
DFS.	深度优先搜索
PQ.		优先队列
set.	并查集
*/

#include<iostream>
#include<map>
#include<queue>
#include<string>
#define MAXN 210
#define INF 1e8
using namespace std;

int g[MAXN][MAXN],p[MAXN],n;

struct graph	{	int s,e,w;	}pnt;
struct cmp
{
	bool operator()(graph a,graph b)
	{	return a.w<b.w;	}
};
int find(int x)
{	return p[x]==x?x:p[x]=find(p[x]);	}

int dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(!p[i] && g[x][i])
		{
			p[i]=g[x][i]<p[x]?g[x][i]:p[x];
			dfs(i);
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int r,cas=1;
	while(cin>>n>>r && (n||r))
	{
		int i,cnt=0;
		string start,target;
		map<string,int> m;
		priority_queue<graph,vector<graph>,cmp> q;
		for(i=0;i<r;i++)
		{
			cin>>start>>target>>pnt.w;
			if(m.find(start)==m.end())
				m[start]=++cnt;
			if(m.find(target)==m.end())
				m[target]=++cnt;
			pnt.s=m[start];
			pnt.e=m[target];
			q.push(pnt);
		}
		memset(p,0,sizeof(p));
		for(i=1;i<=n;i++)
			p[i]=i;
		memset(g,0,sizeof(g));
		for(i=0;i<r;i++)
		{
			pnt=q.top();
			q.pop();
			int x=find(pnt.s),y=find(pnt.e);
			if(x!=y)
			{
				p[x]=y;
				g[pnt.s][pnt.e]=g[pnt.e][pnt.s]=pnt.w;
			}
		}
		cin>>start>>target;
		memset(p,0,sizeof(p));
		p[ m[start] ]=INF;
		dfs(m[start]);
		cout<<"Scenario #"<<cas++<<endl
			<<p[ m[target] ]<<" tons"<<endl
			<<endl;
	}

return 0;
}
