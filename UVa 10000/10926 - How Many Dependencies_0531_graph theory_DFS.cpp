/*
10926 - How Many Dependencies?

graph theory...
DFS...
对这种规模的题没必要想的复杂了...
直接对每个点dfs暴搜即可...
dp的话状态判断也太复杂了点...
*/

#include<iostream>
#include<vector>
#define MAXN 110
using namespace std;

int n,sz[MAXN],cnt;
vector<int> vi[MAXN];
bool flag[MAXN];

void dfs(int u)
{
	for(int i=0;i<sz[u];++i)
	{
		int v=vi[u][i];
		if(!flag[v])
		{
			flag[v]=true;
			++cnt;
			dfs(v);
		}
	}
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
			vi[i].clear();
			scanf("%d",sz+i);
			int v;
			for(int j=0;j<sz[i];++j)
			{
				scanf("%d",&v);
				vi[i].push_back(v);
			}
		}
		int key=0,p;
		for(int i=1;i<=n;++i)
		{
			cnt=0;
			memset(flag,0,sizeof(flag));
			flag[i]=true;
			dfs(i);
			if(cnt>key)
			{
				key=cnt;
				p=i;
			}
		}
		printf("%d\n",p);
	}

	return 0;
}
