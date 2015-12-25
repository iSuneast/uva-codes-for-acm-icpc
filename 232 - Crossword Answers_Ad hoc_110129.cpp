/*
232 - Crossword Answers

Ad hoc...
应该算是水题了~
下午被各种神题虐的一塌糊涂~
于是便挑了一道水题玩玩...

happy coding~
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 13
using namespace std;

char puzzle[MAXN][MAXN];
int n,m,idx[MAXN][MAXN];
bool across[MAXN][MAXN],down[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	bool first=true;
	int cas=1;
	while(scanf("%d%d",&n,&m)!=EOF && n)
	{
		if(!first)
			putchar(10);
		first=false;

		memset(puzzle,0,sizeof(puzzle));
		memset(across,0,sizeof(across));
		memset(down,0,sizeof(down));
		memset(idx,0,sizeof(idx));

		int id=1;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",puzzle[i]+1);
			for(int j=1;j<=m;++j)
			{
				if( isalpha(puzzle[i][j]) )
				{
					if(  !isalpha(puzzle[i][j-1]) )
						across[i][j]=true;
					if(  !isalpha(puzzle[i-1][j]) )
						down[i][j]=true;
					if(across[i][j] || down[i][j])
						idx[i][j]=id++;
				}
			}
		}

		printf("puzzle #%d:\n",cas++);
		puts("Across");
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(across[i][j])
				{
					printf("%3d.",idx[i][j]);
					int p=j;
					while(isalpha( puzzle[i][p] ))
						putchar(puzzle[i][p++]);
					putchar(10);
				}
			}
		}

		puts("Down");
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(down[i][j])
				{
					printf("%3d.",idx[i][j]);
					int p=i;
					while(isalpha( puzzle[p][j] ))
						putchar(puzzle[p++][j]);
					putchar(10);
				}
			}
		}
	}

	return 0;
}
