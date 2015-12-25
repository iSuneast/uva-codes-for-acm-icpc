/*
11280 - Flying to Fredericton

graph theory...
sssp...
找最短路...
不过有边限制...
那就索性bfs暴搜一次算了...
一层一层地来...
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 110
#define INF 0x7f7f7f7f
using namespace std;

int n,m;
int g[MAXN][MAXN],dis[MAXN][MAXN];
string name;

void bfs()
{
	memset(dis,0x7f,sizeof(dis));
	dis[0][0]=0;
	for(int dep=0;dep<=n;++dep)
	{
		for(int i=0;i<n;++i)
			dis[dep+1][i]=dis[dep][i];
		for(int i=0;i<n;++i)
		{
			if(dis[dep][i]!=INF)
				for(int j=0;j<n;++j)
					if(g[i][j]!=INF && dis[dep+1][j]>dis[dep][i]+g[i][j])
						dis[dep+1][j]=dis[dep][i]+g[i][j];
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>n;
		map<string,int> msi;
		for(int i=0;i<n;++i)
		{
			cin>>name;
			msi[name]=i;
		}
		cin>>m;
		memset(g,0x7f,sizeof(g));
		int u,v,w;
		while(m--)
		{
			cin>>name;	u=msi[name];
			cin>>name;	v=msi[name];
			cin>>w;
			g[u][v]=min(g[u][v],w);
		}

		bfs();

		cout<<"Scenario #"<<cas<<endl;
		int query,dep;
		cin>>query;
		while(query--)
		{
			cin>>dep;
			dep=min(dep+1,n-1);
			if(dis[dep][n-1]!=INF)
				cout<<"Total cost of flight(s) is $"<<dis[dep][n-1]<<endl;
			else
				cout<<"No satisfactory flights"<<endl;
		}
		if(cas!=dataset)
			cout<<endl;
	}

	return 0;
}
