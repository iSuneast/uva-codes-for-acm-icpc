/*
10947 - Bear with me, again..

graph theory...
cc...
if two island's distance is less than k*m+r1+r2
we connect them
finally dfs check whether the start is connected with end...
*/

#include<iostream>
#define MAXN 110
using namespace std;

struct DATA
{
	int x,y,r;
}data[MAXN];
int k,m,n;
bool g[MAXN][MAXN],flag[MAXN];

int sqr(int n)
{
	return n*n;
}

int dis(DATA &a,DATA &b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}

void dfs(int u)
{
	flag[u]=true;
	for(int v=0;v<n;++v)
		if(g[u][v] && !flag[v])
			dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&k,&m)!=EOF)
	{
		scanf("%d%d%d",&data[0].x,&data[0].y,&data[0].r);
		scanf("%d%d%d",&data[1].x,&data[1].y,&data[1].r);
		scanf("%d",&n);
		n+=2;

		memset(g,0,sizeof(g));
		if(dis(data[0],data[1])<=sqr(k*m+data[0].r+data[1].r))
			g[0][1]=g[1][0]=true;

		for(int i=2;i<n;++i)
		{
			scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].r);
			for(int j=0;j<i;++j)
				if(dis(data[i],data[j])<=sqr(k*m+data[i].r+data[j].r))
					g[i][j]=g[j][i]=true;
		}

		memset(flag,0,sizeof(flag));
		dfs(0);
		puts(flag[1]?"Larry and Ryan will escape!"
			:"Larry and Ryan will be eaten to death.");
	}

	return 0;
}
