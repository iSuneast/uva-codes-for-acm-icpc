/*
989 - Su Doku

brute force...
backtracking...
直接暴力回溯...
还以为要用什么A*之类的启发式算法...
最近怎么一直想的很多...
*/

#include<iostream>
#define MAXN 9
using namespace std;

int mat[MAXN][MAXN],n,end;
bool got;

void dfs(int x,int y)
{
	if(got)
		return ;
	if(x==end)
	{
		for(int i=0;i<end;++i)
		{
			for(int j=0;j<end;++j)
			{
				if(j)
					putchar(' ');
				printf("%d",mat[i][j]);
			}
			putchar('\n');
		}
		got=true;
		return ;
	}

	if(mat[x][y])
	{
		if(y+1==end)
			dfs(x+1,0);
		else
			dfs(x,y+1);
		return ;
	}

	bool flag[MAXN+3];
	memset(flag,0,sizeof(flag));

	for(int i=0;i<end;++i)
		flag[ mat[x][i] ]=flag[ mat[i][y] ]=true;
	int sx=x/n*n,sy=y/n*n;
	for(int i=sx;i<sx+n;++i)
		for(int j=sy;j<sy+n;++j)
			flag[ mat[i][j] ]=true;

	for(int i=1;i<=end;++i)
		if(!flag[i])
		{
			flag[i]=true;
			mat[x][y]=i;
			if(y+1==end)
				dfs(x+1,0);
			else
				dfs(x,y+1);
			mat[x][y]=0;		//用完记得清空啊...
			flag[i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	bool first=true;
	while(scanf("%d",&n)!=EOF)
	{
		if(!first)
			putchar('\n');
		first=false;

		end=n*n;
		for(int i=0;i<end;++i)
			for(int j=0;j<end;++j)
				scanf("%d",&mat[i][j]);
		got=false;
		dfs(0,0);
		if(!got)
			puts("NO SOLUTION");
	}

	return 0;
}
