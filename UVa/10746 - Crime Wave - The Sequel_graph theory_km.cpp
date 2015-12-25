/*
10746 - Crime Wave - The Sequel

graph theory...
KM...
二分图的最小权匹配...
对边取反就可以了...

注意输出那边有精度问题...
所以要加上eps...
*/

#include<iostream>
#include<cmath>
#define INF 0x3f3f3f3f
#define eps 1e-6
#define MAXN 25
using namespace std;

int n,m;
double w[MAXN][MAXN],x[MAXN],y[MAXN],slack[MAXN];
int match[MAXN];
bool visx[MAXN],visy[MAXN];

bool dfs(int u)
{
	visx[u]=true;
	for(int v=0;v<m;++v)
		if(!visy[v] && fabs(x[u]+y[v]-w[u][v])<eps)
		{
			visy[v]=true;
			if(match[v]==-1 || dfs( match[v] ))
			{
				match[v]=u;
				return true;
			}
		}
		return false;
}

void km()
{
	memset(match,-1,sizeof(match));
	memset(y,0,sizeof(y));

	for(int i=0;i<n;++i)
	{
		x[i]=w[i][0];
		for(int j=1;j<m;++j)
			x[i]=max(x[i],w[i][j]);
	}

	for(int k=0;k<m;++k)
	{
		while(true)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(k))
				break;
			double d=INF;

			for(int i=0;i<n;++i)
				if(visx[i])
					for(int j=0;j<m;++j)
						if(!visy[j])
							d=min(d,x[i]+y[j]-w[i][j]);
			for(int i=0;i<n;++i)
				if(visx[i])
					x[i]-=d;
			for(int j=0;j<m;++j)
				if(visy[j])
					y[j]+=d;
		}
	}

	double key=0;
	for(int i=0;i<m;++i)
		if(match[i]!=-1)
			key+=w[ match[i] ][i];

	printf("%.2lf\n",-key/n+eps);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				scanf("%lf",&w[i][j]);
				w[i][j]*=-1;
			}
		km();
	}

	return 0;
}
