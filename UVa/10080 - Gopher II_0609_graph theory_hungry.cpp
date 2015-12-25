/*
10080 - Gopher II

graph theory...
hungry...
ÐÙÑÀÀû...
*/

#include<iostream>
#define MAXN 110
using namespace std;

struct POINT
{
	double x,y;
}hole,gopher[MAXN];

int n,m,match[MAXN*2],tot;
double s,v;
bool g[MAXN*2][MAXN*2],flag[MAXN*2];

int dfs(int u)
{
	for(int v=0;v<tot;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			int t=match[v];
			match[v]=u;
			if(t==-1 || dfs(t))
				return 1;
			match[v]=t;
		}
	return 0;
}

int hungry()
{
	int key=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<tot;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key;
}

bool ok(POINT &a,POINT &b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return dx*dx+dy*dy<=s;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d%lf%lf",&n,&m,&s,&v)!=EOF)
	{
		s*=v;
		s*=s;
		tot=n+m;

		for(int i=0;i<n;++i)
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		memset(g,0,sizeof(g));
		for(int j=0;j<m;++j)
		{
			scanf("%lf%lf",&hole.x,&hole.y);
			for(int i=0;i<n;++i)
				if(ok(hole,gopher[i]))
					g[i][j+n]=g[j+n][i]=true;
		}

		printf("%d\n",n-hungry()/2);
	}

	return 0;
}
