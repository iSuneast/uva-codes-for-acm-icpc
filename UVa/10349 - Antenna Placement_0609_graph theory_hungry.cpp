/*
10349 - Antenna Placement

graph theory...
hungry...
ACM生涯的第一道匈牙利...

本题竟然不能贪心...
将相邻的点拿去匹配,则
总的点数=匹配数/2*2+未匹配的点数
总共需要的圈=匹配数+未匹配的点数=总的点数-匹配数/2
*/

#include<iostream>
#define MAXN 50
#define EDGE 450
using namespace std;

char buf[MAXN][MAXN];
bool g[EDGE][EDGE],flag[EDGE];
int match[EDGE],cnt,n,m;

int dfs(int u)
{
	for(int v=0;v<cnt;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;	//标记v
			int t=match[v];	//记录之前与v匹配的值
			match[v]=u;		//将v与u匹配
			if(t==-1 || dfs(t))		//若v未匹配过,匹配成功...或者与v匹配过的值可以和其它点匹配,匹配成功
				return 1;
			match[v]=t;		//匹配失败
		}
	return 0;
}

int hungry()
{
	int key=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<cnt;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key;
}

int hash(int x,int y)
{
	return (x-1)*m+y-1;
}

void add(int x,int y)
{
	int t,s=hash(x,y);
	if(buf[x][y-1]=='*')
	{
		t=hash(x,y-1);
		g[s][t]=true;
	}
	if(buf[x][y+1]=='*')
	{
		t=hash(x,y+1);
		g[s][t]=true;
	}
	if(buf[x-1][y]=='*')
	{
		t=hash(x-1,y);
		g[s][t]=g[t][s]=true;
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
		int tot=0;
		scanf("%d%d",&n,&m);
		cnt=n*m;
		memset(buf,0,sizeof(buf));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",buf[i]+1);
			for(int j=1;j<=m;++j)
				if(buf[i][j]=='*')
				{
					++tot;
					add(i,j);
				}
		}

		printf("%d\n",tot-hungry()/2);
	}

	return 0;
}
