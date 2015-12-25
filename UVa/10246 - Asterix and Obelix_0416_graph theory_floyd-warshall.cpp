/*
10246 - Asterix and Obelix

graph theory...
floyd-warshall...
非常非常神奇的代码...
竟然说要两次floyd才可以AC...
简直就是前无古人.后无来者...
orz...UVa的神牛...
*/

#include<iostream>
#define MAXN 86
#define INF 1e9
using namespace std;

int c,r,q,w[MAXN];
int g[2][MAXN][MAXN];

void floyd_warshall()
{
	for(int k=1;k<=c;++k)
		for(int i=1;i<=c;++i)
			for(int j=1;j<=c;++j)
			{
				int v1=g[0][i][j]+g[1][i][j];
				int v2=g[0][i][k]+g[0][k][j]+max(g[1][i][k],g[1][k][j]);
				if(v1>v2)
				{
					g[0][i][j]=g[0][i][k]+g[0][k][j];
					g[1][i][j]=max(g[1][i][k],g[1][k][j]);
				}
			}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1;
	while(cin>>c>>r>>q && (c||r||q))
	{
		if(cas!=1)
			cout<<endl;
		int i,s,e,d;
		for(i=1;i<=c;++i)
			cin>>w[i];
		for(i=1;i<=c;++i)
		{
			for(int j=1;j<=c;++j)
			{
				g[0][i][j]=INF;
				g[1][i][j]=max(w[i],w[j]);
			}
			g[0][i][i]=0;
		}
		for(i=0;i<r;++i)
		{
			cin>>s>>e>>d;
			g[0][e][s]=g[0][s][e]=min(g[0][s][e],d);
		}
		floyd_warshall();
		floyd_warshall();		//好神奇啊...竟然说要两次floyd才可以
		cout<<"Case #"<<cas++<<endl;
		for(i=0;i<q;++i)
		{
			cin>>s>>e;
			if(g[0][s][e]==INF)
				cout<<-1<<endl;
			else
				cout<<g[0][s][e]+g[1][s][e]<<endl;
		}
	}

	return 0;
}
