/*
925 - No more prerequisites, please!

graph theory...
DAG...
为什么这题是传递闭包?
题目只要求输出最少数量的前驱结点
所以可以直接用dfs搜索出当前结点满足条件的前驱即可
(该前驱,不是当前结点的其它前驱的前驱...)
*/

#include<iostream>
#include<algorithm>
#define MAXN 123
using namespace std;

bool g[MAXN][MAXN],flag[MAXN];
struct DATA
{
	char s[23];
	bool operator<(const DATA &t)const
	{
		return strcmp(s,t.s)<0;
	}
}data[MAXN],buf;
int n,m,t,dis[MAXN];

void dfs(int u)
{
	for(int v=0;v<n;++v)
		if(g[u][v] && dis[v]!=-1)
		{
			if(dis[u]==0)
			{
				dis[v]=1;
				dfs(v);
			}
			else
			{
				dis[v]=-1;
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
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s",data[i].s);
		sort(data,data+n);

		memset(g,0,sizeof(g));
		memset(flag,0,sizeof(flag));
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",buf.s);
			int u=lower_bound(data,data+n,buf)-data;
			flag[u]=true;
			scanf("%d",&t);
			while(t--)
			{
				scanf("%s",buf.s);
				int v=lower_bound(data,data+n,buf)-data;
				g[u][v]=true;
			}
		}

		for(int i=0;i<n;++i)
			if(flag[i])
			{
				memset(dis,0,sizeof(dis));
				dfs(i);
				int cnt=0;
				for(int j=0;j<n;++j)
					if(dis[j]==1)
						++cnt;
				printf("%s %d",data[i].s,cnt);
				for(int j=0;j<n;++j)
					if(dis[j]==1)
						printf(" %s",data[j].s);
				putchar(10);
			}
	}

	return 0;
}
