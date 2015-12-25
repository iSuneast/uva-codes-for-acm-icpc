/*
10099 - The Tourist Guide

MST...
额...
慢慢熟练吧...
*/

#include<iostream>
#include<cmath>
#include<queue>
#define MAXN 110
#define INF 1e8 
using namespace std;

int g[MAXN][MAXN],p[MAXN],n,r;

struct graph	{	int s,d,t;	}pnt;
struct cmp
{
	bool operator()(graph a,graph b)
	{	return a.t<b.t;	}
};

int find(int d)
{	return d==p[d]?d:p[d]=find(p[d]);	}

void dfs(int s)
{
	for(int i=1;i<=n;++i)
		if(!p[i] && g[s][i])
		{
			p[i]=g[s][i]<p[s]?g[s][i]:p[s];
			dfs(i);
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10099.txt","w",stdout);

	int cas=1;
	while(cin>>n>>r && (n||r))
	{
		int i;
		priority_queue<graph,vector<graph>,cmp> q;
		for(i=0;i<r;i++)
		{
			cin>>pnt.s>>pnt.d>>pnt.t;
			q.push(pnt);
		}
		for(i=0;i<=n;i++)
			p[i]=i;
		memset(g,0,sizeof(g));
		for(i=0;i<r;i++)
		{
			pnt=q.top();
			q.pop();
			int x=find(pnt.s),y=find(pnt.d);
			if(x!=y)
			{
				p[x]=y;
				g[pnt.s][pnt.d]=g[pnt.d][pnt.s]=pnt.t;
			}
		}
		memset(p,0,sizeof(p));
		cin>>pnt.s>>pnt.d>>pnt.t;
		p[pnt.s]=INF;
		dfs(pnt.s);
		int key=pnt.t/(p[pnt.d]-1);
	//补充一下,我说过很多次了...不要直接copy以上的代码...
	//楼下有个傻×错误if(pnt.t/(p[pnt.d]-1))让我WA了好几次.
		if(pnt.t%(p[pnt.d]-1))		//不要用ceil.
			++key;
		cout<<"Scenario #"<<cas++<<endl
			<<"Minimum Number of Trips = "<<key<<endl<<endl;
	}

return 0;
}
