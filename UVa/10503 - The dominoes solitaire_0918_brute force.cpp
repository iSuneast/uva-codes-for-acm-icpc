/*
10503 - The dominoes solitaire

brute force...
check whether there is a path from start to end with length=n
we can link (x1,y1)->(x2,y2)
if and only if y1==x2 || y1==x2
use backtracking to solve it
*/

#include<iostream>
#define MAXN 18
using namespace std;

int n,m,pnt[MAXN][2];
bool flag[MAXN],ok;

void dfs(int dep,int pos)
{
	if(ok)
		return ;
	if(dep==n && pos==pnt[1][0])
	{
		ok=true;
		return ;
	}

	for(int i=2;i<m;++i)
	{
		if(flag[i])
			continue;
		for(int j=0;j<2;++j)
			if(pos==pnt[i][j])
			{
				flag[i]=true;
				dfs(dep+1,pnt[i][1-j]);
				flag[i]=false;
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && n)
	{
		m+=2;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&pnt[i][0],&pnt[i][1]);
			flag[i]=false;
		}

		ok=false;
		dfs(0,pnt[0][1]);
		puts(ok?"YES":"NO");
	}

	return 0;
}
