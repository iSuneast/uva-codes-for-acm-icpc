/*
11159 - Factors and Multiples

graph theory...
binary match...

the only tricky of this problem is that a[] may have element 0
you can simple ignore it
if b[] also have element 0 ,we know that 0=0*0
*/

#include<iostream>
#define MAXN 103
using namespace std;

int na,a[MAXN],nb,b[MAXN],match[MAXN];
bool g[MAXN][MAXN],flag[MAXN];


bool dfs(int u)
{
	for(int v=0;v<nb;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			if(match[v]==-1 || dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	return false;
}

int hungry()
{
	memset(match,-1,sizeof(match));
	int key=0;
	for(int i=0;i<na;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=(dfs(i)?1:0);
	}
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
		scanf("%d",&na);
		for(int i=0;i<na;++i)
			scanf("%d",&a[i]);
		scanf("%d",&nb);
		memset(g,0,sizeof(g));
		for(int j=0;j<nb;++j)
		{
			scanf("%d",&b[j]);
			for(int i=0;i<na;++i)
				if(a[i] && b[j]%a[i]==0)
					g[i][j]=true;
				else if(a[i]==b[j])
					g[i][j]=true;
		}

		printf("Case %d: %d\n",cas,hungry());
	}

	return 0;
}
