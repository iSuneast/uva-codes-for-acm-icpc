/*
11067 - Little Red Riding Hood

dp...
quite a simple dp problem...
but, why am I always getting WA...

finally using memorize search to solve it
dp[i][j]=dp[i][j-1]+dp[i-1][j]
strange...
*/

#include<iostream>
#define MAXN 110
using namespace std;

bool g[MAXN][MAXN];
long long cnt[MAXN][MAXN];

long long dp(int x,int y)
{
	if(cnt[x][y]!=-1)
		return cnt[x][y];
	if(g[x][y])
		return 	cnt[x][y]=0;
	cnt[x][y]=0;
	if(!x && !y)
		return cnt[x][y]=1;
	if(!x)
		return cnt[x][y]=dp(x,y-1);
	if(!y)
		return cnt[x][y]=dp(x-1,y);
	return cnt[x][y]+=dp(x-1,y)+dp(x,y-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int w,h,n;
	while(scanf("%d%d",&w,&h)!=EOF && (w||h))
	{
		scanf("%d",&n);
		int x,y;
		memset(g,0,sizeof(g));
		while(n--)
		{
			scanf("%d%d",&x,&y);
			g[x][y]=true;
		}
		if(g[0][0])
		{
			puts("There is no path.");
			continue;
		}

		memset(cnt,-1,sizeof(cnt));
		cnt[0][0]=1;

		long long key=dp(w,h);

		if(key==-1 || key==0)
			puts("There is no path.");
		else if(key==1)
			puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
		else
			cout<<"There are "<<key<<" paths from Little Red Riding Hood's house to her grandmother's house."<<endl;
	}

	return 0;
}
