/*
11893 - Fabulous DAGy

graph theory...
binary match...

in a DAG graph, there is no loop...
*
* plus one additional directed edge. 
* With this additional edge a cycle forms that
* goes through every vertex in the graph. 
*
so there is only a big cycle in the graph
we can use Binary Match to check the Cycle.

a node only have one InDegree and one OutDegree
so if we can find a maximum match = N,
every node is obviously in the same cycle

because it's a special DAG graph with only one 
	additional directed edge
we won't got more than one cycle...
so the finally answer is unique
*/

#include<iostream>
#define MAXN 407
using namespace std;

bool g[MAXN][MAXN],flag[MAXN];
int n,m,match[MAXN];

bool dfs(int u)
{
	for(int v=0;v<n;++v)
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
	for(int i=0;i<n;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i)?1:0;
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,u,v;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		memset(g,0,sizeof(g));
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			g[u][v]=true;
		}

		puts(hungry()==n?"Yeah, I'm superman":
			"Your DAGy was initially defected!");
	}

	return 0;
}
