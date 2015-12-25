/*
208 - Firetruck

graph theory...
backtracking...
直接从源点开始按标号从小到大dfs回溯即可...
*/

#include<iostream>
#define MAXN 21
using namespace std;

int s,tot;
bool flag[MAXN],g[MAXN][MAXN],vis[MAXN];

void dfs_vis(int u)
{
	flag[u]=true;
	for(int v=1;v<MAXN;++v)
		if(g[u][v] && !flag[v])
			dfs_vis(v);
}

int ans[MAXN];

void dfs(int u,int dep)
{
	if(u==s)
	{
		++tot;
		putchar('1');
		for(int i=1;i<dep;++i)
			printf(" %d",ans[i]);
		putchar('\n');
	}
	else for(int v=1;v<MAXN;++v)
		if(flag[v] && g[u][v] && !vis[v])
		{
			vis[v]=true;
			ans[dep]=v;
			dfs(v,dep+1);
			vis[v]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&s)!=EOF && s)
	{
		int u,v;
		memset(g,0,sizeof(g));
		while(scanf("%d%d",&u,&v)!=EOF && (u||v))
			g[u][v]=g[v][u]=true;

		memset(flag,0,sizeof(flag));
		dfs_vis(s);

		printf("CASE %d:\n",cas++);
		memset(vis,0,sizeof(vis));
		ans[0]=1;	vis[1]=true;
		tot=0;	dfs(1,1);
		printf("There are %d routes from the firestation to streetcorner %d.\n",tot,s);
	}

	return 0;
}
