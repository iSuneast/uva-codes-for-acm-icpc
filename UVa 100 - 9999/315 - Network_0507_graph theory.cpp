/*
315 - Network

graph theory...
求割点...
直接暴力枚举即可...
*/

#include<iostream>
#define MAXN 110
using namespace std;

int nodes;
char buf[1000];
bool g[MAXN][MAXN],flag[MAXN],tmp[MAXN];

void dfs(int u)
{
	if(flag[u])
		return ;
	flag[u]=1;
	for(int v=1;v<=nodes;++v)
		if(g[u][v])
			dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&nodes)!=EOF && nodes)
	{
		int start,next,key=0;
		memset(g,0,sizeof(g));
		while(scanf("%d",&start)!=EOF && start)
		{
			gets(buf);
			char *token=strtok(buf," ");
			while(token)
			{
				sscanf(token,"%d",&next);
				g[start][next]=g[next][start]=1;
				token=strtok(NULL," ");
			}
		}
		for(int i=1;i<=nodes;++i)
		{
			memset(flag,0,sizeof(flag));
			for(int j=1;j<=nodes;++j)
			{
				tmp[j]=g[i][j];
				g[i][j]=g[j][i]=0;
			}
			flag[i]=1;
			if(i!=nodes)
				dfs(i+1);
			else
				dfs(i-1);
			for(int j=1;j<=nodes;++j)
				if(!flag[j])
				{
					++key;
					break;
				}
			for(int j=1;j<=nodes;++j)
				g[i][j]=g[j][i]=tmp[j];
		}
		printf("%d\n",key);
	}

	return 0;
}
