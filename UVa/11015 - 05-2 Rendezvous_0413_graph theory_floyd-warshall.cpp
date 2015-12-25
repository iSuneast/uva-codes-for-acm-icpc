/*
11015 - 05-2 Rendezvous

graph theory...
floyd_warshall...
无数次WA...
说实话除了memset忘了写我无语之外...
实在找不到是什么地方让我无数次WA...
*/

#include<iostream>
#include<string>
#define INF 1e5
#define MAXN 30
using namespace std;

int n,m,g[MAXN][MAXN];
string place[MAXN];

void floyd_warshall()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("11015.txt","w",stdout);

	int cas=1;
	while(cin>>n>>m && n)
	{
		getchar();
		int i,j,s,e,w;
		memset(g,0,sizeof(g));
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
				g[i][j]=INF;
			g[i][i]=0;
		}
		for(i=1;i<=n;++i)
			getline(cin,place[i]);
		for(i=0;i<m;++i)
		{
			cin>>s>>e>>w;
			g[s][e]=g[e][s]=w;
		}
		floyd_warshall();
		int key=1;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
				g[i][0]+=g[i][j];
			key=g[key][0]<=g[i][0]?key:i;
		}
		cout<<"Case #"<<cas++<<" : "<<place[key]<<endl;
	}

	return 0;
}
