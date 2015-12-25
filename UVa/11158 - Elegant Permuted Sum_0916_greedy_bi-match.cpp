/*
11158 - Elegant Permuted Sum

greedy...
bi-match...
there exist a simple greedy solution
but be more complex, we can solve it by using maximum weight binary match

construct the matrix g[i][j]=abs(var[i]-var[j])
enum the last value k, set g[k][]=0
we should set g[x][x]=-INF, because the value can't match with itself
run km(), and choose the max answer

total run in O(n*n^3) time
*/

#include<iostream>
#define MAXN 51
using namespace std;
const int INF=0x3f3f3f3f;

int g[MAXN][MAXN],n,var[MAXN];
int x[MAXN],y[MAXN],match[MAXN],buf[MAXN],slack;
bool visX[MAXN],visY[MAXN];

bool dfs(int u)
{
	visX[u]=true;
	for(int v=0;v<n;++v)
	{
		if(visY[v])
			continue;
		if(x[u]+y[v]==g[u][v])
		{
			visY[v]=true;
			if(match[v]==-1 || dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
		else
			slack=min(slack,x[u]+y[v]-g[u][v]);
	}

	return false;
}

int km()
{
	for(int i=0;i<n;++i)
	{
		x[i]=g[i][0];
		for(int j=1;j<n;++j)
			x[i]=max(x[i],g[i][j]);
		y[i]=0;
		match[i]=-1;
	}

	for(int k=0;k<n;++k)
	{
		while(true)
		{
			memset(visX,0,sizeof(visX));
			memset(visY,0,sizeof(visY));

			slack=INF;
			if(dfs(k))
				break;

			for(int i=0;i<n;++i)
				if(visX[i])
					x[i]-=slack;

			for(int j=0;j<n;++j)
				if(visY[j])
					y[j]+=slack;
		}
	}

	int key=0;
	for(int i=0;i<n;++i)
		key+=g[ match[i] ][i];

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
			for(int j=0;j<i;++j)
				g[i][j]=g[j][i]=abs(var[i]-var[j]);
		}

		int key=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				buf[j]=g[i][j];
				g[i][j]=0;
			}
			g[i][i]=-INF;

			key=max(key,km());

			for(int j=0;j<n;++j)
				g[i][j]=buf[j];
		}

		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
