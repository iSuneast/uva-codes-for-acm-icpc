/*
10505 - Montesco vs Capuleto

graph theory...
b_color...
���ǲ��鼯����Ŀ...
�����ö���ɫ����,
���Ƕ���ɫ�����ÿ����ͨ�ķ�֧
�Բ�ͬ����ͨ��֧,Ӧ�÷ֿ�����...
�������ĳ����ͨ��֧�޽�������������ͨ��֧�����е�
�����ٷ���
*/

#include<iostream>
#define MAXN 210
using namespace std;

int n,flag[MAXN];
bool g[MAXN][MAXN];

bool dfs(int u)
{
	for(int v=1;v<=n;++v)
		if(g[u][v])
		{	
			if(!flag[v])
			{
				flag[v]=-flag[u];
				if(!dfs(v))
					return false;
			}
			else if(flag[v]==flag[u])
				return false;
		}
	return true;
}

bool vis[MAXN];

void dfs_vis(int u)
{
	vis[u]=true;
	for(int v=1;v<=n;++v)
		if(g[u][v] && !vis[v]) 
			dfs_vis(v);
}

int b_color()
{
	int i,j,d=1,key=0;
	memset(flag,0,sizeof(flag));
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			flag[i]=d;
			if(dfs(i))
			{
				int a=0,b=0;
				for(j=1;j<=n;++j)
					if(!vis[j])
					{
						if(flag[j]==d)
							++a;
						else if(flag[j]==-d)
							++b;
					}
					++d;
					key+=max(a,b);
			}
			dfs_vis(i);
		}

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,cnt,i,j;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		for(i=1;i<=n;++i)
		{
			scanf("%d",&cnt);
			while(cnt--)
			{
				scanf("%d",&j);
				g[i][j]=g[j][i]=true;
			}
		}
		
		printf("%d\n",b_color());
	}

	return 0;
}
