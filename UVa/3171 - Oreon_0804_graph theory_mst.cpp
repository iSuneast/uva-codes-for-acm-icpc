/*
3171 - Oreon

graph theory...
mst...
最小生成树...
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN 1000
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

struct EDGE
{
	int u,v,w;
	bool flag;
	bool operator<(const EDGE &t)const
	{
		if(w==t.w)
			return u<t.u;
		return w<t.w;
	}
}edge[MAXN];

int n,tot,fa[MAXN];
char s[MAXN];

void init()
{
	for(int i=0;i<n;++i)
		fa[i]=i;
}

int find(int u)
{
	return u==fa[u]?u:find(fa[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,i,j,k;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);gets(s);
		tot=0;
		for(i=0;i<n;++i)
		{
			gets(s);
			char *token=strtok(s," ,");
			for(j=0;j<n;++j)
			{
				edge[tot].u=i;
				edge[tot].v=j;
				edge[tot].flag=false;
				if(edge[tot].u>edge[tot].v)
					swap(edge[tot].u,edge[tot].v);
				sscanf(token,"%d",&edge[tot].w);
				if(edge[tot].w)
					++tot;
				token=strtok(NULL," ,");
			}
		}

		init();
		sort(edge,edge+tot);

		for(int i=0;i<tot;++i)
		{
			int a=find(edge[i].u),b=find(edge[i].v);
			if(a!=b)
			{
				edge[i].flag=true;
				fa[a]=b;
			}
		}

		printf("Case %d:\n",cas);
		for(int i=0;i<tot;++i)
			if(edge[i].flag)
				printf("%c-%c %d\n",edge[i].u+'A',edge[i].v+'A',edge[i].w);
	}


	return 0;
}
