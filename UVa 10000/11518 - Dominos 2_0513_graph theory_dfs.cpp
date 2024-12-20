/*
11518 - Dominos 2

graph theory...
dfs...
路径覆盖问题...
用邻接表保存节点关系...
直接搜索即可...

注意每个test case要清空数组...
又在这里WA了一次...
*/

#include<iostream>
#include<vector>
#define MAXN 10010
using namespace std;

bool flag[MAXN];
vector<int> vi[MAXN];
int cnt[MAXN],key;

void dfs(int u)
{
	if(flag[u])
		return ;
	flag[u]=true;
	++key;
	for(int i=0;i<cnt[u];++i)
		dfs(vi[u][i]);
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
		int n,m,l,a,b;
		scanf("%d%d%d",&n,&m,&l);
		for(int i=1;i<=n;++i)
		{
			vi[i].clear();
			cnt[i]=0;
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			vi[a].push_back(b);
			++cnt[a];
		}
		key=0;
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=l;++i)
		{
			scanf("%d",&a);
			dfs(a);
		}
		printf("%d\n",key);
	}

	return 0;
}
