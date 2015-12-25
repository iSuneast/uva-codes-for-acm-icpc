/*
11419 - SAM I AM

graph theory...
max-match...
min vertex cover
最小路径覆盖...
先hungry求出最大匹配...

令左边为r,点表示为u,右边为c,点表示为v
matched[u](bool)代表u被匹配过,match[v](int)代表和v匹配
g[u][v]=1代表未匹配边,标记g[ match[v] ][v]=-1代表匹配边

从r开始,寻找u,满足matched[u]=false,走一条g[u][v]=1的边到达v
从v开始,走一条g[u][v]=-1的边到达u'
如此反复,走过的点打上标记vis_r[u],vis_c[v]

最后的答案是满足
对u : matched[u] && !vis_r[u]
	即有一条匹配边连接u,并且u未被访问过
对v : match[v]!=-1 && vis_c[v]
	即有一条匹配边连接v,并且v被访问过

此即最小路径覆盖...
*/

#include<iostream>
#define MAXN 1003
using namespace std;

int r,c,n;
char g[MAXN][MAXN];

int match[MAXN];
bool flag[MAXN];

int dfs(int u)
{
	for(int v=1;v<=c;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			if(match[v]==-1 || dfs(match[v]))
			{
				match[v]=u;
				return 1;
			}
		}
	return 0;
}

int hungry()
{
	memset(match,-1,sizeof(match));
	int key=0;
	for(int i=1;i<=r;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key;
}

bool matched[MAXN],vis_r[MAXN],vis_c[MAXN];

void dfs_r(int);

void dfs_c(int v)
{
	for(int u=1;u<=r;++u)
		if(g[u][v]==-1 && !vis_r[u])
		{
			vis_r[u]=true;
			dfs_r(u);
		}
}

void dfs_r(int u)
{
	for(int v=1;v<=c;++v)
		if(g[u][v]==1 && !vis_c[v])
		{
			vis_c[v]=true;
			dfs_c(v);
		}
}

void process()
{
	printf("%d",hungry());

	memset(matched,0,sizeof(matched));
	for(int v=1;v<=c;++v)
		if(match[v]!=-1)
		{
			matched[ match[v] ]=true;
			g[ match[v] ][v]=-1;
		}

	memset(vis_r,0,sizeof(vis_r));
	memset(vis_c,0,sizeof(vis_c));
	for(int u=1;u<=r;++u)
		if(!matched[u])
			dfs_r(u);

	for(int u=1;u<=r;++u)
		if(matched[u] && !vis_r[u])
			printf(" r%d",u);
	for(int v=1;v<=c;++v)
		if(match[v]!=-1 && vis_c[v] )
			printf(" c%d",v);

	putchar(10);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d%d",&r,&c,&n)!=EOF && (r||c||n))
	{
		int u,v;
		memset(g,0,sizeof(g));
		while(n--)
		{
			scanf("%d%d",&u,&v);
			g[u][v]=1;
		}
		process();
	}

	return 0;
}
