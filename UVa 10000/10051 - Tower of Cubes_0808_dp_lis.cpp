/*
10051 - Tower of Cubes

dp...
lis..
直接O(n^2*6^2)的lis,
对每个旋转进行匹配...
记录下father指针
dfs输出即可
*/

#include<iostream>
#define MAXN 503
#define SZ 6
using namespace std;

struct POINT{int x,y,p;}fa[MAXN][6];
int cube[MAXN][6],dp[MAXN][6],n;
const char key[10][10]={"front","back","left","right","top","bottom"};

void input()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<SZ;++j)
			scanf("%d",&cube[i][j]);
}

void output(int x,int y)
{
	if(x==-1 || y==-1)
		return ;
	output(fa[x][y].x,fa[x][y].y);
	printf("%d %s\n",fa[x][y].p,key[y]);
}

void lis()
{
	int _max=0,x,y;

	for(int i=0;i<n;++i)
		for(int j=0;j<SZ;++j)
		{
			dp[i][j]=1;	fa[i][j].x=-1,fa[i][j].y=-1;fa[i][j].p=i+1;

			for(int k=0;k<i;++k)
				for(int a=0;a<SZ;++a)
					if(cube[k][a]==cube[i][j] && dp[k][a^1]+1>dp[i][j])
					{
						dp[i][j]=dp[k][a^1]+1;
						fa[i][j].x=k,fa[i][j].y=a^1;
					}

			if(dp[i][j]>_max)
			{
				_max=dp[i][j];
				x=i,y=j;
			}
		}

	printf("%d\n",_max);
	output(x,y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(cas!=1)
			putchar(10);

		input();
		printf("Case #%d\n",cas++);
		lis();
	}

	return 0;
}
