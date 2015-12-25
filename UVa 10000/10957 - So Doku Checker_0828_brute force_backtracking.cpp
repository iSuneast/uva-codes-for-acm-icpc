/*
10957 - So Doku Checker

brute force...
almost the same as UVa 989...
check whether the doku is Illegal...
then try to general the right doku using backtracking...
stop when we have already find 2 solutions...
*/

#include<iostream>
#define MAXN 13
using namespace std;

int doku[MAXN][MAXN];
char key[][MAXN]={"Impossible","Unique","Ambiguous","Illegal"};

bool input()
{
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			if(scanf("%d",&doku[i][j])==EOF)
				return false;
	return true;
}

int got,end=9,n=3;

void dfs(int x,int y)
{
	if(got>1)
		return ;
	if(x==end)
	{
		got++;
		return ;
	}

	if(doku[x][y])
	{
		if(y+1==end)
			dfs(x+1,0);
		else
			dfs(x,y+1);
		return ;
	}

	bool flag[MAXN];
	memset(flag,0,sizeof(flag));

	for(int i=0;i<end;++i)
		flag[ doku[x][i] ]=flag[ doku[i][y] ]=true;
	int sx=x/n*n,sy=y/n*n;
	for(int i=sx;i<sx+n;++i)
		for(int j=sy;j<sy+n;++j)
			flag[ doku[i][j] ]=true;

	for(int i=1;i<=end;++i)
		if(!flag[i])
		{
			flag[i]=true;
			doku[x][y]=i;
			if(y+1==end)
				dfs(x+1,0);
			else
				dfs(x,y+1);
			doku[x][y]=0;
			flag[i]=false;
		}
}

int chk()
{
	bool flag[MAXN];

	for(int i=0;i<end;++i)
	{
		memset(flag,0,sizeof(flag));
		for(int j=0;j<end;++j)
			if(doku[i][j])
			{
				if(!flag[ doku[i][j] ])
					flag[ doku[i][j] ]=true;
				else
					return 3;
			}
	}

	for(int j=0;j<end;++j)
	{
		memset(flag,0,sizeof(flag));
		for(int i=0;i<end;++i)
			if(doku[i][j])
			{
				if(!flag[ doku[i][j] ])
					flag[ doku[i][j] ]=true;
				else
					return 3;
			}
	}

	for(int a=0;a<end;a+=3)
		for(int b=0;b<end;b+=3)
		{
			memset(flag,0,sizeof(flag));
			for(int i=a;i<a+n;++i)
				for(int j=b;j<b+n;++j)
					if(doku[i][j])
					{
						if(!flag[ doku[i][j] ])
							flag[ doku[i][j] ]=true;
						else
							return 3;
					}
		}

	got=0;
	dfs(0,0);
	return got;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(input())
	{
		printf("Case %d: %s.\n",cas++,key[chk()]);
	}

	return 0;
}
