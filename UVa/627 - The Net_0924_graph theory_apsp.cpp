/*
627 - The Net

graph theory...
apsp...
use floyd to initiate the distance array
then use dfs to output the path
*/

#include<iostream>
#define MAXN 303
using namespace std;
const int INF=0x3f3f3f3f;

int g[MAXN][MAXN],n;
char buf[MAXN];

void input()
{
	int u,v;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%*c",&u);
		gets(buf);
		for(int j=1;j<=n;++j)
			g[u][j]=INF;
		char *token=strtok(buf,",");
		while(token)
		{
			v=atoi(token);
			g[u][v]=1;
			token=strtok(NULL,",");
		}
	}
}

void floyd()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void output(int u,int v)
{
	for(int i=1;i<=n;++i)
		if(g[u][i]+g[i][v]==g[u][v])
		{
			output(u,i);
			output(i,v);
			return ;
		}
		printf(" %d",v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int u,v,m;
	while(scanf("%d",&n)!=EOF)
	{
		input();
		floyd();
		scanf("%d",&m);
		puts("-----");
		while(m--)
		{
			scanf("%d%d",&u,&v);
			if(g[u][v]==INF)
				puts("connection impossible");
			else
			{
				printf("%d",u);
				output(u,v);
				putchar(10);
			}
		}
	}

	return 0;
}
