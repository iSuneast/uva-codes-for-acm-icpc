/*
11331 - The Joys of Farming

graph theory...
DP...knapsack...
��ͼ�Ķ���ɫ�����еĵ����Ϊ����...
����knapsack[][2]��������...
(����޷���ͼ����ɫ��ֱ���˳�)

�ñ��������еĽ����һ��...
��������������Ե���b||c���н�,�����޽�.
���ں�һ��״̬������ǰһ��״̬,��knapsack[][]�����ֵ�Ǹ�.
����,��������ö��.

sample
	in
1
3 3 0
	out
yes
�������ǱȽ���������Ӱ�...
*/

#include<iostream>
#define MAXN 2010
using namespace std;

int cnt[MAXN],next[MAXN][MAXN],color[MAXN],b,c,a,key[3],knapsack[MAXN][2];
int dp[MAXN];
bool flag[MAXN];

bool dfs(int u)
{
	flag[u]=true;
	int c=color[u];
	if(!c)
		c=color[u]=1;
	++key[color[u]];
	for(int i=0;i<cnt[u];++i)
	{
		int v=next[u][i];
		if(!flag[v])
		{
			color[v]=(color[u]==1?2:1);
			if(!dfs(v))
				return false;
		}
		else if(color[v]==color[u])
			return false;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("acm.txt","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&b,&c,&a);
		memset(cnt,0,sizeof(cnt));
		int u,v;
		for(int i=0;i<a;++i)
		{
			scanf("%d%d",&u,&v);
			next[u][cnt[u]++]=v;
			next[v][cnt[v]++]=u;
		}
		memset(color,0,sizeof(color));
		memset(flag,0,sizeof(flag));
		bool got=true;
		int p=0;
		for(int i=1;i<=b+c;++i)
			if(!flag[i])
			{
				key[1]=key[2]=0;
				if(!dfs(i))
				{
					got=false;
					break;
				}
				knapsack[p][0]=key[1];
				knapsack[p][1]=key[2];
				++p;
			}
		if(!got)
		{
			puts("no");
			continue;
		}
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<p;++i)
		{
			for(int j=b+c;j>=0;--j)		//��������ö��
				if(dp[j]==i)
				{
					dp[j+knapsack[i][0]]=i+1;
					dp[j+knapsack[i][1]]=i+1;
				}
		}
		if(dp[b]==p || dp[c]==p)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}
