/*
10803 - Thunder Mountain

graph theory...
floyd-warshall...
晕...
刚没多久没做图论的题....
就生疏了不少...
竟然把图建成有向边...
Orz...
*/

#include<iostream>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 110
#define MAXDIS 10
#define INF 1e9
using namespace std;
typedef pair<double,double> pdd;

pdd pnt[MAXN];
double g[MAXN][MAXN];
int n;

void floyd_warshall()
{
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
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
		int i,j;
		double dx,dy,d;
		memset(g,0,sizeof(g));
		cin>>n;
		for(i=0;i<n;++i)
		{
			cin>>pnt[i].first>>pnt[i].second;
			for(j=0;j<i;++j)
			{
				dx=pnt[i].first-pnt[j].first;
				dy=pnt[i].second-pnt[j].second;
				d=dx*dx+dy*dy;
				if(d>MAXDIS*MAXDIS)
					g[i][j]=g[j][i]=INF;
				else
					g[i][j]=g[j][i]=sqrt(d);
			}
		}
		floyd_warshall();
		double key=0;
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				key=max(key,g[i][j]);
		cout<<"Case #"<<cas<<":"<<endl;
		if(key==INF)
			puts("Send Kurdy");
		else
			printf("%.4lf\n",key);
		putchar('\n');
	}

	return 0;
}
