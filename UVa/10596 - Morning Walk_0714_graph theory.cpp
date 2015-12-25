/*
10596 - Morning Walk

graph theory...
�ǳ�ֱ�۵���ŷ����·����...
Ψһ��tricky���ǵ�����Ϊ0��ʱ��
û�б�,��Ȼ�Ͳ����ܴ��ڻ�·��...
*/

#include<iostream>
#define MAXN 210
using namespace std;

int n,r,degree[MAXN];
bool g[MAXN][MAXN];

void dfs(int u)
{
	degree[u]=0;
	for(int v=0;v<n;++v)
		if(g[u][v] && degree[v])
			dfs(v);
}

bool chk()
{
	for(int i=0;i<n;++i)
		if(degree[i]&1)
			return false;
	for(int i=0;i<n;++i)
		if(degree[i])
		{
			dfs(i);
			for(int j=i;j<n;++j)
				if(degree[j])
					return false;
			break;
		}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&r)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(degree,0,sizeof(degree));
		int u,v;
		for(int i=0;i<r;++i)
		{
			scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=true;
			degree[u]++;
			degree[v]++;
		}
		if(r && chk())
			puts("Possible");
		else
			puts("Not Possible");
	}

	return 0;
}
