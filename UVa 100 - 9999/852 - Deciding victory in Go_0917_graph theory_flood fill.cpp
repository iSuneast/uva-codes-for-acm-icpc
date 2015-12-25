/*
852 - Deciding victory in Go

flood fill...
just a simple flood fill algorithm
*/

#include<iostream>
#define MAXN 13
using namespace std;

char s[MAXN][MAXN];
bool black,white;
int cnt;

void dfs(int x,int y)
{
	if(s[x][y]!='.')
	{
		if(s[x][y]=='X')
			black=true;
		else if(s[x][y]=='O')
			white=true;
		return ;
	}
	++cnt;
	s[x][y]=0;

	dfs(x+1,y);	dfs(x-1,y);
	dfs(x,y+1);	dfs(x,y-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		for(int i=1;i<=9;++i)
		{
			scanf("%s",s[i]+1);
		}
		int blackN=0,whiteN=0;
		for(int i=1;i<=9;++i)
		{
			for(int j=1;j<=9;++j)
				if(s[i][j]=='.')
				{
					black=white=false;
					cnt=0;
					dfs(i,j);
					if(black && white)
						continue;
					if(black)
						blackN+=cnt;
					else
						whiteN+=cnt;
				}
				else if(s[i][j]=='X')
					++blackN;
				else if(s[i][j]=='O')
					++whiteN;
		}

		printf("Black %d White %d\n",blackN,whiteN);
	}

	return 0;
}
