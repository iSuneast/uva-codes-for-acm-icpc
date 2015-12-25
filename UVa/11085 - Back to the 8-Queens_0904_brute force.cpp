/*
11085 - Back to the 8-Queens

brute force...
general all possible list of 8-Queens
and then match the current state with final state
	the 8 - max-match is the answer
*/

#include<iostream>
#define MAXN 103
using namespace std;
const int boardSize=8;

int key[MAXN][boardSize],cur[boardSize];
int cnt;
bool flagY[boardSize],flagDiagonal[boardSize*3],flagClino[boardSize*3];

bool input()
{
	for(int i=0;i<boardSize;++i)
		if(scanf("%d",&cur[i])==EOF)
			return false;
	return true;
}

void dfs(int depth)
{
	if(depth==boardSize)
		memcpy(key[cnt++],cur,sizeof(cur));
	else for(int i=0;i<boardSize;++i)
		if(!flagY[i] && !flagDiagonal[i+depth] && 
			!flagClino[boardSize+depth-i])
		{
			cur[depth]=i+1;
			flagY[i]=flagDiagonal[i+depth]=flagClino[boardSize+depth-i]=true;
			dfs(depth+1);
			flagY[i]=flagDiagonal[i+depth]=flagClino[boardSize+depth-i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	cnt=0;
	memset(flagY,0,sizeof(flagY));
	memset(flagDiagonal,0,sizeof(flagDiagonal));
	memset(flagClino,0,sizeof(flagClino));

	dfs(0);

	int cas=1;
	while(input())
	{
		int ans=boardSize;

		for(int i=0;i<cnt;++i)
		{
			int tmp=boardSize;

			for(int j=0;j<boardSize;++j)
				if(key[i][j]==cur[j])
					--tmp;
			ans=min(ans,tmp);
		}
		printf("Case %d: %d\n",cas++,ans);
	}

	return 0;
}
