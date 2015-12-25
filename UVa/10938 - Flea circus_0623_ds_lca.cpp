/*
10938 - Flea circus

data struct...
lca...
原来lca也不会很难嘛...
*/

#include<iostream>
#include<vector>
#define MAXN 5010
using namespace std;

struct TREE
{
	int idx,dep,fa;
}tree[MAXN];

int n;
vector<int> edge[MAXN];

void dfs(int u)
{
	int sz=edge[u].size();
	for(int i=0;i<sz;++i)
	{
		int v=edge[u][i];
		if(tree[v].dep==-1)
		{
			tree[v].dep=tree[u].dep+1;
			tree[v].fa=u;
			dfs(v);
		}
	}
}

int lca(int u,int v)
{
	while(tree[u].dep>tree[v].dep)
		u=tree[u].fa;
	while(u!=v)
		u=tree[u].fa,v=tree[v].fa;
	return u;
}

void query(int u,int v)
{
	if(tree[u].dep<tree[v].dep)
		swap(u,v);

	int key=lca(u,v);
	int pase=tree[u].dep+tree[v].dep-tree[key].dep*2;
	bool meet=pase%2==0;
	pase>>=1;

	while(tree[u].dep>tree[v].dep && pase>0)
		u=tree[u].fa,--pase;
	while(pase>0)
		u=tree[u].fa,pase--;
	v=tree[u].fa;

	if(u>v && !meet)
		swap(u,v);

	if(meet)
		printf("The fleas meet at %d.\n",u);
	else
		printf("The fleas jump forever between %d and %d.\n",u,v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;++i)
		{
			edge[i].clear();
			tree[i].idx=i;
			tree[i].dep=tree[i].fa=-1;
		}

		int u,v;
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		tree[1].dep=0;
		dfs(1);

		int q;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&u,&v);
			query(u,v);
		}
	}

	return 0;
}
