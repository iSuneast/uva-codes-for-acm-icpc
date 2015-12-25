/*
615 - Is It A Tree?

graph theory...
判断图是否是一颗树
dfs一下就可以了...
*/

#include<iostream>
#include<map>
#include<vector>
#define MAXN 10000
using namespace std;

vector<int> edge[MAXN];
bool flag[MAXN],vis[MAXN],fade;

void dfs(int u)
{
	int sz=edge[u].size();
	for(int i=0;i<sz;++i)
	{
		int v=edge[u][i];
		if(!vis[v])
		{
			vis[v]=true;
			dfs(v);
		}
		else
			fade=true;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int u,v,cas=1;
	while(scanf("%d%d",&u,&v)!=EOF && u>=0 && v>=0)
	{
		if(u==0 && v==0)
		{
			printf("Case %d is a tree.\n",cas++);
			continue;
		}

		for(int i=0;i<MAXN;++i)
		{
			edge[i].clear();
			vis[i]=flag[i]=false;
		}

		fade=false;
		map<int,int> mii;
		int tot=0;
		if(mii.find(u)==mii.end())
			mii[u]=tot++;
		if(mii.find(v)==mii.end())
			mii[v]=tot++;
		else
			fade=true;

		u=mii[u];	v=mii[v];
		edge[u].push_back(v);
		flag[v]=true;

		while(scanf("%d%d",&u,&v)!=EOF && (u||v))
		{
			if(mii.find(u)==mii.end())
				mii[u]=tot++;
			if(mii.find(v)==mii.end())
				mii[v]=tot++;
			if(u==v)
				fade=true;
			else
			{
				u=mii[u];	v=mii[v];
				edge[u].push_back(v);
				flag[v]=true;
			}
		}

		for(int v=0;v<tot;++v)
			if(!flag[v])
			{
				vis[v]=true;
				dfs(v);
				for(int u=v+1;u<tot;++u)
					if(!flag[u])
						fade=true;
				break;
			}
			for(int u=0;u<tot;++u)
				if(!vis[u])
				{
					fade=true;
					break;
				}

		if(fade)
			printf("Case %d is not a tree.\n",cas++);
		else
			printf("Case %d is a tree.\n",cas++);
	}

	return 0;
}
