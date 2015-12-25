/*
11792 - Krochanska is Here!

graph theory...
floyd-warshall...
求多元最短路...
建图是要删除没用的点...
不然直接搜的话会TLE
*/

#include<iostream>
#include<queue>
#include<vector>
#include<map>
#define MAXN 110
#define INF 0x7f7f7f7f
using namespace std;

int n,dis[MAXN][MAXN];
int flag[MAXN*100];
vector<int> edges[MAXN],vip;

void floyd_warshall(int n)
{
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(dis[i][k]!=INF && dis[k][j]!=INF)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int i=1;i<=dataset;++i)
	{
		int m,u,v;
		scanf("%d%d",&n,&m);
		memset(flag,-1,sizeof(flag));
		for(int i=0;i<m;++i)
			edges[i].clear();

		map<int,int> mii;
		int cnt=0;
		vip.clear();
		for(int i=0;i<m;++i)
			while(scanf("%d",&u)!=EOF && u)
			{
				edges[i].push_back(u);

				if(flag[u]==-2)
					continue;
				else if(flag[u]!=-1 && flag[u]!=i)
				{
					mii[u]=cnt++;
					vip.push_back(u);
					flag[u]=-2;
				}
				else
					flag[u]=i;
			}

		memset(dis,0x7f,sizeof(dis));
		for(int i=0;i<cnt;++i)
			dis[i][i]=0;
		for(int i=0;i<m;++i)
		{
			int sz=edges[i].size();
			u=-1;
			int p=-1;
			for(int j=0;j<sz;++j)
				if(flag[ v=edges[i][j] ]==-2)
				{
					v=mii[v];
					if(u!=-1)
						dis[u][v]=dis[v][u]=min((j-p)*2,dis[u][v]);
					u=v;
					p=j;
				}
		}
		floyd_warshall(cnt);
		int ans=INF,p;
		for(int i=0;i<cnt;++i)
		{
			int t=0;
			for(int j=0;j<cnt;++j)
				t+=dis[i][j];
			if(t<ans)
			{
				ans=t;
				p=vip[i];
			}
			else if(t==ans)
				p=min(vip[i],p);
		}

		printf("Krochanska is in: %d\n",p);
	}

	return 0;
}
