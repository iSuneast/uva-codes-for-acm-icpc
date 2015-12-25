/*
11218 - KTV

brute force...
暴力枚举全排列...
不能暴力枚举1-9的全排列再暴力匹配...
会TLE..
*/

#include<iostream>
#define MAXN 86
using namespace std;

bool flag[10];
int comb[MAXN][4],n,key;

void dfs(int cur,int dep)
{
	if(dep==3)
		key=max(key,cur);
	else for(int i=0;i<n;++i)
		if(!flag[ comb[i][0] ] && !flag[ comb[i][1] ] && !flag[ comb[i][2] ])
		{
			flag[ comb[i][0] ]=flag[ comb[i][1] ]=flag[ comb[i][2] ]=true;
			dfs(cur+comb[i][3],dep+1);
			flag[ comb[i][0] ]=flag[ comb[i][1] ]=flag[ comb[i][2] ]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(comb,0,sizeof(comb));
		for(int i=0;i<n;++i)
			scanf("%d%d%d%d",&comb[i][0],&comb[i][1],&comb[i][2],&comb[i][3]);
		key=-1;
		dfs(0,0);
		printf("Case %d: %d\n",cas++,key);
	}

	return 0;
}
