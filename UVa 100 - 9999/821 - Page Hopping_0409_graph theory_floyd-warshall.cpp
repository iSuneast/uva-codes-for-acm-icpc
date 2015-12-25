/*
821 - Page Hopping

floyd-warshall...
似乎一点都没有改变嘛...
*/

#include<iostream>
#define INF 1e9
#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)
#define MAXN 110
using namespace std;

int g[MAXN][MAXN],n;

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

	int s,e,i,j,cas=1;
	while(cin>>s>>e && (s||e))
	{
		for(i=0;i<MAXN;++i)
			for(j=0;j<MAXN;++j)
				g[i][j]=INF;
		n=0;
		g[s][e]=1;
		n=max(n,max(s,e));
		while(cin>>s>>e && (s||e))
		{
			n=max(n,max(s,e));
			g[s][e]=1;
		}
		floyd_warshall();
		double key=0;
		int cnt=0;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				if(i!=j && g[i][j]!=INF)
				{
					key+=g[i][j];
					++cnt;		//这里是累加路径个数,不是n*(n-1)
				}
		printf("Case %d: average length between pages = %.3lf clicks\n",
			cas++,key/cnt);
	}
	return 0;
}
