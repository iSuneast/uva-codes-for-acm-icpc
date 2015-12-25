/*
167 - The Sultan's Successors

经典的8皇后问题...
先用dfs遍历图,保存所有状态...
读入图后按状态枚举所有解,取最大值即可..
*/

#include<iostream>
#define MAXN 8
#define MAXSTATE 100
using namespace std;

int g[MAXN+2][MAXN+2],vis[3][(MAXN+2)*(MAXN+2)],c[MAXN+2],state[MAXSTATE][MAXN+2],cnt;

void dfs(int cur)
{
	if(cur>8)
		memcpy(state[cnt++],c,sizeof(c));
	else for(int i=1;i<=MAXN;++i)
		if(!vis[0][i] && !vis[1][i+cur] && !vis[2][MAXN+cur-i])
		{
			c[cur]=i;
			vis[0][i]=vis[1][i+cur]=vis[2][MAXN+cur-i]=1;
			dfs(cur+1);
			vis[0][i]=vis[1][i+cur]=vis[2][MAXN+cur-i]=0;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);

	dfs(1);
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int i,j,key=0,t;
		for(i=1;i<=MAXN;++i)
			for(j=1;j<=MAXN;++j)
				scanf("%d",&g[i][j]);
		for(i=0;i<cnt;++i)
		{
			t=0;
			for(j=1;j<=MAXN;++j)
				t+=g[j][ state[i][j] ];
			key=key>t?key:t;
		}
		printf("%5d\n",key);
	}

	return 0;
}
