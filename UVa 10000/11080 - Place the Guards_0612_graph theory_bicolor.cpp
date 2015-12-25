/*
11080 - Place the Guards

graph theory...
图的二着色...
*/

#include<iostream>
#include<queue>
#define MAXN 210
using namespace std;

int v,e,match[MAXN];
bool g[MAXN][MAXN],flag[MAXN];

int bfs(int u)
{
	int color[2]={0};
	memset(flag,0,sizeof(flag));
	queue<int> q;
	q.push(u);
	match[u]=1;
	flag[u]=true;
	color[ match[u] ]++;

	while(!q.empty())
	{
		u=q.front();	q.pop();
		for(int i=0;i<v;++i)
			if(g[u][i])
			{
				if(!flag[i])
				{
					match[i]=1-match[u];
					color[ match[i] ]++;
					flag[i]=true;
					q.push(i);
				}
				else if(match[i]==match[u])
						return -1;
			}
	}
	if(!color[0])
		return color[1];
	return min(color[0],color[1]);
}

int bi_color()
{
	memset(match,-1,sizeof(match));
	int key=0,cur;
	for(int i=0;i<v;++i)
		if(match[i]==-1)
		{
			if((cur=bfs(i))==-1)
				return -1;
			key+=cur;
		}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int a,b;
		memset(g,0,sizeof(g));

		scanf("%d%d",&v,&e);
		while(e--)
		{
			scanf("%d%d",&a,&b);
			g[a][b]=g[b][a]=true;
		}
		printf("%d\n",bi_color());
	}

	return 0;
}
