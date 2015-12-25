/*
988 - Many Paths, One Destination

graph theory...
dag...
算dag中路径条数...
先toposort...
然后从0开始算路径即可...
*/

#include<iostream>
#include<vector>
#define MAXN 3000
using namespace std;

vector<int> edge[MAXN];
int sz[MAXN],n,u,v,tot,topo[MAXN];
bool flag[MAXN];
long long cnt[MAXN];

void dfs(int u)
{
	flag[u]=true;
	for(int i=0;i<sz[u];++i)
		if(!flag[ edge[u][i] ])
			dfs(edge[u][i]);
	topo[--tot]=u;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	bool first=true;
	while(scanf("%d",&n)!=EOF)
	{
		if(!first)
			putchar('\n');
		first=false;

		for(int i=0;i<n;++i)
		{
			edge[i].clear();
			flag[i]=false;
			cnt[i]=0;
			scanf("%d",sz+i);
			for(int j=0;j<sz[i];++j)
			{
				scanf("%d",&u);
				edge[i].push_back(u);
			}
		}
		tot=n;
		dfs(0);
		cnt[0]=1;
		for(int i=tot;i<n;++i)
		{
			u=topo[i];
			for(int j=0;j<sz[u];++j)
				cnt[ edge[u][j] ]+=cnt[u];
		}
		long long key=0;
		for(int i=0;i<n;++i)
			if(!sz[i] && flag[i])
				key+=cnt[i];

		printf("%lld\n",key);
	}

	return 0;
}
