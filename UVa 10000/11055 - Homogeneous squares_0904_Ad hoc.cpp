/*
11055 - Homogeneous squares

Ad hoc...
it's not so obvious that we can just chk every 2*2 matrix
if format g[i][j]+g[i-1][j-1]==g[i][j-1]+g[i-1][j]
is always true, then the answer is true

a binary-match solution you may come up with at first
if the MaxMatch==MinMatch the answer is true
but the KM algorithm run in O(n^3) time will cause TLE
*/

#include<iostream>
#define MAXN 1003
using namespace std;

int n,g[MAXN][MAXN];

bool chk()
{
	for(int i=1;i<n;++i)
		for(int j=1;j<n;++j)
			if(g[i][j]+g[i-1][j-1]!=g[i][j-1]+g[i-1][j])
				return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				scanf("%d",&g[i][j]);
		}
		puts(chk()?"homogeneous":"not homogeneous");
	}

	return 0;
}

/*
int x[MAXN],y[MAXN],match[MAXN];
bool visX[MAXN],visY[MAXN];

bool dfs(int u)
{
	visX[u]=true;
	for(int v=0;v<n;++v)
		if(!visY[v] && x[u]+y[v]==g[u][v])
		{
			visY[v]=true;
			if(match[v]==-1 || dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	return false;
}

int kmMaxMatch()
{
	memset(match,-1,sizeof(match));
	memset(y,0,sizeof(y));

	for(int i=0;i<n;++i)
	{
		x[i]=g[i][0];
		for(int j=1;j<=n;++j)
			x[i]=max(x[i],g[i][j]);
	}

	for(int k=0;k<n;++k)
	{
		while(true)
		{
			memset(visX,0,sizeof(visX));
			memset(visY,0,sizeof(visY));
			if(dfs(k))
				break;

			int d=INF;
			for(int i=0;i<n;++i)
				if(visX[i])
					for(int j=0;j<n;++j)
						if(!visY[j])
							d=min(d,x[i]+y[j]-g[i][j]);

			for(int i=0;i<n;++i)
				if(visX[i])
					x[i]-=d;
			for(int j=0;j<n;++j)
				if(visY[j])
					y[j]+=d;
		}
	}

	int key=0;
	for(int j=0;j<n;++j)
		if(match[j]!=-1)
			key+=g[ match[j] ][j];

	return key;
}

bool chk()
{
	int key=kmMaxMatch();
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			g[i][j]=-g[i][j];

	return key==-kmMaxMatch();
}
*/
