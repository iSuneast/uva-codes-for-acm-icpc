/*
11690 - Money Matters

graph theory...
求连通分支...
*/

#include<iostream>
#include<vector>
#define MAXN 10010
#define eps 1e-9
using namespace std;

int ppl[MAXN],n,m,key;
bool flag[MAXN];
vector<int> next[MAXN];

void dfs(int u)
{
	key+=ppl[u];
	int sz=next[u].size();
	for(int i=0;i<sz;++i)
	{
		int v=next[u][i];
		if(!flag[v])
		{
			flag[v]=true;
			dfs(v);
		}
	}
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
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
		{
			scanf("%d",ppl+i);
			flag[i]=false;
			next[i].clear();
		}
		int u,v;
		for(int j=0;j<m;++j)
		{
			scanf("%d%d",&u,&v);
			next[u].push_back(v);
			next[v].push_back(u);
		}
		for(int i=0;i<n;++i)
			if(!flag[i])
			{
				key=0;
				flag[i]=true;
				dfs(i);
				if(key)
					break;
			}
		if(key)
			puts("IMPOSSIBLE");
		else
			puts("POSSIBLE");
	}

	return 0;
}
