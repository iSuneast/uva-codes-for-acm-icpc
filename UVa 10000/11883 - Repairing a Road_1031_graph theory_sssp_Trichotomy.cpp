/*
 * 11883 - Repairing a Road
 *
 * graph theory...
 * sssp...
 *
 * use floyd to initialization the graph
 * enum edge (u,v)
 * ans = min( time[1,u] + time[v,n] + key1 )
 * ans = min( time[1,v] + time[u,n] + key2 )
 *
 * key is Minimum Distance Between (u,v)
 * key = time[1,u] + Add + v/pow(a,time[1,u]+Add)
 * use Trichotomy to calculate Add
 */

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

int n,m;
double g[MAXN][MAXN];
struct DATA
{
	int u,v;
	double vi,ai;
}data[505];

double calc(double vi,double ai,double t)
{
	double bgn=0,end=INF;
	while(fabs(bgn-end)>eps)
	{
		double m1=bgn+(end-bgn)/3.0;
		double m2=bgn+(end-bgn)*2.0/3.0;

		double k1=m1+vi/pow(ai,t+m1);
		double k2=m2+vi/pow(ai,t+m2);

		if(k1>k2)
			bgn=m1;
		else
			end=m2;
	}

	return bgn+vi/pow(ai,t+bgn);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		int u,v;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<i;++j)
				g[i][j]=g[j][i]=INF;
			g[i][i]=0;
		}

		for(int i=0;i<m;++i)
		{
			scanf("%d%d%lf%lf",&u,&v,&data[i].vi,&data[i].ai);
			data[i].u=u;
			data[i].v=v;

			g[u][v]=g[v][u]=min(g[u][v],data[i].vi);
		}

		for(int k=1;k<=n;++k)
		{
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}

		double key=INF;
		for(int i=0;i<m;++i)
		{
			u=data[i].u;
			v=data[i].v;

			double t=calc(data[i].vi,data[i].ai,g[1][u]);
			key=min(g[1][u]+g[v][n]+t,key);

			t=calc(data[i].vi,data[i].ai,g[1][v]);
			key=min(g[1][v]+g[u][n]+t,key);
		}

		printf("%.3lf\n",key);
	}

	return 0;
}

