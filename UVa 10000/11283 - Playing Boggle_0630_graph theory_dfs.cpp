/*
11283 - Playing Boggle

graph theory...
dfs...
简单的搜索题...
dfs一下就可以了...
*/

#include<iostream>
#define MAXN 6
using namespace std;

char boggle[MAXN][MAXN],s[MAXN*MAXN];
bool got,flag[MAXN][MAXN];
const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

int goal(int l)
{
	if(l<=4)
		return 1;
	else if(l==5)
		return 2;
	else if(l==6)
		return 3;
	else if(l==7)
		return 5;
	else
		return 11;
}

void dfs(int x,int y,int dep)
{
	if(got)
		return ;
	else if(!s[dep])
	{
		got=true;
		return ;
	}
	for(int d=0;d<8 && !got;++d)
	{
		int tx=x+dx[d],ty=y+dy[d];
		if(!flag[tx][ty] && boggle[tx][ty]==s[dep])
		{
			flag[tx][ty]=true;
			dfs(tx,ty,dep+1);
			flag[tx][ty]=false;
		}
	}
}

int score()
{
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			if(boggle[i][j]==s[0])
			{
				got=false;
				memset(flag,0,sizeof(flag));
				flag[i][j]=true;	//之前忘记标记了...wa了好多次...
				dfs(i,j,1);
				if(got)
					return goal(strlen(s));
			}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		memset(boggle,0,sizeof(boggle));
		for(int i=1;i<=4;++i)
			scanf("%s",boggle[i]+1);

		int m,key=0;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",s);
			key+=score();
		}
		printf("Score for Boggle game #%d: %d\n",cas,key);
	}

	return 0;
}
