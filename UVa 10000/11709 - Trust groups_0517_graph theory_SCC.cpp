/*
11709 - Trust groups

graph theory
SCC
图比较小
直接用tarjan就可以了...
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 1010
using namespace std;

bool g[MAXN][MAXN],g2[MAXN][MAXN],flag[MAXN];
int n,m,end[MAXN*2],pos;
char buf[13];

void dfs(int u,bool g[MAXN][MAXN])
{
	flag[u]=1;
	for(int v=0;v<n;++v)
		if(g[u][v] && !flag[v])
			dfs(v,g);
	end[--pos]=u;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		gets(buf);
		map<string,int> msi;
		for(int i=0;i<n;++i)
		{
			gets(buf);
			msi[buf]=i;
		}
		memset(g,0,sizeof(g));
		memset(g2,0,sizeof(g2));
		for(int i=0;i<m;++i)
		{
			gets(buf);
			int a=msi[buf];
			gets(buf);
			int b=msi[buf];
			g[a][b]=g2[b][a]=true;
		}
		memset(flag,0,sizeof(flag));
		pos=n;
		for(int i=0;i<n;++i)
			if(!flag[i])
				dfs(i,g);
		pos=n*2;
		int key=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;++i)
			if(!flag[end[i]])
			{
				++key;
				dfs(end[i],g2);
			}
		printf("%d\n",key);
	}

	return 0;
}
