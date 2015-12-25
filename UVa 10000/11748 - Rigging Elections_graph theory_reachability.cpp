/*
11748 - Rigging Elections

graph theory...
reachability...
枚举所有获选人的组合
胜出的人向败者连一条有向边
最后,如果从c出发,所有点可达则获胜...
*/

#include<iostream>
#define MAXN 103
using namespace std;

int rank[MAXN][MAXN];
bool g[MAXN][MAXN],flag[MAXN];
int n,m,c;

void dfs(int u)
{
	flag[u]=true;
	for(int v=1;v<=n;++v)
		if(g[u][v] && !flag[v])
			dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d%d",&n,&m,&c)!=EOF && (n||m||c))
	{
		int w;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				scanf("%d",&w);
				rank[i][w]=j;
			}
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
			{
				int a=0,b=0;
				for(int k=1;k<=m;++k)
					if(rank[k][i]<rank[k][j])
						++a;
					else
						++b;
				a>b?g[i][j]=true:g[j][i]=true;
			}
		memset(flag,0,sizeof(flag));
		dfs(c);
		bool bk=false;
		for(int i=1;i<=n && !bk;++i)
			if(!flag[i])
				bk=true;
		puts(bk?"no":"yes");
	}

	return 0;
}
