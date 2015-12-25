/*
820 - Internet Bandwidth

graph theory...
max-flow...
没什么要注意的...
*/

#include<iostream>
#include<queue>
#define MAXN 110
#define INF 1e9
using namespace std;

int cap[MAXN][MAXN],n,start,target;
int flow[MAXN][MAXN],remflow[MAXN],fa[MAXN];

int edmonds_karp()
{
	memset(flow,0,sizeof(flow));
	queue<int> q;
	int key=0,u,v;
	while(true)
	{
		memset(remflow,0,sizeof(remflow));
		remflow[start]=INF;
		q.push(start);
		while(!q.empty())
		{
			u=q.front();	q.pop();
			for(v=1;v<=n;++v)
				if(!remflow[v] && cap[u][v]>flow[u][v])
				{
					fa[v]=u;
					q.push(v);
					remflow[v]=min(remflow[u],cap[u][v]-flow[u][v]);
				}
		}
		if(remflow[target]==0)
			return key;
		for(u=target;u!=start;u=fa[u])
		{
			flow[fa[u]][u]+=remflow[target];
			flow[u][fa[u]]-=remflow[target];
		}
		key+=remflow[target];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1;
	while(cin>>n && n)
	{
		int path,s,e,c;
		cin>>start>>target>>path;
		memset(cap,0,sizeof(cap));
		for(int i=0;i<path;++i)
		{
			cin>>s>>e>>c;
			cap[s][e]+=c;
			cap[e][s]+=c;
		}
		cout<<"Network "<<cas++<<endl
			<<"The bandwidth is "<<edmonds_karp()<<"."<<endl<<endl;
	}

	return 0;
}
