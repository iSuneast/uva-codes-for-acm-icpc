/*
662 - Fast Food

dp...
�ź�����֮ǰ��һֱû�п������������ô��...
ע�⵽[i,i]�������Ҫ��һ��depot�Ļ�һ����(i+j)/2,{��λ��}
��dis[i][j]Ϊ[i,j]����һ��depot�ľ���
���Եõ�dis[i][j]=dis[i][j-1]+d[j]-d[m]
	����m=(i+j)/2

��dp[i][k]Ϊ��[1,i]����k��depot�ľ���
�ɵ�	dp[i][1]=dis[1][i]
	dp[i][k]=min(dp[j][k-1]+dis[j+1][i])
ֻ��Ҫ��״̬ת�Ƶ�ʱ���¼���ڵ���Ϣ
Ȼ��ݹ������������..
*/

#include<iostream>
#define MAXN 210
#define MAXK 35
#define INF 0x3f3f3f3f
using namespace std;

int n,depot;
int dis[MAXN][MAXN],dp[MAXN][MAXK],d[MAXN];
int fa[MAXN][MAXK];

void dfs(int s,int k)
{
	if(!k)
		return ;
	dfs(fa[s][k],k-1);
	if(fa[s][k]+1==s)
		printf("Depot %d at restaurant %d serves restaurant %d\n",
			k,s,s);
	else
		printf("Depot %d at restaurant %d serves restaurants %d to %d\n",
			k,(fa[s][k]+1+s)/2,fa[s][k]+1,s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d%d",&n,&depot)!=EOF && (n||depot))
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&d[i]);

		memset(dis,0,sizeof(dis));
		for(int k=1;k<=n;++k)
			for(int i=1;i+k<=n;++i)
			{
				int j=i+k,m=(i+j)/2;
				dis[i][j]=dis[i][j-1]+d[j]-d[m];
			}

		memset(dp,0x3f,sizeof(dp));
		memset(fa,-1,sizeof(fa));
		for(int i=1;i<=n;++i)
		{
			dp[i][1]=dis[1][i];
			fa[i][1]=0;
		}

		for(int k=2;k<=depot;++k)
		{
			dp[k][k]=0;
			fa[k][k]=k-1;
			for(int i=k+1;i<=n;++i)
				for(int j=k-1;j<i;++j)
					if(dp[i][k]>dp[j][k-1]+dis[j+1][i])
					{
						dp[i][k]=dp[j][k-1]+dis[j+1][i];
						fa[i][k]=j;
					}
		}

		printf("Chain %d\n",cas++);
		dfs(n,depot);
		printf("Total distance sum = %d\n\n",dp[n][depot]);
	}

	return 0;
}
